/**
 * @file linkedlist.h
 * @author John Peterson (jpeterson1823)
 * @brief Simple OOP Linked List for integers, characters, and strings
 * @date 2021-11-06
 * 
 * @copyright Copyright (c) 2021
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// include node classes
#include "../include/nodes.h"




// typedef struct prototypes
typedef struct INODE_LINKEDLIST {
    iNode* current;
    iNode head;
    iNode tail;
    int numElements;
} iNode_LinkedList_struct;
typedef iNode_LinkedList_struct* iLinkedList;

typedef struct CNODE_LINKEDLIST {
    cNode head;
    cNode tail;
    cNode current;
    int numElements;
} cNode_LinkedList_struct;
typedef cNode_LinkedList_struct* cLinkedList;

typedef struct STRNODE_LINKEDLIST {
    strNode head;
    strNode tail;
    strNode current;
    int numElements;
} strNode_LinkedList_struct;
typedef strNode_LinkedList_struct* strLinkedList;
// ---------------------




// iNode Linked List prototypes
iLinkedList iLinkedList_construct();
void        iLinkedList_destroy(iLinkedList self);
void        iLinkedList_init(iLinkedList self);
void        iLinkedList_remove(iLinkedList self, int index);
void        iLinkedList_add(iLinkedList self, int data);
int         iLinkedList_get(iLinkedList self, int index);

#endif
