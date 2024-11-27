#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// create Rectangle "methods" and "associated functions"
impl Rectangle {
    // this is a method AND an associated function
    fn area(&self) -> u32 {
        self.width * self.height
    }
    // same here
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
    
    // this is ONLY an associated funciton cuz it does not require &self
    // you call these with :: syntax, like String::new()
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size,
        }
    }
}


fn main() {
    let rect = Rectangle {
        width: 30,
        height: 50,
    };
    let square = Rectangle::square(5);
    display_function(&rect);
    display_function(&square);
}


// here is how to pass a struct to a function
fn display_function(rect: &Rectangle) {
    // print rectangle with debug format thing
    println!("Rectangle: {:?}", rect);

    // can also print debug info using macro, but it prints to stderr
    dbg!(&rect);

    // calculate and print area of rectangle struct using it's methods
    println! (
        "The area of the rectangle is {} square pixels.",
        rect.area()
    );
}
