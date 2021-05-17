//This is the header file that contains all the libraries needed
//to run the client/server and establish connections between them
#include <string.h>  //bzero function
#include <sys/socket.h> //basic socket functions
#include <netinet/in.h> //basic definations for sockect structure,socket options
#include <ctype.h> // data types
#include <stdlib.h> //standard library functions
#include <stdio.h> // standard i/o functions
#include <signal.h> //signal function
#include <errno.h> //errno
#define SERV_PORT 9877
#define MAXLINE 4096
#define SA struct sockaddr
#define LISTENQ 1024
