# c_linked_list


Creating linked list in C  

RxNode: Create a linked list data structure, this struct is mainly used in 'RxList' struct  
        The 'RxNode' struct has 2 members: data, and pointer point to next node   
        RxNode_Create(): create a node   
        RxNode_Destroy(): destroy a node  
        RxNode_GetData(): retrieve data from a node  
        RxNode_SetData(): set data to a particular node  
        RxNode_GetNext(): get the 'next' pointer member from a node  
        RxNode_SetNext(): link node with the next node   

RxList: linked list operation   
        the 'RxList' struct has 3 members: a head node, a tail node, and size of the list   
        RxList_Init(): initialize a linked list   
        RxList_Cleanup()  
        RxList_AddToFront(): add a node to the front of linked list  
        RxList_AddToBack(): add a node to the back of linked list  
        RxList_Remove(): remove a node from list      
        RxList_GetFirst(): get data from the head node   
        RxList_GetLast(): get data from the tail node   
        RxList_GetAt():     
        RxList_Find():    
        RxList_Foreach():   
        RxList_IsEmpty(): Empty the linked list   
        RxList_GetSize(): get the size of the linked list          
