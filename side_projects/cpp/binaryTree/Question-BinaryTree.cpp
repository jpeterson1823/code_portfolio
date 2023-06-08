/*
    Since I asked this question this morning, I remembered that structs were
    a thing and that completely solved the problem I was having, but I am still
    curious about some things. The original question was this:
        Using the class below, sometimes I get the error: "Incomplete type not allowed."
        So the question is: Should I use pointers here, or a reference to the class object
        I'm confused because I know classes are just pointers at a base level, so I'm
        not sure how to proceed. 
*/
class Node {
    private:
        int value;
        // This is what I am talking about.
        // This gives a "Incomplete type not allowed." flag
        // "<error-type> Node::left      incomplete type not allowed"
        Node left;
        Node right;

        // Do I use pointers:
        Node* pLeft;
        Node* pRight;

        // Or do I use references:
        Node& rLeft;
        Node& rRight;

    public:
        Node();
        void insert(Node node);
};

/*
    The error I was talking about in class fixed itself somehow when I wrote this. It
    didn't pop up when I was writing this script, so I guess at some point in the old
    code I messed up so bad that even the compiler didn't know what was wrong!

    When I came home to write this for an example, I also remembered that structs exist,
    so the question is the same here as well:
*/
struct nodeStruct {
    int value;
    // Do I use Pointers:
    nodeStruct* pLeft;
    nodeStruct* pRight;

    // Or do I use references:
    nodeStruct& rLeft;
    nodeStruct& rRight;
};

/*
    Also, for sanity's sake, I promise I dont add "r" to the front of references
    and "p" to the front of pointers in a normal script.
*/