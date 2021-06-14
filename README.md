# Sockets-in-C

Program to create a TCP-based connection by creating Client/Server sockets using [Winsock](https://docs.microsoft.com/en-us/windows/win32/winsock/winsock-reference "Winsock").  
The program uses the client socket to take user input and sends it to the server socket. Once the buffer has been successfully transferred to the server socket, the server socket simply prints the buffer sent by the client socket, indicating that the connection was indeed successful.


# How To Use
_____________

- Run the server socket. Error handling has been implemented in the code itself; any errors will result in an error code being displayed on the console. A list of error codes and their corresponding errors is given [here](https://docs.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2 "Winsock Error Codes")  
- After the server socket has been successfully initialized, your console should look like this:
![image](https://user-images.githubusercontent.com/66318555/121880264-6cf1b600-cd2b-11eb-9cb0-6ed3aa50c7f2.png)

- Once this has been acheived, run the client socket code. Not running the server socket code first will result in the following error:

     ![image](https://user-images.githubusercontent.com/66318555/121880563-c823a880-cd2b-11eb-9774-1cc9edf66218.png)
   
- Once the steps are followed, assuming no error has occurred, your client socket console should look like this:
![image](https://user-images.githubusercontent.com/66318555/121880912-30728a00-cd2c-11eb-8e57-adf967a0b813.png)

- Simultaneously, your server socket console should look like this:
![image](https://user-images.githubusercontent.com/66318555/121880996-497b3b00-cd2c-11eb-9397-fed8d5244cb6.png)

# Some info about the configuration of the sockets
________________
- Both, the client and the server sockets have a family of `AF_INET` corresponding to the IPv4 protocol. 
- The connection uses `SOCK_STREAM` type of socket, basically a TCP socket as opposed to a `SOCK_DGRAM` type of socket or a UDP socket. Read more about their difference between them [here](https://stackoverflow.com/questions/4688855/whats-the-difference-between-streams-and-datagrams-in-network-programming "SOCK STREAM vs DATAGRAM")
- The IP address parameter of the server socket to bind to is set as `INADDR_ANY` which means that the server socket will listen for connections at all available addresses as opposed to a single specific IP address. Read more about it [here](https://stackoverflow.com/questions/16508685/understanding-inaddr-any-for-socket-programming#:~:text=INADDR_ANY%20is%20a%20constant%2C%20that,("192.168.78.2") "Meaning of INADDR_ANY")
- The current port defined can be changed to any value, however, this change of port address has to be changed in both the files i.e. `server_socket.cpp` and `client_socket.cpp`. 

