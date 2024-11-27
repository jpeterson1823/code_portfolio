/**
 * @file linkedlist.c
 * @author John Peterson (jpeterson1823)
 * @breif Simple OOP linked List for integers, characters, and strings
 * @date 2021-11-06
 *
 * @copyright Copyright (c) 2021
 */

#include "../include/nodes.h"
#include "../include/linkedlist.h"


// ------------- iNode Linked List
/**
 * Default iNode Linked List constructor
 * @return          alloc'd iLinkedList pointer
 */
iLinkedList iLinkedList_construct() {
    iLinkedList list = (iLinkedList)malloc(sizeof(iNode_LinkedList_struct));
    iNode head = (iNode)malloc(sizeof(iNode_struct));
    iNode tail = (iNode)malloc(sizeof(iNode_struct));
    int numElements = 0;
}

/**
 * TODO(john)
 * Initializes a properly alloc'd iLinkedList pointer
 * @param       self - pointer to alloc'd memory to be initialized
 */
void iLinkedList_init(iLinkedList self) {

}

/**
 * TODO(john)
 * Destroys an iLinkedList object and destroys all its nodes
 * @param       self - pointer to linkedlist to destroy
 */
void iLinkedList_destroy(iLinkedList self) {
    // TODO(john): iteratively free alloc'd data at every node

    // free alloc'd data at self pointer
    free(self);
}

/**
 * TODO(john)
 * Adds an integer element to the end of the list
 * @param       element - element to be appended to the list
 */
