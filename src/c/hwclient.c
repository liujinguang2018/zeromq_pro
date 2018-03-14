//
//  Hello World client in C++
//  Connects REQ socket to tcp://localhost:5555
//  Sends "Hello" to server, expects "World" back

#include <zmq.h>
#include <stdio.h>

int main(void)
{
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    printf("Connecting to hello world server...\n");
    int rc = zmq_connect(requester, "tcp://localhost:5555");
    if (rc != 0)
    {
        printf("failed\n");
        return 1;
    }

    //int request_nr;
    for (int request_nr = 0; request_nr != 10; request_nr++)
    {
        zmq_msg_t request;
        zmq_msg_init_size(&request, 5);
        memcpy(zmq_msg_data(&request), "hello", 5);
        printf("Send hello %d...\n", request_nr);
        zmq_msg_send(&request, requester, 0);
        zmq_msg_close(&request);

        zmq_msg_t reply;
        zmq_msg_init(&reply);
        zmq_msg_recv(&reply, requester, 0);
        printf("Received World %d\n", request_nr);
        zmq_msg_close(&reply);
    }

    zmq_close(requester);
    zmq_ctx_destroy(context);

    return 0;
}