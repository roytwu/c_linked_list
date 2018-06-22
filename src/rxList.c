#include <stdio.h>
#include <stdlib.h> //NULL
#include <stdbool.h>
#include "rxList.h"
#include "rxNode.h"

static void RxList_Add(RxList *const pThis, void *p_item, bool front);

//------ ----- ----- -----
void RxList_Init(RxList *const pThis){
	pThis->mp_head = NULL;  //equivalent to (&p_me).mp_head = NULL;
	pThis->mp_tail = NULL;
	pThis->m_size = 0;
}//----- ----- ----- -----


//------ ----- ----- -----
void RxList_AddToFront(RxList *const pThis, void *p_item){
	RxList_Add(pThis, p_item, true);
}//----- ----- ----- -----


//------ ----- ----- -----
void RxList_AddToBack(RxList *const pThis, void *p_item){
	RxList_Add(pThis, p_item, false);
}//----- ----- ----- -----


//------ ----- ----- -----
void RxList_CleanList(RxList *const pThis){
	while (pThis->mp_head != NULL)
	{

		// let curNode traverse, starting from head node
		RxNode * p_curNode = (pThis->mp_head);

		(pThis->mp_head) = RxNode_GetNext(p_curNode);//reset head node
		
		RxNode_Destroy(p_curNode);//destroy and free old head
		p_curNode = NULL;

		(pThis->m_size)-- ;
		//printf("m_size is: %d\n", pThis->m_size);
	}


	return;
}//----- ----- ----- -----


//------ ----- ----- -----
void RxList_Remove(RxList *const pThis, void *p_item){

	if (pThis->mp_head == NULL){ return; } //verify that if the list is empty
	
	RxNode * p_curNode = (pThis->mp_head); //store head node
	RxNode * p_nxtNode;  //next node

	//if the head node itself holds the data(p_item) to be deleted
	if(RxNode_GetData(p_curNode) == p_item){
		printf("Case1 - delete head node\n");

		(pThis->mp_head) = RxNode_GetNext(p_curNode);  //reset head
		//if the new head is NULL, the list shall be NULL
		if(pThis->mp_head == NULL){
			pThis->mp_tail = NULL;
		}

		RxNode_Destroy(p_curNode);  //destroy and free old head
		p_curNode = NULL;
		pThis->m_size--;
		return;
	}
	
	p_nxtNode = RxNode_GetNext(p_curNode); 

	//traverse to search for the data(p_item) to be deleted
	while(p_nxtNode != NULL)
	{
		p_nxtNode = RxNode_GetNext(p_curNode); 
		//if the key(p_item) has been found
		if(RxNode_GetData(p_nxtNode) == p_item){
			printf("case2 - delete midlle/tail node\n");

			//re-link, link curent node with the next-next node
			RxNode_SetNext(p_curNode, RxNode_GetNext(p_nxtNode));
			
			//if the to-be-deleted node is the tail node
			if(pThis->mp_tail == p_nxtNode){
				pThis->mp_tail = p_curNode; //reset/change tail node
			}

			RxNode_Destroy(p_nxtNode); //destroy the to-be-delete node
			p_nxtNode = NULL;

			(pThis->m_size)--;
			return;
		}
		//p_curNode = p_nxtNode; //traverse to next node
		p_curNode = RxNode_GetNext(p_curNode); //traverse to next node
	}//-while
	return;
}//----- ----- ----- -----


void * RxList_GetAt(RxList *const pThis, int pos){
	if(pos >= pThis->m_size){ return NULL; }
	
	//create a node to traverse in the list, starting from head
	RxNode * p_travNode = pThis->mp_head;
	
	for(int i=0; i<pos; i++){
		p_travNode = RxNode_GetNext(p_travNode);
	}
	return RxNode_GetData(p_travNode);
}


void * RxList_GetFirst(RxList *const pThis){
	if(pThis->mp_head == NULL){ return NULL; }
	return RxNode_GetData(pThis->mp_head);
}


void * RxList_GetLast(RxList *const pThis){
	if(pThis->mp_tail == NULL){ return NULL; }
	return RxNode_GetData(pThis -> mp_tail);
}

/*
void * RxList_Find(RxList *const pThis, void *p_item, 
	RxObjFindHandler handler){
	void * p_retval = NULL;
	void * p_value = NULL;

	RxNode * op_iter = pThis->mp_head;

	RxObjFinder finder;
	RxObjFinder_Init(&finder, item, handler);

	int pos;
	for(pos=0; pos<(pThis->m_size); pos++){
		p_value = RxNode_GetData(op_iter);

		if(RxObjFinder_IsEqual(&finder, value)){
			p_retval = p_value;
			break;
		}

		op_iter = RxNode_GetNext(op_iter);
	}
	return p_retval;
}


void * RxList_ForEach(RxList *const pThis, RxObjFindHandler handler,
	void * p_data, size_t dataSize){

}	
*/


bool RxList_IsEmpty(RxList *const pThis){
	return(pThis->m_size == 0);
}


uint16_t RxList_GetSize(RxList *const pThis){ 
	return (pThis->m_size);
}


static void RxList_Add(RxList *const pThis, void *p_item, bool front){
	RxNode *p_newNode = RxNode_Create();  //create new node
	RxNode_SetData(p_newNode, p_item); //set data to new node

	if(pThis->mp_head == NULL){
		//there is no node is the list, set both head and tail node
		RxNode_SetNext(p_newNode, NULL);
		pThis->mp_head = p_newNode;
		pThis->mp_tail = p_newNode;

	} else if (front == true){
		//add a new node in front of head node
		RxNode_SetNext(p_newNode, pThis->mp_head); //link new node to pThis
		pThis->mp_head = p_newNode; //new nide becomes the head node now
	} else {
		//add a node behind tail node
		RxNode_SetNext(p_newNode, NULL); //link new node to NULL  
		RxNode_SetNext(pThis->mp_tail, p_newNode); //link tail node to new node
		pThis->mp_tail = p_newNode;  //new node becomes the tail node now
	}

	(pThis->m_size)++;
	return; 
}