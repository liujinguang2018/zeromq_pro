// 天气更新服务器
// 发布随机的天气更新

#include "zhelpers.h"

int main(void)
{
    //准备上下文和发布者
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    const char *paddr = "tcp://*:5556";
    int rc = zmq_bind(publisher, paddr);
    if (rc != 0)
    {
        printf("bind to %s failed\n", paddr);
        return 1;
    }

    #if !defined(WIN32)
    const char *pipc = "ipc://weather.ipc";
    rc = zmq_bind(publisher, pipc);
    if (rc != 0)
    {
        printf("bind to %s failed\n", pipc);
        return 1;        
    }
    #endif

    //初始化随机数发生器
    srandom((unsigned)time(NULL));

    while (1) {
        //获取随机值
        int zipcode, temperature, relhumidity;
        zipcode = randof(100000);
        temperature = randof(215) - 80;
        relhumidity = randof(50) + 10;

        //发布订阅消息
        char update[32];
        snprintf(update, sizeof(update), sizeof(update)-1, "%05d %d %d", zipcode, temperature, relhumidity);
        printf("%s\n", update);
        zmq_send(publisher, update, strlen(update), 0);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);

    return 0;
}