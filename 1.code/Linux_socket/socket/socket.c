#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        return -1;
    }
    printf("Socket successfully created...\n");

    printf("file descriptor of socket is [%d]\n", sockfd);

    // 关闭 Socket
    if (close(sockfd) == -1) {
        printf("Failed to close socket\n");
        return -1;
    }
    printf("Socket successfully closed...\n");
    printf("socket [%d] closed successfully\n", sockfd);


    return 0;
}