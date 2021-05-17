//------------------------------------------------------
//Programmer:	Giovanni Delacruz
//Instructor:	Dr. Zhao
//Course:	Network Programming Fall 20
//Program:	TCP,UDP Socket Options
//Date:		11/15/2020
//Purpose:	This program showcases ways to modify
//		TCP and UDP Sockets using getsockopt()
//		and setsockopt().
//IMPORTANT:	Must compile with C99 or greater
//		"g++ giovannidelacruz.c" is fine
//-------------------------------------------------------
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>


int
main(int argc, char **argv)
{
	int			debug, keep, cork,type,tcp, mss, buff, udp;
	socklen_t	optlen;

	//create sockets
	udp= socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	tcp = socket(AF_INET, SOCK_STREAM, 0);
		//TCP Options
	printf("\n\u2193\u2193\u2193\u2193\u2193\u2193\u2193");
	printf("TCP Socket Information:");
        printf("\u2193\u2193\u2193\u2193\u2193\u2193\u2193\n");

	
		//Get socket type
		//should return a 1, indicating that it is using TCP
	optlen = sizeof(type);
	getsockopt(tcp, SOL_SOCKET, SO_TYPE, &type, &optlen);
	printf("Socket type:\t\t\t%d\n", type);
	
		//Get debug status
        optlen = sizeof(debug);
        getsockopt(tcp, SOL_SOCKET, SO_DEBUG, &debug, &optlen);
        printf("Debug Status:\t\t\t%d\n", debug);

		/* Fetch and print the TCP maximum segment size.  */
	optlen = sizeof(mss);
	getsockopt(tcp, IPPROTO_TCP, TCP_MAXSEG, &mss, &optlen);
	printf("TCP max segment size =\t\t%d\n", mss);

		//Fetch receive buffer size of TCP and print it 
	getsockopt(tcp, SOL_SOCKET, SO_RCVBUF, &buff, &optlen);
	printf("Receive buffer size=\t\t%d\n", buff);
	
		/* Set the send new receive buffer size, then fetch it and print its value.  */
	buff = buff/4;
	optlen = sizeof(buff);

	setsockopt(tcp, SOL_SOCKET, SO_RCVBUF, (void *)&buff, sizeof(buff));

	getsockopt(tcp, SOL_SOCKET, SO_RCVBUF, &buff, &optlen);
	printf("New receive buffer size=\t%d\n\n", buff);
		//end of TCP Section, this is just formatting...
	printf("\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606");
        printf("\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\u2606\n");
	
		//Beginning of UDP Options
        printf("\n\u2193\u2193\u2193\u2193\u2193\u2193\u2193");
        printf("UDP Socket Information:");
        printf("\u2193\u2193\u2193\u2193\u2193\u2193\u2193\n");

			//fetch socket type
			//Should return a 2, indicating it is using datagram
	 optlen = sizeof(type);
        getsockopt(udp, SOL_SOCKET, SO_TYPE, &type, &optlen);
        printf("Socket type:\t\t\t%d\n", type);
			//fetch keep alive status
			//Disabled by default,0
        optlen = sizeof(keep);
        getsockopt(udp, SOL_SOCKET, SO_KEEPALIVE, &keep, &optlen);
        printf("Keepalive Status:\t\t%d\n", keep);

                //Fetch receive buffer size of UDP and print it
        getsockopt(udp, SOL_SOCKET, SO_RCVBUF, &buff, &optlen);
        printf("Receive buffer size=\t\t%d\n", buff);

                /* Set the send new receive buffer size, then fetch it and print its value.  */
        buff = buff/4;
        optlen = sizeof(buff);

        setsockopt(udp, SOL_SOCKET, SO_RCVBUF, (void *)&buff, sizeof(buff));

        getsockopt(udp, SOL_SOCKET, SO_RCVBUF, &buff, &optlen);
        printf("New receive buffer size=\t%d\n", buff);
	
		//Enable Corking on UDP
        optlen = sizeof(cork);
        getsockopt(udp, IPPROTO_UDP, UDP_CORK, &cork, &optlen);
        printf("Corking status before set:\t%d\n",cork);
		//Corking will be zero, disabled by default
		//So set cork to 1 and enable
	cork++;
        setsockopt(udp, IPPROTO_UDP, UDP_CORK, &cork, sizeof(cork));
		//fetch corking
        getsockopt(udp, IPPROTO_UDP, UDP_CORK, &cork, &optlen);
		//print
        printf("Corking status after enable:\t%d\n\n",cork);

	exit(0);
}
