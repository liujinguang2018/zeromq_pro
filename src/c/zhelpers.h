
#ifndef __ZHELPERS_H_INCLUDE__
#define __ZHELPERS_H_INCLUDE__

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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

#endif