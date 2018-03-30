//任务发生器
//将PUSH套接字绑定到tcp://localhost:5557
//通过那个套接字发送批量任务给工人

#include "zhelpers.h"

int main()
{
    void *context = zmq_ctx_new();

    //用于发送消息的套接字
    void *sender = zmq_socket(context, ZMQ_PUSH);
    zmq_bind(sender, "tcp://*:5557");

    //用于发送批次开始消息的套接字
    void *sink = zmq_socket(context, ZMQ_PUSH);
    zmq_connect(sink, "tcp://localhost:5558");

    printf("Press Enter when the workers are ready.");
    getchar();
    printf("Sending tasks to workers...\n");

    //第一个小时为"0", 它表示批次开始
    s_send(sink, "0");

    //初始化随机发生器
    srandom((unsigned)time(NULL));

    //发送100个任务
    

}