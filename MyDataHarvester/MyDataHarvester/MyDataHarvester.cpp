// MyDataHarvester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <MyDataHarvester.h>
#include "simconnectData.pb.h"


HANDLE simSession;
FILE* dataOut;
SOCKET clientSocket;

void logData(ObjectData* toLog, FILE* file) {
    fprintf(file,"%s", toLog->szTitle);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dAbsoluteTime);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dTime);
    fprintf(file, " ");
    fprintf(file, "%d", toLog->uDayOfTheYear);
    fprintf(file, " ");
    fprintf(file, "%d", toLog->uYear);
    fprintf(file, " ");
    fprintf(file, "%d", toLog->uMonthOfTheYear);
    fprintf(file, " ");
    fprintf(file, "%d", toLog->uDayOfTheMonth);
    fprintf(file, " ");
    fprintf(file, "%d", toLog->uDayOfTheWeek);
    fprintf(file, " ");
    fprintf(file, "%d", toLog->uTimeZoneOffset);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dSimTime);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dLatitude);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dLongitude);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dAltitude);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dPitch);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dBank);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dHeading);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dVelocityX);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dVelocityY);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dVelocityZ);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dTemperature);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dAirPressure);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dAirDensity);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dWindVelocity);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dWindDirection);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dWindX);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dWindY);
    fprintf(file, " ");
    fprintf(file, "%f", toLog->dWindZ);
    fprintf(file, "\n");
}

DWORD WINAPI createProto(LPVOID lParam) {
    ObjectData* toConvert = (ObjectData*)lParam;

    simConnect::simData convertedData;
    std::string toStr(toConvert->szTitle);

    convertedData.set_sztitle(toStr);
    convertedData.set_dabsolutetime(toConvert->dAbsoluteTime);
    convertedData.set_dtime(toConvert->dTime);
    convertedData.set_udayoftheyear(toConvert->uDayOfTheYear);
    convertedData.set_uyear(toConvert->uYear);
    convertedData.set_umonthoftheyear(toConvert->uMonthOfTheYear);
    convertedData.set_udayofthemonth(toConvert->uDayOfTheMonth);
    convertedData.set_udayoftheweek(toConvert->uDayOfTheWeek);
    convertedData.set_utimezoneoffset(toConvert->uTimeZoneOffset);
    convertedData.set_dsimtime(toConvert->dSimTime);
    convertedData.set_dlatitude(toConvert->dLatitude);
    convertedData.set_dlongitude(toConvert->dLongitude);
    convertedData.set_daltitude(toConvert->dAltitude);
    convertedData.set_dpitch(toConvert->dPitch);
    convertedData.set_dbank(toConvert->dBank);
    convertedData.set_dheading(toConvert->dHeading);
    convertedData.set_dvelocityx(toConvert->dVelocityX);
    convertedData.set_dvelocityy(toConvert->dVelocityY);
    convertedData.set_dvelocityz(toConvert->dVelocityZ);
    convertedData.set_dtemperature(toConvert->dTemperature);
    convertedData.set_dairpressure(toConvert->dAirPressure);
    convertedData.set_dairdensity(toConvert->dAirDensity);
    convertedData.set_dwindvelocity(toConvert->dWindVelocity);
    convertedData.set_dwinddirection(toConvert->dWindDirection);
    convertedData.set_dwindx(toConvert->dWindX);
    convertedData.set_dwindy(toConvert->dWindY);
    convertedData.set_dwindz(toConvert->dWindZ);

    printf("Size after serializing is %ld\n", convertedData.ByteSizeLong());
    long pktSize = convertedData.ByteSizeLong();
    char* pkt = new char[pktSize];
    google::protobuf::io::ArrayOutputStream aos(pkt, pktSize);
    google::protobuf::io::CodedOutputStream* coded_pkt = new google::protobuf::io::CodedOutputStream(&aos);
    coded_pkt->WriteVarint32(convertedData.ByteSizeLong());
    convertedData.SerializeToCodedStream(coded_pkt);

    int iResult = send(clientSocket, pkt, pktSize, 0);
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
                    fopen_s(&dataOut, "data.txt", "w");

                    if (!dataOut) {
                        std::cout << "Error opening out file\n";
                    }

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
              
                    /*sprintf_s(sendbuff, "Data timestamp: %d:%d:%d\n", hours, minutes, seconds);
                    int iResult = send(clientSocket, sendbuff, (int)strlen(sendbuff), 0);*/

                    std::cout << "Data timestamp: " << static_cast<int>(userData->dTime / 3600) + 00 << ":" << static_cast<int>(userData->dTime / 60  - 60) + 00 << ":" << static_cast<int>(fmod(userData->dTime, 60)) + 00 << "\n";
                    //std::cout << "Send result to server: " << iResult << "\n";
                    //logData(userData, dataOut);
                    
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
            
            if (dataOut) {
                fclose(dataOut);
                dataOut = NULL;
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
