#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main(int argc, char * argv[]){
	int sockfd, n;
	char buffer[256];
	struct sockaddr_in serv_addr;
	if(argc < 3){
		printf("Please provide sufficent number of arguments - IP, PORT");
		return 0;
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0){ printf("\nERROR: Opening socket\n");  }
	bzero((char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(atoi(argv[2]));
	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<0){
		printf("\nInvalid IP address provided\n");
	}
	bzero((char*)&buffer, sizeof(buffer));
	printf("\nEnter your message: \n");
	fgets(buffer,sizeof(buffer), stdin);
	n = write(sockfd, buffer, strlen(buffer));
	if(n<0){ printf("\nERROR: Writing to socket\n");  }
	bzero(buffer, sizeof(buffer));
	n = read(sockfd, buffer, sizeof(buffer));
	if(n<0){ printf("\nERROR: Reading from socket\n");  }
	printf("%s", buffer);
	return 0;
}
