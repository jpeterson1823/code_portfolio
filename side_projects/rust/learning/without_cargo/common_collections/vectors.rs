fn main() {
    // create vec and add elements
    let v1: Vec<i32> = Vec::new();
    v1.push(5);
    v1.push(6);
    v1.push(7);
    v1.push(8);

    // or init with macro
    let v2 = vec![1, 2, 3];

    // read from vec
    let third: &i32 = &v[2];

    // OR
    match v1.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println("There is no third element"),
    }

    // iteration (immutable)
    let v = vec![100, 32, 57];
    for i in &v {
        println!("{}", i);
    }

    // iteration (mutable)
    let mut a = vec![100, 32, 57];
    for i in &mut v {
        *i += 50;
    }
}
