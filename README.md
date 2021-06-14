# Sockets-in-C

Program to create a TCP-based connection by creating Client/Server sockets using [Winsock](https://docs.microsoft.com/en-us/windows/win32/winsock/winsock-reference "Winsock").  
The program uses the client socket to take user input and sends it to the server socket. Once the buffer has been successfully transferred to the server socket, the server socket simply prints the buffer sent by the client socket, indicating that the connection was indeed successful.
