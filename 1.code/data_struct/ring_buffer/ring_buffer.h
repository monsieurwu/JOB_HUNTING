#include <stdio.h>

#define OK 0          /* 成功 */
#define ERROR -1      /* 失败 */

#define MAX_SIZE 100  /* 定义环形缓冲区的最大容量 */

/* 定义环形缓冲区结构体 */
typedef struct {
    char buffer[MAX_SIZE];   /* 环形缓冲区 */
    int read_index;          /* 读指针 */
    int write_index;         /* 写指针 */
} ringbuffer_t;

void init_ringbuffer(ringbuffer_t* rbuf);
int is_empty(ringbuffer_t* rbuf);
int is_full(ringbuffer_t* rbuf);
int ringbuffer_write(ringbuffer_t* rbuf, char value);
int ringbuffer_read(ringbuffer_t* rbuf, char* value);
int ringbuffer_peek(ringbuffer_t* rbuf, char* value);
