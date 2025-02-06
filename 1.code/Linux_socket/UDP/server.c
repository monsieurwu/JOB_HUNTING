#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int server_sockfd;

    struct sockaddr_in server_addr, client_addr;
    char* server_ip = "10.0.2.15";
    unsigned short server_port = 8080;
    socklen_t client_addr_len = sizeof(client_addr);

    char recvbuf[512] = { 0 };
    int recvbuflen = 512;

    char *sendbuf = "this is world from server!";

    // 创建一个 TCP IPv4 套接字
    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (server_sockfd == -1) {
        printf("Failed to create server socket, [%d], %s\n", errno, strerror(errno));
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
        printf("Failed to bind, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    }
    printf("bind to server %s:%u successfully!\n", server_ip, server_port);

    // 阻塞接收数据
    ssize_t recv_len = recvfrom(server_sockfd, recvbuf, recvbuflen, 0, (struct sockaddr*)&client_addr, &client_addr_len);
    if (recv_len < 0) {
        printf("recvfrom failed, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    } else {
        recvbuf[recv_len] = '\0'; // 确保字符串以 NULL 结束
        printf("receive [%zd] bytes data: [%s]\n", recv_len, recvbuf);
        printf("from ip: %s, port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }


        // 发送数据到目标地址
    ssize_t sent_bytes = sendto(server_sockfd, sendbuf, strlen(sendbuf), 0,
                                (struct sockaddr *)&client_addr, sizeof(client_addr));
    if (sent_bytes < 0) {
        printf("send failed, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
    } else {
        printf("send data [%s] successfully\n", sendbuf);
    }








    // 关闭服务端 Socket
    if (close(server_sockfd) == -1) {
        printf("Failed to close server socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("server socket [%d] closed successfully\n", server_sockfd);

    return 0;
}