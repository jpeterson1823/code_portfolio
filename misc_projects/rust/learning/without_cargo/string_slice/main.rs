fn main() {
    let s = String::from("Hello World");
    let word = first_word(&s);
    println!("The first word is: {}", word);
}

/* Determine the first word by returning the index of the first list.
 * Will return the length of the string if no spaces are found.
 * This is the old method
fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }

    s.len()
}*/

/* Determine the first word by returning the index of the first list.
 * Will return the length of the string if no spaces are found.
 * This is the better method
 */
fn first_word(s: &String) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    
    &s[..]
}
