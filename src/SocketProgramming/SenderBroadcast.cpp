#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#define PORT 5000
using namespace std;
int mainss()
{
	int sock;
	int broadcast =1;
	struct addrinfo hints, *res;
	struct sockaddr_in theiraddr;
	struct hostent *he;

	sock=socket(res->ai_family,res->ai_socktype,res->ai_protocol); //nam trong 2 thu vien sys/type.h va sys/socket.h
	//this call is what allows broadcast packet to be sent
	setsockopt(sock,SOL_SOCKET,SO_BROADCAST,&broadcast,sizeof broadcast);
	he=gethostbyname("192.168.157.119");
	theiraddr.sin_family=AF_INET;
	theiraddr.sin_port= htons(PORT);
	theiraddr.sin_addr= *((struct in_addr *)he->h_addr_list[0]);
	memset(theiraddr.sin_zero,'\0',sizeof theiraddr.sin_zero);

	char *msg = "Hello World";
	int len, bytes_sent;
	len=strlen(msg);
	bytes_sent=sendto(sock,msg,len,0,(struct sockaddr *)&theiraddr, sizeof theiraddr);

	cout<<"sent: " <<bytes_sent <<"bytes to: "<<inet_ntoa(theiraddr.sin_addr) <<endl;

	//close(sock);
	return 0;
}
