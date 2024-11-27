#include <stdio.h>
#include <string.h>
#include "../include/nodes.h"

int main(int argc, char* argv[]) {
    printf("Creating iNode pointers n1 and n2....\n");

    strNode n1 = (strNode)malloc(sizeof(strNode_struct));
    strNode n2 = (strNode)malloc(sizeof(strNode_struct));

    printf("Initializing strNode n1 and n2 with strNode_init()...\n");

    strNode_init(n1, "ungabungaduhungalobungalo1", strlen("ungabungaduhungalobungalo1"));
    strNode_init(n2, "bingusboingusdungusamungus2", strlen("bingusboingusdungusamungus2"));

    printf("Setting n1->next to n2...\n");

    n1->next = n2;

    printf("Displaying stored/set data...\n");

    printf("n1->data: %s\n", n1->data);
    printf("n1->next: %s\n", n1->next->data);

    printf("Attempting to destroy all alloc'd data...\n");

    strNode_destroy(n1);
    strNode_destroy(n2);

    printf("DONE\n");

    return 0;
}