mod node;
use node::Node;

// Singly linked list
pub struct LinkedList<T> {
    head: Box<Node<T>>,
    size: usize
}

impl<T> LinkedList<T> {
    pub fn new() -> Self {
        Self {
            head: Box::new(Node::Empty),
            size: 0
        }
    }

    pub fn len(&self) -> usize {
        self.size
    }

    pub fn push(&mut self, value: T) {
        let cur_head = self.head.take();
        let new_node = Box::new(Node::new(value, Box::new(cur_head)));
        self.head = new_node;
        self.size += 1;
    }

    pub fn pop(&mut self) -> Option<T> {
        let node = self.head.take();

        if let Node::NonEmpty(node) = node {
            self.head = node.next;
            self.size -= 1;
            Some(node.value)
        } else {
            None
        }
    }
}
