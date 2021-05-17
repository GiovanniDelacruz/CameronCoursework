//this is the function for tcpserv that will
//enable the server to receive and send 
//messages to tcpcli. 
#include	"myunp.h"	//import libraries

void str_echo(int sockfd)
{
	ssize_t		n;	//status of client message
	char		buf[MAXLINE];	//receive buffer
	char		buf2[MAXLINE];	//send buffer
again:
	//check that the client is sending information
	//at the same time get the message if there is one
	while((n= read(sockfd, buf, MAXLINE))>0){
		printf("\nClient: ");	//print client prompt
		fputs(buf,stdout);	//print out client message
		printf("\n>> ");	//print prompt
		fgets(buf2, MAXLINE, stdin);//allow server to make message
		write(sockfd, buf2, strlen(buf2));//send message
		memset(&buf, 0, sizeof(buf));	//clear buffer
		memset(&buf2, 0, sizeof(buf2));	//clear buffer
		
}
	if (n < 0 && errno == EINTR)	//if there is a problem at read but it was caused by interrupt
		goto again;
	else if (n < 0)	//if there is a problem reading, exit
	{
		printf("str_echo: read error");
		exit(1);
	}
}
