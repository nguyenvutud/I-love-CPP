/*
 * testsocket.cpp
 *
 *  Created on: Oct 7, 2016
 *      Author: nguyenvu
 */

#include "testsocket.h"
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

namespace socketprogramming {

testsocket::testsocket() {
	// TODO Auto-generated constructor stub

}

testsocket::~testsocket() {
	// TODO Auto-generated destructor stub
}
int testsocket::getaddressinformation(){
	int status;
	struct addrinfo hints; //nam trong thu vien sys/socket.h
	struct addrinfo *servinfo;
	memset(&hints,0,sizeof hints); //make sure the struct is empty
	hints.ai_family= AF_UNSPEC;		//don't care IPv4 or IPv6
	hints.ai_socktype=SOCK_STREAM; 	//using TCP socket
	//get ready to connect
	status=getaddrinfo("www.example.net","23456", &hints,&servinfo);
	return status;

}
int testsocket::getsocketinfo()
{
	int sock;
	struct addrinfo hints, *res;
	memset(&hints,0,sizeof hints);
	hints.ai_family=AF_UNSPEC;
	hints.ai_socktype=SOCK_STREAM;
	hints.ai_flags=AI_PASSIVE;//fill in my ip for me
	getaddrinfo(NULL,"23456",&hints,&res);

	sock=socket(res->ai_family,res->ai_socktype,res->ai_protocol); //nam trong 2 thu vien sys/type.h va sys/socket.h
	bind(sock,res->ai_addr,res->ai_addrlen);

	// !!! THIS IS THE OLD WAY !!!
//	int sockfd;
//	struct sockaddr_in my_addr;
//	sockfd = socket(PF_INET, SOCK_STREAM, 0);
//	my_addr.sin_family = AF_INET;
//	my_addr.sin_port = htons(MYPORT);	// short, network byte order
//	my_addr.sin_addr.s_addr = inet_addr("10.12.110.57");
//	memset(my_addr.sin_zero, '\0', sizeof my_addr.sin_zero);
//	bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr);
	return sock;
}
} /* namespace socketprogramming */
