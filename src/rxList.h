#ifndef _RXLIST_H_ //include guards
#define _RXLIST_H_ //include guards

#include <stdbool.h>
#include <stdint.h>  //uint16_t
#include "rxNode.h"
//#include "rxObjectFinder.h"
//#include "rxObjectAction.h"


typedef struct RxList{
	RxNode *mp_head;
	RxNode *mp_tail;
	int    m_size;
}RxList;

/*
    p_head            p_tail  
	 |                 |
	 |                 |
 +---+-----+       +---+-----+
 | # |  o--------> | # |  # --------> NULL 
 +---+-----+       +---+-----+	  
   RxNode             RxNode
*/

void RxList_Init(RxList *const pThis);

void RxList_Cleanup(RxList * const pThis);

void RxList_AddToFront(RxList * const pThis, void *p_item);

void RxList_AddToBack(RxList * const pThis, void *p_item);

void RxList_Remove(RxList *const pThis, void *p_item);

void * RxList_GetAt(RxList *const pThis, int pos);

void * RxList_GetFirst(RxList *const pThis);

void * RxList_GetLast(RxList *const pThis);

/*
void * RxList_Find(RxList *const pThis, void *p_item, 
	RxObjectFindHandler handler);

void * RxList_ForEach(RxList *const pThis, RxObjectFindHandler handler,
	void * p_data, size_t dataSize);	
*/

bool RxList_IsEmpty(RxList *const pThis);

uint16_t RxList_GetSize(RxList *const pThis);


#endif //_RXLIST_H_ include guards