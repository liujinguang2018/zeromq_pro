//
//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back
//

#include <zmq.h>

int main(void)
{
    int count = 0;
    void *context = zmq_ctx_new();

    //初始化与客户端交流的套接字
    void *responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");
    if (rc !=0 ) 
    {
        printf("Bind to tcp://*:5555 failed\n");

        return 1;
    }

    while (1)
    {
        //等待客户端请求
        zmq_msg_t request;
        zmq_msg_init(&request);
        zmq_msg_recv(&request, responder, 0);
        ++count;
        printf("Received hello %d\n", count);
        zmq_msg_close(&request);


        //将应答发送给客户端
        zmq_msg_t reply;
        zmq_msg_init_size(&reply, 5);
        memcpy(zmq_msg_data(&reply), "world", 5);
        zmq_msg_send(&reply, responder, 0);
        zmq_msg_close(&reply);
    }
}