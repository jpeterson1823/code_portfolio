enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn main() {
    let mut count = 0;
    match coin {
        Coin::Quarter => println!("Quarter"),
        _ => count += 1,
    }

    if let Coin::Quarter = coin {
        println!("Quarter");
    } else {
        count += 1;
    }
}
