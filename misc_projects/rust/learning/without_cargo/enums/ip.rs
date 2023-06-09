// create enum and show that they can be different types
enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

// using an enum like this:
let home = IpAddr::V4(127, 0, 0, 1);
let loopback = IpAddr::V6(String::from("::1"));
