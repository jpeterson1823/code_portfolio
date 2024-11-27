#ifndef J_STRING_H
#define J_STRIN_H

// define str struct
typedef struct STR_OBJ {
    char* data;
    int len;
} String_struct;
typedef String_struct* String;

// Prototypes - String
String String_construct(char* c_str);
void   String_destroy(String self);
void   String_deepcopy(String og_str, String copy);

#endif