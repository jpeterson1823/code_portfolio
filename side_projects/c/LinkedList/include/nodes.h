/**
 * @file nodes.h
 * @author John Peterson (jpeterson1823)
 * @brief Simple single pointer node class for integers, characters, and strings
 * @date 2021-11-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdlib.h>
#ifndef NODES_H 
#define NODES_H 

// define integer node struct
typedef struct INT_NODE {
    int data;
    struct INT_NODE* next;
} iNode_struct;
typedef iNode_struct* iNode;


// define char node struct
typedef struct CHAR_NODE {
    char data;
    struct CHAR_NODE* next;
} cNode_struct;
typedef cNode_struct* cNode;





// define string (char[]) node struct
typedef struct STR_NODE {
    char* data;
    struct STR_NODE* next;
} strNode_struct;
typedef strNode_struct* strNode;




/**
 * ----- iNode Definitions -----
 * iNode_construct() - create iNode with specified data, NULL next pointer
 * iNode_destroy()   - frees iNode's allocated memeory
 * iNode_init()      - initialize an iNode pointer
 */
iNode iNode_construct(int data);
void  iNode_init(iNode self, int data);
void  iNode_destroy(iNode self);

// -----


// Prototypes - cNode
cNode cNode_construct(char data);
void  cNode_init(cNode self, char data);
void  cNode_destroy(cNode self);





// Prototypes - strNode
strNode strNode_construct(char* data, int size);
void    strNode_init(strNode self, char* data, int size);
void    strNode_destroy(strNode self);

#endif
