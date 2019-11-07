#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include<stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <string.h>
#include <fcntl.h>

struct data {
	int a;
	int b;
	int sum;
};

int main(int argc, char *argv[])
{
	int sockfd = -1;
	socklen_t client = -1;
	struct data mydata;
	struct sockaddr_un clientaddr, serveraddr;

	if ( argc < 2 ) {
		printf("argv[1] : [File Name]\n");
return 0;
	}

	sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if ( sockfd < 0 ) {
		perror("sock err : ");
		return 0;
	}
	unlink(argv[1]);

	memset(&serveraddr, 0, sizeof(sockaddr_un));
	serveraddr.sun_family = AF_UNIX;
	//128은 임의의 값
	strncpy(serveraddr.sun_path, argv[1], 128);

	if ( bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 ) {
		perror("bind err : ");
		return 0;
	}
	client = sizeof(clientaddr);

	while(1) {
		recvfrom(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&serveraddr, &client);
		printf("%d + %d = %d\n", mydata.a, mydata.b, mydata.a + mydata.b);
		sendto(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&serveraddr, client);
	}

	close(sockfd);
	return 0;
}
