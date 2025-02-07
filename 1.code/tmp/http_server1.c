      
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_html(int client_sockfd)
{
    // 响应行和响应头
    const char *header = "HTTP/1.1 200 OK\r\n"
                         "Content-Type: text/html; charset=utf-8\r\n\r\n";
    // 响应体
    const char *body = "<html>"
                        "<head>\r\n"
                            "<title>我的第一个网页</title>\r\n"
                        "</head>\r\n"
                        "<body>\r\n"
                            "<h1>欢迎来到我的网页</h1>\r\n"
                            "<p>这是我学习HTML写的第一个网页！</p>\r\n"
                        "</body>\r\n"
                        "</html>\r\n";

    send(client_sockfd, header, strlen(header), 0);
    send(client_sockfd, body, strlen(body), 0);
}

void handle_client(int client_sockfd)
{
    char recvbuf[BUFFER_SIZE];
    ssize_t bytes_recv;
    
    // 阻塞接收数据
    bytes_recv = recv(client_sockfd, recvbuf, sizeof(recvbuf) - 1, 0);

    if (bytes_recv < 0) {
        printf("recv failed, [%d], %s\n", errno, strerror(errno));
    } else if (bytes_recv == 0) {
        printf("tcp closed\n");
    } else {
        recvbuf[bytes_recv] = '\0';
        printf("receive [%zd] bytes data:\n%s", bytes_recv, recvbuf);
        
        send_html(client_sockfd);
    }
}

int main(void)
{
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    char buffer[BUFFER_SIZE];

    // 创建一个 TCP IPv4 套接字
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
    // 套接字的IP地址，INADDR_ANY 相当于 0.0.0.0
    server_addr.sin_addr.s_addr = INADDR_ANY;
    // 套接字的端口号，需要转换为网络序
    server_addr.sin_port = htons(PORT);
    // 将套接字绑定到指定的地址和端口
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    }
    printf("bind to server %s:%u successfully!\n", "0.0.0.0", PORT);

    // 在绑定的套接字上监听连接请求
    if (listen(server_sockfd, 2) < 0) {
        printf("Failed to listen server, [%d], %s\n", errno, strerror(errno));
        close(server_sockfd);
        return -1;
    }
    printf("listen to server %s:%u successfully!\n", "0.0.0.0", PORT);

    while (1) {
        // 阻塞接收客户端连接
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            printf("accept failed, [%d], %s\n", errno, strerror(errno));
            continue;
        }
        // 当有客户端发起连接时，退出阻塞
        printf("client socket [%d], ip: %s, port: %d connect successfully\n", 
            client_sockfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    
        // 处理客户端请求
        handle_client(client_sockfd);
        
        // 关闭客户端连接
        close(client_sockfd);
    }

    // 关闭服务端 Socket
    if (close(server_sockfd) == -1) {
        printf("Failed to close server socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("server socket [%d] closed successfully\n", server_sockfd);
    return 0;
}

    