#include "string.h"

String String_construct(char* str) {
    // get length of provided string
    int len = 0;
    while (str[len] != '\0')
        len++;
    
    // create string reference and allocate memory for members
    String string = (String)malloc(sizeof(String));
    string->data = (char*)malloc(sizeof(char) * len);
    string->len = len;

    // copy data to string
    for (int i = 0; i < len; i++)
        string->data[i] = str[i];

    // return new string object
    return string;
}

void String_destroy(String self) {
    free(self->data);
    free(self);
}

void String_deepcopy(String og_str, String copy) {
    // delete copy's char* data and reallocate memory to ensure proper copying
    free(copy->data);
    copy->data = (char*)malloc(sizeof(char) * og_str->len);
    // deepcopy data
    for (int i = 0; i < og_str->len; i++)
        copy->data[i] = og_str->data[i];
}