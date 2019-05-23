/***************************************************
*      FileName: server.cpp
*      Author&website:  cityhunterhb.top
*      Mail:  cityhunterhb.top@gmail.com
*      Description: ---
*      CreatedTime: 2019-05-23 22:04:14
*      LastModified: 2019-05-23 22:30:58
****************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(void)
{
	//create socket
	int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//bind ip address and port
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; //IPV4
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //address
	serv_addr.sin_port =  htons(1234); //port
	bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//listen
	listen(serv_sock, 20);

	//accept
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

	//send data
	char str[] = "socket test!";
	write(clnt_sock, str, sizeof(str));

	//close
	close(clnt_sock);
	close(serv_sock);

	return 0;
}
