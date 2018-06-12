#ifndef _RXNODE_H_ //include guards
#define _RXNODE_H_ //include guards

typedef struct RxNode RxNode; //tydeft bofore struct delacration
struct RxNode{
	void   *mp_data;
	RxNode *mp_next;
};


//create node 'p_me'
RxNode * RxNode_Create();

//sub-function of RxNode_Create()
void RxNode_Init(RxNode *const pThis);

//destroy node 'p_me'
void RxNode_Destroy(RxNode *pThis);


// retrieve/return data from node 'pThis'
void * RxNode_GetData(RxNode *const pThis);


//set data 'p_dataSet' to node 'pThis'
void RxNode_SetData(RxNode *const pThis, void *p_dataSet);

//get the 'p_next' pointer from Node 'pThis'
RxNode * RxNode_GetNext(RxNode *const pThis);


//link node 'pThis' with  node 'nxtNode'
void RxNode_SetNext(RxNode *const pThis, RxNode *p_nxtNode); 


#endif //_RXNODE_H_ include guards