#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int client_sockfd;

    struct sockaddr_in server_addr;
    char* server_ip = "10.0.2.15";
    unsigned short server_port = 8080;

    char *sendbuf = "this is hello from client!";

    char recvbuf[512] = { 0 };
    int recvbuflen = 512;

    // 创建一个 TCP IPv4 套接字
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (client_sockfd == -1) {
        printf("Failed to create server socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("file descriptor of server socket is [%d]\n", client_sockfd);


    // 套接字的地址协议族, AF_INET表示 IPv4 地址
    server_addr.sin_family = AF_INET;
    // 套接字的IP地址，将点分十进制字符串转成网络序整型
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    // 套接字的端口号，需要转换为网络序
    server_addr.sin_port = htons(server_port);

     // 发起连接请求
    if (connect(client_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect server, [%d], %s\n", errno, strerror(errno));
        close(client_sockfd);
        return -1;
    }
    printf("connect to server %s:%u successfully!\n", server_ip, server_port);

    // 发送数据
    if (send(client_sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
        printf("send failed, [%d], %s\n", errno, strerror(errno));
        close(client_sockfd);
        return -1;
    } else {
        printf("send data [%s] successfully\n", sendbuf);
    }

    // 阻塞接收数据
    ssize_t ret = recv(client_sockfd, recvbuf, sizeof(recvbuf) - 1, 0);
    if (ret < 0) {
        printf("recv failed, [%d], %s\n", errno, strerror(errno));
        close(client_sockfd);
        return -1;
    } else if (ret == 0) {
        printf("tcp closed\n");
    } else {
        recvbuf[ret] = '\0'; // 确保字符串以 NULL 结束
        printf("receive [%zd] bytes data: [%s]\n", ret, recvbuf);
    }


        // 关闭客户端 Socket
    if (close(client_sockfd) == -1) {
        printf("Failed to close client socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("client socket [%d] closed successfully\n", client_sockfd);
    
    return 0;
}