#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
using namespace std;
#define MYPORT "23456"
#define BACKLOG 10 //how many pending connections queue will hold
#define MAXDATASIZE 100
int mainaa()
{
	int sock, newsock;
	struct sockaddr_storage theiraddr;
	socklen_t addrsize;
	struct addrinfo hints, *res;
	memset(&hints,0,sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_flags=AI_PASSIVE;//fill in my ip for me
	getaddrinfo(NULL,MYPORT,&hints,&res);

	sock=socket(res->ai_family,res->ai_socktype,res->ai_protocol); //nam trong 2 thu vien sys/type.h va sys/socket.h
	bind(sock,res->ai_addr,res->ai_addrlen);
	listen(sock,BACKLOG);
	cout<<"SERVER IS WAITING FOR CONNECTING FROM CLIENT!" <<endl;
	addrsize=sizeof theiraddr;
	newsock=accept(sock,(struct sockaddr *)&theiraddr, & addrsize);
	if(newsock == -1 )
	{
		cout<<"OCCURED ERRORS DURING CONNECTION PROCESSING" <<endl;
		return 0;
	}
	cout<<"ACCEPTED FROM CLIENT:"<<endl;
	char buf[MAXDATASIZE];
	int len, flags=0,bytes_received;
	bytes_received=recv(newsock,buf,MAXDATASIZE-1, flags);
	buf[bytes_received]='\0';

	cout<<"Client sent:" << buf <<endl;

//	close(sock);
//	close(newsock);
	return 0;
}
