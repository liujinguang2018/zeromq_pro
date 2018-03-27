//天气更新客户端
//将SUB套接字连接到tcp://localhost:5556

#include "zhelpers.h"

int main(int argc, const char *argv[])
{
    void *context = zmq_ctx_new();

    //与服务器交流的套接字
    printf("Collecting updates from weather server...\n");
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    int rc = zmq_connect(subscriber, "tcp://localhost:5556");
    assert(rc == 0);

    //订阅邮政编码，默认是NYC， 10001
    const char *filter = (argc > 1) ? argv[1] : "10001";
    rc = zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, filter, strlen(filter));
    assert(rc == 0);

    //处理100个更新
    int update_nbr = 0;

    long total_temp = 0;
    for (;update_nbr < 100; update_nbr++)
    {
        char *string = s_recv(subscriber);
        printf("%s\n", string);

        int zipcode, temperature, relhumidity;
        sscanf(string, "%d %d %d", &zipcode, &temperature, &relhumidity);
        total_temp += temperature;

        free(string);
    }

    printf("Average temperature for zipcode '%s' was %dF\n", filter, (int)(total_temp/update_nbr));

    zmq_close(subscriber);
    zmq_ctx_destroy(context);

    return 0;
}