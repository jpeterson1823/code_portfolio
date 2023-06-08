// struct with generic (must be same type for x and y)
struct Point<T> {
    x: T,
    y: T,
}

// generic implementation
impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }
}

// struct with generic (can accept multiple types)
struct BetterPoint<T, U> {
    x: T,
    y: U,
}


fn largest <T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];

    let result = largest(&number_list);
    println!("The largest number is {}", result);

}
