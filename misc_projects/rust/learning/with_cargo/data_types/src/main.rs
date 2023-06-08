fn main() {
    // create and use tup
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is {}", y);

    // accessing individual elements of tup
    let five_hundred = tup.0;
    let six_point_four = tup.1;
    let one = tup.2;

    // create and use array
    let array: [i32; 5] = [1, 2, 3, 4, 5];
    let first = array[0];
    let second = array[1];
}
