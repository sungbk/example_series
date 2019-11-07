#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>

struct data
{
    int a;
    int b;
    int sum;
};
int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_un serveraddr;
    int  clilen;
    struct data mydata;

    if ( argc < 3 ) {
	    printf("argv[1] : [File Name] / argv[2] : [num1] / argv[3] [num2]\n");
	    return 0;
    }

    sockfd = socket(AF_UNIX, SOCK_DGRAM, 0); 
    if (sockfd < 0)
    {
	perror("exit : ");
	return 0;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sun_family = AF_UNIX;
    strncpy(serveraddr.sun_path, argv[1], 128);

    clilen = sizeof(serveraddr);

    mydata.a = atoi(argv[2]);
    mydata.b = atoi(argv[3]);
    mydata.sum = 0;

    if (sendto(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&serveraddr, clilen) < 0)
    {
	perror("send error : ");
	return 0;
    }
    recvfrom(sockfd, (void *)&mydata, sizeof(mydata), 0, (struct sockaddr *)&serveraddr, (socklen_t *)clilen);
    printf("result is : %d\n", mydata.sum);

    close(sockfd);
    return 0;
}
