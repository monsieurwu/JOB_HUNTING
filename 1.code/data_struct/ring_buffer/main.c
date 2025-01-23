#include "ring_buffer.h"

int main(void)
{
    ringbuffer_t rbuf;  // 定义一个环形缓冲区

    /* 初始化环形缓冲区 */
    init_ringbuffer(&rbuf);

    /* 判空测试 */
    if (is_empty(&rbuf)) {
        printf("RingBuffer is empty\n\n");
    }
    else {
        printf("RingBuffer not empty\n\n");
    }

    /* 写入一些数据 */
    printf("add [%c] into ringbuffer\n", 'A');
    ringbuffer_write(&rbuf, 'A');
    printf("add [%c] into ringbuffer\n", 'B');
    ringbuffer_write(&rbuf, 'B');
    printf("add [%c] into ringbuffer\n", 'C');
    ringbuffer_write(&rbuf, 'C');
    printf("add [%c] into ringbuffer\n", 'D');
    ringbuffer_write(&rbuf, 'D');

    /* 查看头部数据 */
    char value;
    if (ringbuffer_peek(&rbuf, &value) == OK) {
        printf("front value of ringbuffer is [%c]\n", value);
    }

    /* 读取所有数据 */
    while (!is_empty(&rbuf)) {
        ringbuffer_read(&rbuf, &value);
        printf("read value [%c] from ringbuffer\n", value);
    }

    /* 再次判空 */
    if (is_empty(&rbuf)) {
        printf("RingBuffer is empty\n");
    }

    return 0;
}