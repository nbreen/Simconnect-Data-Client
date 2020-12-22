// MyDataHarvester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <MyDataHarvester.h>
#include "simconnectData.pb.h"


HANDLE simSession;
SOCKET clientSocket;

DWORD WINAPI createProto(LPVOID lParam) {
    ObjectData* toConvert = (ObjectData*)lParam;
    simConnect::simData convertedData;
    std::string toStr(toConvert->szTitle);
    /* Fill in the proto object from our simconnect object */
    convertedData.set_sztitle(toStr);
    convertedData.set_dabsolutetime(toConvert->dAbsoluteTime);
    convertedData.set_dtime(toConvert->dTime);
    convertedData.set_usimonground(toConvert->uSimOnGround);
    convertedData.set_daltitude(toConvert->dAltitude);
    convertedData.set_dheading(toConvert->dHeading);
    convertedData.set_dspeed(toConvert->dSpeed);
    convertedData.set_dverticalspeed(toConvert->dVerticalSpeed);
    convertedData.set_dgpseta(toConvert->dGpsEta);
    convertedData.set_dlatitude(toConvert->dLatitude);
    convertedData.set_dlongitude(toConvert->dLongitude);
    convertedData.set_dsimtime(toConvert->dSimTime);
    convertedData.set_dtemperature(toConvert->dTemperature);
    convertedData.set_dairpressure(toConvert->dPressure);
    convertedData.set_dwindvelocity(toConvert->dWindVelocity);
    convertedData.set_dwinddirection(toConvert->dWindDirection);

    printf("Size after serializing is %ld\n", convertedData.ByteSizeLong());
    /* Add HDR_SZ to pktSize since we're using MSG_PEEK to get the size of the packet */
    long pktSize = convertedData.ByteSizeLong() + HDR_SZ;
    /* Create a new packet */
    char* pkt = new char[pktSize];
    /* Create the new output stream to place in our pkt */
    google::protobuf::io::ArrayOutputStream aos(pkt, pktSize);
    google::protobuf::io::CodedOutputStream* coded_pkt = new google::protobuf::io::CodedOutputStream(&aos);
    /* Write the header to the start of the packet*/
    coded_pkt->WriteVarint64(convertedData.ByteSizeLong());
    /* Write the data behind the header */
    convertedData.SerializeToCodedStream(coded_pkt);
    /* Send our created packet with the header */
    int iResult = send(clientSocket, pkt, pktSize, 0);
    /* Show how many bytes we sent */
    printf("Sent bytes %d\n", iResult);
    return 0;
}

void CALLBACK MyDispatchProc(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext) {
    HRESULT hr;

    switch (pData->dwID) {
        
        case SIMCONNECT_RECV_ID_OPEN: {
            SIMCONNECT_RECV_OPEN* pOpen = (SIMCONNECT_RECV_OPEN*)pData;

            printf("Open: AppName=\"%s\"  AppVersion=%d.%d.%d.%d  SimConnectVersion=%d.%d.%d.%d\n", pOpen->szApplicationName,
                pOpen->dwApplicationVersionMajor, pOpen->dwApplicationVersionMinor, pOpen->dwApplicationBuildMajor, pOpen->dwApplicationBuildMinor,
                pOpen->dwSimConnectVersionMajor, pOpen->dwSimConnectVersionMinor, pOpen->dwSimConnectBuildMajor, pOpen->dwSimConnectBuildMinor
            );

            break;
        }

        case SIMCONNECT_RECV_ID_EVENT: {
            SIMCONNECT_RECV_EVENT* event = (SIMCONNECT_RECV_EVENT*)pData;

            switch(event->uEventID) {
                case START_CLIENT_APPLICATION: {
                    std::cout << "Received start event\n";
                    std::string * disptext = new std::string("Beggining log");
                    std::string disp = *disptext;

                    hr = SimConnect_RequestDataOnSimObject(simSession, USER_OBJECT_DATA, USER_OBJECT_DEF, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SECOND);
                    if (hr != S_OK) {
                        std::cout << "An error occured starting data request\n";
                    }


                    hr = SimConnect_Text(simSession, SIMCONNECT_TEXT_TYPE_PRINT_WHITE, 5, DISPLAYING_TEXT, sizeof(disp), (void*) disptext);
                    if (hr != S_OK) {
                        std::cout << "An error occured displaying text\n";
                    }

                    hr = SimConnect_MenuDeleteItem(simSession, START_CLIENT_APPLICATION);
                    if (hr != S_OK) {
                        std::cout << "An error occured deleting start from menu\n";
                    }
                    
                    hr = SimConnect_MenuAddItem(simSession, "Stop client application", STOP_CLIENT_APPLICATION, 0);
                    if (hr != S_OK) {
                        std::cout << "An error occured changing to stop in menu\n";
                    }

                    break;

                }

                case STOP_CLIENT_APPLICATION: {
                    std::cout << "Received stop event\n";
                    std::string* disptext = new std::string("Stopping log");
                    std::string disp = *disptext;

                    hr = SimConnect_RequestDataOnSimObject(simSession, USER_OBJECT_DATA, USER_OBJECT_DEF, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_NEVER);
                    if (hr != S_OK) {
                        std::cout << "An error occured ending data request\n";
                    }


                    hr = SimConnect_Text(simSession, SIMCONNECT_TEXT_TYPE_PRINT_WHITE, 5, DISPLAYING_TEXT, sizeof(disp), (void*) disptext);
                    if (hr != S_OK) {
                        std::cout << "An error occured displaying text\n";
                    }

                    hr = SimConnect_MenuDeleteItem(simSession, STOP_CLIENT_APPLICATION);
                    if (hr != S_OK) {
                        std::cout << "An error occured deleting stop in menu\n";
                    }

                    hr = SimConnect_MenuAddItem(simSession, "Start client application", START_CLIENT_APPLICATION, 0);
                    if (hr != S_OK) {
                        std::cout << "An error occured changing to start in menu\n";
                    }

                    break;

                }

                case DISPLAYING_TEXT: {
                    std::cout << "Display text success\n";
                    break;
                }
            }
            break;
        }

        case SIMCONNECT_RECV_ID_SIMOBJECT_DATA: {
            SIMCONNECT_RECV_SIMOBJECT_DATA* simObjectData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
            std::cout << "Received obj data\n";

            switch (simObjectData->dwRequestID) {
                case USER_OBJECT_DATA: {
                    DWORD dwObjectID = simObjectData->dwObjectID;

                    ObjectData* userData = (ObjectData*)&simObjectData->dwData;

                    int hours = static_cast<int>(userData->dTime / 3600);
                    int minutes = static_cast<int>(userData->dTime / 60);
                    int seconds = static_cast<int>(fmod(userData->dTime, 60));
                    char sendbuff[BUFF_LEN];
                    HANDLE protoHandle;
                    DWORD threadID;

                    protoHandle = CreateThread(NULL, 0, createProto, (LPVOID)userData, 0, &threadID);
                    std::cout << "Data timestamp: " << static_cast<int>(userData->dTime / 3600) + 00 << ":" << static_cast<int>(userData->dTime / 60  - 60) + 00 << ":" << static_cast<int>(fmod(userData->dTime, 60)) + 00 << "\n";
                    break;
                }
            }

            break;
        }

        case SIMCONNECT_RECV_ID_QUIT: {
            hr = SimConnect_Close(simSession);
            if (hr != S_OK) {
                std::cout << "Error closing simconnect session\n";
            }

            exit(0);
        }

        default: {
            printf("Received: %d\n", pData->dwID);
            break;
        }
    }
}

void initLogger() {
    HRESULT hr;

    hr = SimConnect_MenuAddItem(simSession, "Start client application", START_CLIENT_APPLICATION, 0);

    if (hr != S_OK) {
        std::cout << "An error occured adding origin start to menu\n";
    }

    for (unsigned int i = 0; i < ARRAYSIZE(g_aVariables); ++i) {
        const PropertyDefinition& prop = g_aVariables[i];
        hr = SimConnect_AddToDataDefinition(simSession, USER_OBJECT_DEF, prop.pszName, prop.pszUnits, prop.eDataType);
        if (hr != S_OK) {
            std::cout << "Error with data definition\n";
        }
    }

}

DWORD WINAPI simConnectDispatch(LPVOID lpParam) {
    while (1) {
        SimConnect_CallDispatch(simSession, MyDispatchProc, NULL);
        Sleep(1);
    }

    return 0;
}

bool ConnectToSim(SOCKET sock) {
    HRESULT hr;
    bool connected = false;

    std::cout << "Attempting to connect to P3d.....\n";

    for (int i = 0; i < 6; i++) {
        hr = SimConnect_Open(&simSession, "My Data Harvester", NULL, 0, 0, 0);
        if (hr == S_OK) {
            connected = true;
            break;
        }
        std::cout << "Connection Attempt " << i + 1 << "\n";
        Sleep(30);
    }

    if (connected) {
        std::cout << "P3D connection successful. Initializing logger\n";
        initLogger();
        clientSocket = sock;
        return true;
   
    } else {
        std::cout << "Connection timeout\n";
        return false;
    }
}

/*int main() {
    ConnectToSim();
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
