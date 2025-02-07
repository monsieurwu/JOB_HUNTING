#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int server_sockfd;

    struct sockaddr_in server_addr;
    char* server_ip = "192.168.0.127";
    unsigned short server_port = 8080;
    
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sockfd == -1) {
        printf("Failed to create server socket\n");
        return -1;
    }
    printf("file descriptor of server socket is [%d]\n", server_sockfd);

    // 套接字的地址协议族, AF_INET表示 IPv4 地址
    server_addr.sin_family = AF_INET;
    // 套接字的IP地址，将点分十进制字符串转成网络序整型
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    // 套接字的端口号，需要转换为网络序
    server_addr.sin_port = htons(server_port);
    
    // 将套接字绑定到指定的地址和端口
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind\n");
        close(server_sockfd);
        return -1;
    }
    printf("bind to server %s:%u successfully!\n", server_ip, server_port);

    // 在绑定的套接字上监听连接请求
    if (listen(server_sockfd, 2) < 0) {
        printf("Failed to listen server \n");
        close(server_sockfd);
        return -1;
    }
    printf("listen to server %s:%u successfully!\n", server_ip, server_port);






    // 关闭 Socket
    if (close(server_sockfd) == -1) {
        printf("Failed to close server_sockfd\n");
        return -1;
    }
    printf("server_sockfd successfully closed...\n");
    printf("server_sockfd [%d] closed successfully\n", server_sockfd);


    return 0;
}