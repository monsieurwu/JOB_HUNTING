#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_sockfd);
void send_html(int client_sockfd);
void send_404(int client_sockfd);

int main() {

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
    while(1){

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
        if(close(client_sockfd) == -1) {
            printf("Failed to close client socket, [%d], %s\n", errno, strerror(errno));
            return -1;
        }
    }

    // 关闭服务端 Socket
    if (close(server_sockfd) == -1) {
        printf("Failed to close server socket, [%d], %s\n", errno, strerror(errno));
        return -1;
    }
    printf("server socket [%d] closed successfully\n", server_sockfd);

    return 0;
}

void send_file(int client_sockfd, const char *filename)
{
    char buf[4096];
    FILE* stream = NULL;

    printf("opening %s\n", filename);
    // 打开本地文件
    if ((stream = fopen(filename, "r")) == NULL) {
        printf("%s open failed\n", filename);
        send_404(client_sockfd); // 读取文件失败，返回页面不存在
        return ;
    }
    
    sprintf(buf, "HTTP/1.0 200 OK\r\n");
    send(client_sockfd, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html; charset=utf-8\r\n");
    send(client_sockfd, buf, strlen(buf), 0);
    sprintf(buf, "\r\n");
    send(client_sockfd, buf, strlen(buf), 0);
    

   
    // 从指定的流 stream 读取一行, 并向buf中追加一个'\0'字符
    while (fgets(buf, sizeof(buf), stream) != NULL) {
        // 按行发送文件内容
        send(client_sockfd, buf, strlen(buf), 0);
    }

    fclose(stream);
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

        // 解析 HTTP 请求行
        char method[16] = {0}, path[256] = {0};
        char filename[256];
        sscanf(recvbuf, "%s %s", method, path);
        
        // 只处理 GET 请求
        if (strcmp(method, "GET") == 0) {
            // 去掉开头的 '/'，得到文件名
            if (strcmp(path, "/") == 0) {
                strcpy(filename, "index.html"); // 如果是根路径，默认返回 index.html
            } else {
                strcpy(filename, &path[1]); // 去掉 '/'
            }

            // 尝试发送文件
            send_file(client_sockfd, filename);
        } else { // 否则返回页面不存在
            send_404(client_sockfd);
        }
    }
}

// http 状态码 404 表示未找到请求的页面
void send_404(int client_sockfd)
{
    char buf[4096];

    sprintf(buf, "HTTP/1.1 404 Not Found\r\n");
    send(client_sockfd, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: text/html\r\n");
    send(client_sockfd, buf, strlen(buf), 0);
    
    sprintf(buf, "\r\n");
    send(client_sockfd, buf, strlen(buf), 0);
    sprintf(buf, "<html><body><h1>404 Not Found</h1></body></html>");
    send(client_sockfd, buf, strlen(buf), 0);
}