#include <assert.h>
#include "rxLib.h"

//RxCreate is like a custom version of malloc,
//which creates a struct
void * RxCreate(size_t size){
	void * p_rtnValue = malloc(size);
	assert(p_rtnValue != NULL);

	return p_rtnValue;  //return a void pointer
}

//RxDesgtroy is like a custom version of free,
//which it is used to dispose a struct
void RxDestroy(void * p_ptr){
	if(p_ptr != NULL){
		free(p_ptr);
	}
}