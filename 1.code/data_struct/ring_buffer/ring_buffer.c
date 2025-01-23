#include "ring_buffer.h"

/* 初始化环形缓冲区 */
void init_ringbuffer(ringbuffer_t* rbuf)
{
    rbuf->read_index = 0;
    rbuf->write_index = 0;
}

/* 判空操作，如果是空返回1，非空返回0 */
int is_empty(ringbuffer_t* rbuf)
{
    return rbuf->read_index == rbuf->write_index;
}

/* 判满操作，如果是满返回1，不满返回0 */
int is_full(ringbuffer_t* rbuf)
{
    return (rbuf->write_index + 1) % MAX_SIZE == rbuf->read_index;
}

/* 写入数据 */
int ringbuffer_write(ringbuffer_t* rbuf, char value)
{
    if (is_full(rbuf)) {
        printf("RingBuffer is full!\n");
        return ERROR;
    }
    rbuf->buffer[rbuf->write_index] = value;
    /* 循环缓冲区的写指针下标 */
    rbuf->write_index = (rbuf->write_index + 1) % MAX_SIZE;
    return OK;
}

/* 读取数据 ，将头部元素移除，并通过传出参数传出该元素 */
int ringbuffer_read(ringbuffer_t* rbuf, char* value)
{
    if (is_empty(rbuf)) {
        printf("RingBuffer is empty!\n");
        return ERROR;
    }
    *value = rbuf->buffer[rbuf->read_index];
    rbuf->read_index = (rbuf->read_index + 1) % MAX_SIZE;
    return OK;
}

/* 查看当前缓冲区头部数据（不移除） */
int ringbuffer_peek(ringbuffer_t* rbuf, char* value)
{
    if (is_empty(rbuf)) {
        printf("RingBuffer is empty!\n");
        return ERROR;
    }
    *value = rbuf->buffer[rbuf->read_index];
    return OK;
}
