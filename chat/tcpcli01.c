//Program: tcpcli01.c
//
//Programmer:	Giovanni Delacruz
//Instructor:	Dr. Zhao
//Date:		11/1/20
//Compile:	make cli
//Run:		./cli <ip address of server>
//
//Purpose:	This program is meant to be used in tandem with the server function
//		When ran, it will start a conversation with the server as long as the 
//		Server was ran first. Only one message can be sent at a time. 
//------------------------------------------------------------------------------------
#include	"myunp.h"	//import library and talk function
#include	"str_cli.c"
int main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;

	if (argc != 2)		//tell users input an ip address of the server if they did not
	{
		printf("usage: tcpcli <IPaddress>");
		exit(1);	//exit the program so they can restart
	}
	//create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	//establish connection to server
	connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
	//once connection is estblished, call chat function
	printf("Type a massage and press enter to begin conversation with the Server.\n>> ");
	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
