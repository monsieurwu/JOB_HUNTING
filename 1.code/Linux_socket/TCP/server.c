#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main() {
    int server_sockfd, client_sockfd;

    struct sockaddr_in server_addr, client_addr;

    char* server_ip = "10.0.2.15";
    unsigned short server_port = 8080;
    socklen_t client_addr_len = sizeof(client_addr);

    char recvbuf[512] = { 0 };
    int recvbuflen = 512;

    char *sendbuf = "this is world from server!";

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sockfd == -1) {
        printf("Failed to create server socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("file descriptor of server socket is [%d]\n", server_sockfd);

    int opt = 1; // 套接字选项
    // 设置 SO_REUSEADDR 选项
    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("setsockopt failed, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    }

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

    // 在绑定的套接字上监听连接请求
    if (listen(server_sockfd, 2) < 0) {
        printf("Failed to listen server, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    }
    printf("listen to server %s:%u successfully!\n", server_ip, server_port);


    // 程序阻塞，接受客户端连接
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        printf("accept failed, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    }
        // 当有客户端发起连接时，退出阻塞
    printf("client socket [%d], ip: %s, port: %d connect successfully\n", 
        client_sockfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // 阻塞接收数据
    ssize_t ret = recv(client_sockfd, recvbuf, sizeof(recvbuf) - 1, 0);
    if (ret < 0) {
        printf("recv failed, [%d], %s\n", errno, strerror(errno));
        close(client_sockfd);
        close(server_sockfd);
        return -1;
    } else if (ret == 0) {
        printf("tcp closed\n");
    } else {
        recvbuf[ret] = '\0'; // 确保字符串以 NULL 结束
        printf("receive [%zd] bytes data: [%s]\n", ret, recvbuf);
    }

    // 发送数据
    if (send(client_sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
        printf("send failed, [%d], %s\n", errno, strerror(errno));
        close(client_sockfd);
        close(server_sockfd);
        return -1;
    } else {
        printf("send data [%s] successfully\n", sendbuf);
    }



    // 关闭客户端 Socket
    if (close(client_sockfd) == -1) {
        printf("Failed to close client socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("client socket [%d] closed successfully\n", client_sockfd);


    // 关闭服务端 Socket
    if (close(server_sockfd) == -1) {
        printf("Failed to close server socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("server socket [%d] closed successfully\n", server_sockfd);


    return 0;
}