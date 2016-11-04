/*
** showip.c -- show IP addresses for a host given on the command line
*/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>

using namespace std;
//struct addrinfo {
//	int ai_flags; 				//AI_PASSIVE, AI_CANONNAME, etc.
//	int ai_family; 				//AF_INET, AF_INET6, AF_UNSPEC
//	int ai_socktype; 			//SOCK_STREAM, SOCK_DGRAM
//	int ai_protocol; 			//use 0 for "any"
//	size_t ai_addrlen; 			//size of ai_addr in bytes
//	struct sockaddr *ai_addr; 	//struct sockaddr_in or _in6
//	char *ai_canonname;			//full canonical hostname
//	struct addrinfo *ai_next; 	//linked list, next node
//};
int mainsss(int argc, char *argv[])
{
	struct addrinfo hints, *res, *p;
	struct sockaddr_in sa;
	int status;
	char ipstr[INET6_ADDRSTRLEN];
	if (argc != 2) {
		fprintf(stderr,"usage: showip hostname\n");
		return 1;
	}
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 2;
	}



	inet_pton(AF_INET,"192.168.1.100",&(sa.sin_addr)); //Convert IP address to numbers-and-dots notation
	char *myip;
	myip=inet_ntoa(sa.sin_addr);

	printf("IP address after coverting to string: %s \n",myip);
	//cout << "IP Address:"<< sa.sin_addr <<endl;

	printf("IP addresses for %s:\n\n", argv[1]);
	for(p = res;p != NULL; p = p->ai_next) {
		void *addr;
		char *ipver;
		// get the pointer to the address itself,
		// different fields in IPv4 and IPv6:
		if (p->ai_family == AF_INET) { // IPv4
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		} else { // IPv6
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
			}
		// convert the IP to a string and print it:
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
		printf(" %s: %s\n", ipver, ipstr);
	}
	printf("DAY LA LENH COUT \n");

	freeaddrinfo(res); // free the linked list
	return 0;
}
