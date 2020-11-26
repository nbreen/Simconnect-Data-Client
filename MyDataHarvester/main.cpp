#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include "MyDataHarvester.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib,"ws2_32")

#define PORT "5000"
#define BUFF_LEN 512


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

	iResult = getaddrinfo("apollo", PORT, &hints, &result);
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

void initHarvester() {
	//MyDataHarvester harvester = new MyDataHarvester();
}

int main() {
	initHarvester();
	SOCKET clientSocket = initSocket();

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

	do {
		iResult = recv(clientSocket, recvbuf, BUFF_LEN, 0);
		if (iResult > 0) {
			printf("Received %d bytes\n", iResult);
			printf("From server: %s", recvbuf);
		}
	} while (iResult > 0);



	return 0;
}