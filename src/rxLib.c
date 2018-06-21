#include <stdio.h>
#include <assert.h>
#include "rxLib.h"

static int new_total = 0;
static int free_total = 0;

//------ ----- ----- -----
void debug_memAlloc(){
	assert(new_total += 1);
	assert( printf("memory allocated... (%d)\n", new_total) );
}//----- ----- ----- -----


//------ ----- ----- -----
void debug_memFree(){
	assert(free_total += 1);
	assert( printf("memory freed... (%d)\n", free_total) );
}//----- ----- ----- -----


//------ ----- ----- -----
//RxCreate is a custom version of malloc,
void * RxCreate(size_t size){
	void * p_rtnValue = malloc(size);
	assert(p_rtnValue != NULL);

	debug_memAlloc();
	return p_rtnValue;  //return a void pointer
}//----- ----- ----- -----


//------ ----- ----- -----
//RxDesgtroy is a custom version of free
void RxDestroy(void * p_ptr){
	if(p_ptr != NULL){
		free(p_ptr);
		debug_memFree();
	}

}//----- ----- ----- -----