// create enum with empty variants
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

// use match construct to convert variants to values
fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        },
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter=> 25,
    }
}
