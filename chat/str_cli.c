//This is the function for tcpcli that will 
//enable the program to receive messages from 
//tcpserv and send messages to them
#include	"myunp.h"	//import library

void str_cli(FILE *fp, int sockfd)
{
	//generate send buffer and receive buffer
	char	sendline[MAXLINE], recvline[MAXLINE];
	
	//while the client is still able to send messages
	//fp will be implemented as keyboard
	while (fgets(sendline, MAXLINE, fp) != NULL) {
		//send the keyboard input to the server
		write(sockfd, sendline, strlen(sendline));
		//print server prompt
		printf("\nServer: ");
		//exit if there is an error getting message from server
		//at the same time get the message
		if (read(sockfd, recvline, MAXLINE) == 0)
		{
			printf("str_cli: server terminated prematurely");
			exit(1);
		}
		//print the message received
		fputs(recvline, stdout);
		//print prompt
		printf("\n>> ");
		//clear buffers
		memset(&sendline, 0, sizeof(sendline));
		memset(&recvline, 0, sizeof(recvline));
	}
}
