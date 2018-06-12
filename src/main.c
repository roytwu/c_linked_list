// File: main.c  (Linked_List)
// Programmer: Roy TWu

#include <stdio.h>
#include <stdint.h> //uintptr_t
#include <stdlib.h> //NULL
#include "rxLib.h"
#include "rxNode.h"
#include "rxList.h"


int main(){
	printf("\nTest the 'RxList' structure...\n");
	int d1 = 50;
	int * p_data1 = &d1;

	int data_ary[] = {1, 2, 3, 4};

	RxList o_list;
	RxList * p_list = &o_list;
	RxList_AddToFront(p_list, p_data1);
	RxList_AddToFront(p_list, data_ary);
	RxList_AddToFront(p_list, (data_ary+1));
	RxList_AddToFront(p_list, (data_ary+2));

	//RxList_Remove(p_list, data_ary);

	
	int output1 = (uintptr_t)RxNode_GetData(RxList_GetFirst(p_list));
	int output2 = (uintptr_t)RxNode_GetData(RxList_GetAt(p_list,0));
	int output3 = (uintptr_t)RxNode_GetData(RxList_GetAt(p_list,1)); 


	printf("%d %d %d\n", output1, output2, output3);

	// for(int i=0; i<3; i++){
	// 	printf("%d ", &(output+i));
	// }

	return 0;
}