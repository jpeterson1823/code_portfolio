#[derive(Debug)]
pub struct NodeValue<T> {
    pub value: T,
    pub next: Box<Node<T>>
}

impl<T> NodeValue<T> {
    pub fn new(value: T, next: Box<Node<T>>) -> Self {
        Self {
            value,
            next,
        }
    }
}

impl<T> Clone for NodeValue<T>
where
    T: Clone,
{
    fn clone(&self) -> Self {
        Self {
            value: self.value.clone(),
            next: Box::clone(&self.next),
        }
    }
}




#[derive(Debug)]
pub enum Node<T> {
    Empty,
    NonEmpty(NodeValue<T>)
}

impl<T> Node<T> {
    pub fn new(value: T, next: Box<Node<T>>) -> Self {
        Node::NonEmpty(NodeValue::new(value, next))
    }

    pub fn take(&mut self) -> Self {
        let mut curr = Self::Empty;
        std::mem::swap(&mut curr, self);
        curr
    }
}
