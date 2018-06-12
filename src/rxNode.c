#include "rxNode.h"
#include "rxLib.h"
/*
Each node has 2 members: data and pointer, 
the pointer is used to point to next node.

When a node is created, both of data and pointer is set to NULL 
Use RxNode_SetData() to set data in the node
*/ 

//create node 'p_This'
RxNode *RxNode_Create(){
	RxNode * pThis = (RxNode*) RxCreate(sizeof(RxNode));
	if (pThis != NULL) {
		RxNode_Init(pThis);
	}
	return pThis;
}

void RxNode_Init(RxNode *const pThis){
	pThis->mp_data = NULL; //same as &pThis.mp_data=NULL
	pThis->mp_next = NULL;
}


//destroy node 'p_This'
void RxNode_Destroy(RxNode *pThis){
	pThis->mp_data = NULL;
	pThis->mp_next = NULL;
	RxDestroy(pThis);
}

// retrieve/return data from node 'pThis'
void * RxNode_GetData(RxNode *const pThis){
	return(pThis->mp_data);
}

//set data 'p_dataSet' to node 'pThis'
void RxNode_SetData(RxNode *const pThis, void *p_dataSet){
	pThis->mp_data = p_dataSet;
}


RxNode * RxNode_GetNext(RxNode *const pThis){
	return(pThis->mp_next);
}

//link node 'pThis' with  node 'nxtNode'
void RxNode_SetNext(RxNode *const pThis, RxNode *p_nxtNode){
	pThis->mp_next = p_nxtNode;
}
