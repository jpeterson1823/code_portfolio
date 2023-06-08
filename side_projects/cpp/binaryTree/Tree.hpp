#include <vector>

struct node {
    int value;
    node* left;
    node* right;
};

class Tree {
    private:
        node* root;
        void insert(int key, node* node);
        void destroyTree(node* leaf);
        void preorderPrint(node* leaf);
        void inorderPrint(node* leaf);
    
    public:
        Tree();
        ~Tree();
        void insert(int key);
        void destroyTree();
        void preorderPrint();
        void inorderPrint();
};