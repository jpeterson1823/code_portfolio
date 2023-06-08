fn main() {
    println!("Hello, world!");

    some_function();
    printnum(5);

    let a = 5;
    let b = 3;
    let c = add(a, b);
    println!("{} + {} = {}", a, b, c);
}

fn some_function() {
    println!("Some Function!");
}

fn printnum(num: i32) {
    println!("NUM: {}", num);
}

fn add(a: i32, b: i32) -> i32 {
    a + b
}
