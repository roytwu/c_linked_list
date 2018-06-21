// File name: main.c  (Linked_List)
// Author: Roy T Wu, roywu2018@gmail.com

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
	RxList_Init(p_list);
	
	RxList_AddToFront(p_list, p_data1);
	RxList_AddToFront(p_list, data_ary);
	// RxList_AddToFront(p_list, p_data1);
	// RxList_AddToFront(p_list, (data_ary+2));

	//RxList_Remove(p_list, data_ary);

	
	int output1 = *(int *)RxList_GetFirst(p_list);
	int output2 = *(int *)RxList_GetAt(p_list,1);
	// int output3 = (uintptr_t)RxNode_GetData(RxList_GetAt(p_list,1)); 


	printf("Output1 is %d\n", output1);
	printf("Output2 is %d\n", output2);
	// printf("%d\n", output3);

	RxList_CleanList(p_list);
	printf("-----test line-----\n");

	return 0;
}