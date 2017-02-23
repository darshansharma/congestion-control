#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc, char * argv[]){
	int sockfd, newsockfd,n;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[1]));
	bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	listen(sockfd, 5);
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
	read(newsockfd, buffer, sizeof(buffer));
	printf("\n* C: * %s\n",buffer );
	bzero((char*)buffer, sizeof(buffer));
	printf("Enter your message: \n");
	fgets(buffer, sizeof(buffer), stdin);
	write(newsockfd, buffer, strlen(buffer));
	return 0;
}
