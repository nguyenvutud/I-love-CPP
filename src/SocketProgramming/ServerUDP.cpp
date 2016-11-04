#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
using namespace std;
#define MYPORT "23457"
#define BACKLOG 10 //how many pending connections queue will hold
#define MAXDATASIZE 100
int mainudp()
{
	int sock, newsock;
	struct sockaddr_storage theiraddr;
	socklen_t addrsize;
	struct addrinfo hints, *res;
	memset(&hints,0,sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_flags=AI_PASSIVE;//fill in my ip for me
	getaddrinfo(NULL,MYPORT,&hints,&res);

	sock=socket(res->ai_family,res->ai_socktype,res->ai_protocol); //nam trong 2 thu vien sys/type.h va sys/socket.h

	bind(sock,res->ai_addr,res->ai_addrlen);

	cout<<"SERVER IS READY!" <<endl;

	char buf[MAXDATASIZE];
	int len, flags=0,bytes_received;
	bytes_received=recvfrom(sock,buf,MAXDATASIZE-1, flags, (struct sockaddr*)&theiraddr,&addrsize);
	buf[bytes_received]='\0';

	cout<<"Client sent:" << buf <<endl;

//	close(sock);
//	close(newsock);
	return 0;
}
