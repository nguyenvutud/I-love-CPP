#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
using namespace std;
int maincc()
{
	int sock;
	struct addrinfo hints, *res;
	memset(&hints,0,sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_DGRAM;
	hints.ai_flags=AI_PASSIVE;//fill in my ip for me
	getaddrinfo("127.0.0.1","23457",&hints,&res);
	sock=socket(res->ai_family,res->ai_socktype,res->ai_protocol); //nam trong 2 thu vien sys/type.h va sys/socket.h

	cout<<"CONNECT SUCCESSFULLY"<<endl;
	char *msg = "Hello World";
	int len, bytes_sent;
	len=strlen(msg);
	bytes_sent=sendto(sock,msg,len,0,res->ai_addr,res->ai_addrlen);
	//close(sock);
	return 0;
}
