#include<stdio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#include<iostream>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")

void displaybuffer(char* buffer)
{
	while (*buffer != '\0')
	{
		printf("%c", *buffer);
		buffer += 1;
	}

	printf("\n");
}

int main()
{
	WSADATA wsadata;

	printf("\nInitializing Winsock...");

	if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0)
	{
		printf("\n\nError Initializing Winsock:%d", WSAGetLastError());
		return -1;
	}

	printf("\n\nWinsock Initialized");

	printf("\n\nCreating Client Socket...");

	SOCKET client_socket = INVALID_SOCKET;

	if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Error creaging client socket:%d", WSAGetLastError());
		return -1;
	}

	printf("\n\nClient socket created sucessfully");


	sockaddr_in client_adrr;
	client_adrr.sin_family = AF_INET;
	client_adrr.sin_port = htons(6969);
	client_adrr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	printf("\n\nAttempting Connection...");

	if (connect(client_socket, (sockaddr*)&client_adrr, sizeof(client_adrr)) != 0)
	{
		printf("\n\nError making connection:%d", WSAGetLastError());
		return -1;
	}

	printf("\n\nConnection Successful");

	char sendbuffer[256];
	char recvbuffer[256];

	while (true)
	{
		cin >> sendbuffer;
		send(client_socket, sendbuffer, 256, 0);
	}


}