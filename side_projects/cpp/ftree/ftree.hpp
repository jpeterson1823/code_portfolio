#include <string>
#include <vector>
using namespace std;

class Node {
    private:
        string name;
        Node* parent;
        vector<Node> contents;
    
    public:
        Node(string name);
        Node(string name, Node* parent);
        void addItem(Node item);
        string getName();
        Node* getParent();
        vector<Node> getContents();
};