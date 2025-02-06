      
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
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

void handle_post(int client_sockfd, char *query)
{
    // 响应行和响应头
    const char *header = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=utf-8\r\n\r\n";
    send(client_sockfd, header, strlen(header), 0);

    char username[32] = { 0 }, password[32] = { 0 }, interests[32] = { 0 };
    char key[32], value[32];
    // 按 & 分割字符串
    // 此处 query 是字符串：username=kieran&password=123456&interests=coding
    char *token = strtok(query, "&");
    while (token) {
        memset(key, 0, sizeof(key));
        memset(value, 0, sizeof(value));
        // 解析 xxx=xxx 格式内容
        sscanf(token, "%[^=]=%s", key, value);

        // 根据 key 将值赋给相应的变量
        if (strcmp(key, "username") == 0) {
            strncpy(username, value, sizeof(username) - 1);
        }
        else if (strcmp(key, "password") == 0) {
            strncpy(password, value, sizeof(password) - 1);
        }
        else if (strcmp(key, "interests") == 0) {
            strncpy(interests, value, sizeof(interests) - 1);
        }

        token = strtok(NULL, "&");  // 继续解析下一个键值对
    }

    // 响应体
    char html_response[1024];
    snprintf(html_response, sizeof(html_response),
        "<html>\n"
        "<head><title>用户输入</title></head>\n"
        "<body>\n"
        "<h1>用户输入</h1>\n"
        "<p><strong>用户名：</strong> %s</p>\n"
        "<p><strong>密码：</strong> %s</p>\n"
        "<p><strong>兴趣：</strong> %s</p>\n"
        "</body>\n"
        "</html>\n", username, password, interests);

    send(client_sockfd, html_response, strlen(html_response), 0);
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
        return;
    } else if (bytes_recv == 0) {
        printf("tcp closed\n");
        return;
    }
    recvbuf[bytes_recv] = '\0';
    printf("receive [%zd] bytes data:\n%s", bytes_recv, recvbuf);
    
    // 解析 HTTP 请求行
    char method[16] = { 0 }, path[256] = { 0 };
    char filename[256];
    // HTTP GET请求：  GET / HTTP/1.1
    // HTTP POST请求：  POST /submit HTTP/1.1
    // 解析 HTTP 请求行的方法和路径，sscanf遇到空格或换行时结束
    sscanf(recvbuf, "%s %s", method, path);

    printf("\nmethod:[%s] path:[%s]\n", method, path);

    // 只处理 GET 请求
    if (strncmp(method, "GET", 4) == 0) {
        printf("Received a GET request\n");
        // 去掉开头的 '/'，得到文件名
        if (strcmp(path, "/") == 0) {
            strcpy(filename, "index.html"); // 如果是根路径，默认返回 index.html
        }
        else {
            strcpy(filename, &path[1]); // 去掉 '/'
        }

        // 尝试发送文件
        send_file(client_sockfd, filename);
    }
    else if (strncmp(method, "POST", 5) == 0) {
        printf("Received a POST request\n");
        // 查找 Content-Length 获取 POST 数据的长度
        char *content_length_str = strstr(recvbuf, "Content-Length: ");
        int content_length = 0;
        if (content_length_str) {
            sscanf(content_length_str, "Content-Length: %d", &content_length);
        }
        // 获取 POST 数据主体部分
        char *body = strstr(recvbuf, "\r\n\r\n");
        if (body) {
            body += 4; // 跳过头部和空行的分隔
            printf("POST body: %.*s\n", content_length, body);
        }
        // 处理 POST 请求的逻辑
        handle_post(client_sockfd, body);
    }
    else { // 否则返回页面不存在
        send_404(client_sockfd);
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
        printf("\nclient socket [%d], ip: %s, port: %d connect successfully\n", 
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

    