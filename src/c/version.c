#include <zmq.h>
#include <stdio.h>

int main(void) 
{
    int major, minor, patch;

    zmq_version(&major, &minor, &patch);
    printf("Current OMQ version is %d.%d.%d\n", major, minor, patch);

    return EXIT_SUCCESS;
}