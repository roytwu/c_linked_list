#ifndef RXLIB_H_
#define RXLIB_H_

#include <stdlib.h>

void * RxCreate(size_t size);
void RxDestroy(void * p_ptr);


void debug_memAlloc();
void debug_memFree();



#endif //RXLIB_H_