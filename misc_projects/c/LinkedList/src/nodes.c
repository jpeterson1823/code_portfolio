/**
 * @file nodes.c
 * @author John Peterson
 * @brief Simple single pointer node class for integers, characters, and strings
 * @date 2021-11-04
 *
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include "../include/nodes.h"

// iNode definitions
iNode iNode_construct(int data) {
    // create node and allocate memory
    iNode node = (iNode)malloc(sizeof(iNode_struct));

    // store data and set next to nullptr
    node->data = data;
    node->next = NULL;

    // return this node
    return node;
}

void iNode_init(iNode self, int data) {
    // verify proper memory allocation; warn and do nothing if improper
    if (sizeof(*self) != sizeof(iNode_struct))
        printf("=WARN= iNode_init(): improper memory allocation found, obj will not be initialized.\n");

    // otherwise, set data and next pointer to proper values
    else {
        self->data = data;
        self->next = NULL;
    }
}

void iNode_destroy(iNode self) {
    free(self);
}
//



// cNode definitions
cNode cNode_construct(char data) {
    // create node and allocate memory
    cNode node = (cNode)malloc(sizeof(cNode_struct));

    // store data and set next to nullptr
    node->data = data;
    node->next = NULL;

    // return this node
    return node;
}

void cNode_init(cNode self, char data) {
    // verify proper memory allocation; warn and do nothing if improper
    if (sizeof(*self) != sizeof(cNode_struct))
        printf("=WARN= cNode_init(): improper memory allocation found, obj will not be initialized.\n");

    // otherwise, set data and next pointer to proper values
    else {
        self->data = data;
        self->next = NULL;
    }
}

void cNode_destroy(cNode self) {
    free(self);
}



// strNode definitions
strNode strNode_construct(char* data, int size) {
    // create strNode and allocate memory
    strNode node = (strNode)malloc(sizeof(strNode_struct));

    // allocate memory for the data char*
    node->data = (char*)malloc(sizeof(char) * size + 1);    // use size + 1 for null terminator

    // deepcopy data into node's data
    for (int i = 0; i < size; i++)
        node->data[i] = data[i];
    // add null terminator
    node->data[size] = '\0';

    // set node's next pointer to null
    node->next = NULL;

    // return new strNode obj
    return node;
}

void strNode_init(strNode self, char* data, int size) {
    // verify proper memory allocation; free and reconstruct if improper
    if (sizeof(*self) != sizeof(strNode_struct))
        printf("=WARN= strNode_init(): improper memory allocation found, obj will not be initialized.\n");

    // otherwise, set data and next pointer to proper values
    else {
        // allocate memory for node's data
        self->data = (char*)malloc(sizeof(char) * (size + 1));    // size + 1 to account for null terminator
        // deepcopy data into node
        for (int i = 0; i < size; i++)
            self->data[i] = data[i];
        // add null terminator
        self->data[size] = '\0';
    }
}

void strNode_destroy(strNode self) {
    if (self->data) free(self->data);
    free(self);
}
//
