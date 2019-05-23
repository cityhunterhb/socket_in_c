/***************************************************
*      FileName: client.cpp
*      Author&website:  cityhunterhb.top
*      Mail:  cityhunterhb.top@gmail.com
*      Description: ---
*      CreatedTime: 2019-05-23 22:31:34
*      LastModified: 2019-05-23 22:41:37
****************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


int main(void)
{
	//create sock
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	//request
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; //ipv4
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(1234);
	connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	//read data
	char buffer[40];
	read(sock, buffer, sizeof(buffer) - 1);

	printf("Message from server: %s\n", buffer);

	//close
	close(sock);

	return 0;
}
