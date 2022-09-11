
#include "MyDataHarvester.h"

#define PORT "5000"
#define ADDRESS "localhost"

bool connectedToSim = false;

SOCKET initSocket() {
	struct addrinfo *result = NULL, 
					*ptr = NULL,
					hints;
	WSADATA wsaData;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Initialize Winsock
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed: %d\n", iResult);
		return 1;
	}

	iResult = getaddrinfo(ADDRESS, PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed!\n");
		WSACleanup();
		return 1;
	}

	SOCKET clientSocket = INVALID_SOCKET;

	ptr = result;

	clientSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	if (clientSocket == INVALID_SOCKET) {
		printf("Error getting socket\n");
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	iResult = connect(clientSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(clientSocket);
		clientSocket = INVALID_SOCKET;
	}

	freeaddrinfo(result);

	if (clientSocket == INVALID_SOCKET) {
		printf("Unable to connect to server\n");
		WSACleanup();
		return 1;
	} else {
		return clientSocket;
	}
}
int main() {
	SOCKET clientSocket = initSocket();
	HANDLE harvesterHandle;
	DWORD threadID;

	if (clientSocket == 1) {
		printf("Unable to create socket\n");
		return 1;
	}

	connectedToSim = ConnectToSim(clientSocket);

	if (!connectedToSim) {
		printf("Unable to connect to sim\n");
		return 1;
	}

	harvesterHandle = CreateThread(NULL, 0, simConnectDispatch, NULL, 0, &threadID);

	const char* sendbuf = "Hello world!";
	char recvbuf[BUFF_LEN];
	int iResult;

	iResult = send(clientSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		printf("Send failed\n");
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}

	WaitForSingleObject(harvesterHandle, INFINITE);

	return 0;
}