use std::io;

fn main() {
    println!("Enter a number:");
    
    let mut n = String::new();

    io::stdin()
        .read_line(&mut n)
        .expect("Failed to read line from stdin");

    let n: u32 = n.trim().parse().expect("Failed to parse int");

    if n % 4 == 0 {
        println!("number is divisible by 4");
    } else if n % 3 == 0 {
        println!("number is divisible by 3");
    } else if n % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }

    // remember, blocks of code evaluate to their last value
    let condition = true;
    let number = if condition { 5 } else { 6 };
    println!("Weird-ass conditional number: {}", number);

    // loop
    let mut count = 0;
    'counting_up: loop {
        println!("count={}", count);
        let mut remaining = 10;

        loop {
            println!("remaining={}", remaining);
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }
        count += 1;
    }
    println!("End count={}", count);
}
