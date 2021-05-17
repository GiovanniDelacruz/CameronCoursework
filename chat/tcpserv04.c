//Program: tcpserv04.c
//
//Programmer:   Giovanni Delacruz
//Instructor:   Dr. Zhao
//Date:         11/1/20
//Compile:      make serv
//Run:          ./serv
//
//Purpose:      This program will create a server that will spawn a child to handle
//              user requests. When a client reaches out, the message will be displayed
//              Then the server will be allowed to reply back.
//------------------------------------------------------------------------------------

#include	"myunp.h"	//import libraries and server chat function
#include 	"str_echo.c"
void sig_child(int signo)	//child function
{
	pid_t pid;		//child id
	int stat;		//status
	pid = wait(&stat);
	printf("\nChild %d terminated\n", pid);
	return;
}
	
int main(int argc, char **argv)
{
	int	listenfd, connfd;	//listen and connection values
	pid_t	childpid;		//child pid
	socklen_t	clilen;		//client/socket length
	struct sockaddr_in	cliaddr, servaddr;	//addresses
	void sig_child(int);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);	//create a listening socket

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	bind(listenfd, (SA *) &servaddr, sizeof(servaddr));	//bind the server

	listen(listenfd, LISTENQ);				//set up listening state

	signal(SIGCHLD, sig_child);	/* must call waitpid() */

	for ( ; ; ) {			//service loop 
		clilen = sizeof(cliaddr);	//check for connection
		if ( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0) {
			if (errno == EINTR)	//if interrrupt occurs, loop
				continue;		/* back to for() */
			else{			//if connection error, exit
				printf("accept error\n");
				exit(1);
			}
		}
		//fork, handle client request using child server
		if ( (childpid = fork()) == 0) {	/* child process */
			close(listenfd);		/* close listening socket */
			str_echo(connfd);	/* process the request */
			exit(0);
		}
		close(connfd);			/* parent closes connected socket */
	}
}
