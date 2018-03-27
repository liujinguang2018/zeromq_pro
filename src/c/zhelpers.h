
#ifndef __ZHELPERS_H_INCLUDE__
#define __ZHELPERS_H_INCLUDE__

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include <time.h>
#if !defined(WIN32)
#include <sys/time.h>
#endif

#if defined(WIN32)
#include <windows.h>
#endif

#if defined(WIN32)
#define srandom srand
#define random rand
#endif

//  Provide random number from 0..(num-1)
#define randof(num)  (int) ((float) (num) * random () / (RAND_MAX + 1.0))

#if defined(WIN32)
#define snprintf _snprintf_s
#endif

//从套接字接收0ZMQ字符串并将其转换为C字符串
static char *
s_recv(void *socket)
{
    zmq_msg_t message;
    zmq_msg_init(&message);

    int size = zmq_msg_recv(&message, socket, 0);
    if (size == -1) 
    {
        return NULL;
    }

    char *string = malloc(size+1);
    memcpy(string, zmq_msg_data(&message), size);
    string[size] = 0;

    return string;
}

#endif