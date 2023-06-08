// can create structs similar to C
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

// can also create structs in this manner as well
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

// Empty structs, called "Unit-Like" structs
struct AlwaysEqual;
// not too sure what these do yet...

fn main() {
    // manual creation
    let user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };

    // using update syntax with shorthand
    let user2 = User {
        email: String::from("another@example.com"),
        ..user1
    };
    /* Manual method
    let user2 = User {
        active: user1.active,
        username: user1.username,
        email: String::from("another@example.com"),
        sign_in_count: user1.sign_in_count,
    };*/

    // using builder function
    let user3 = build_user(String::from("user2@example.com"), String::from("UserSEKANDO"));
    // access data with dot notaion
    println!("{}", user3.email);
    
    // using different type of struct
    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);
}

fn build_user(email: String, username: String) -> User {
    /* Without shorthand
    User{
        email: email,
        username: username,
        active: true,
        sign_in_count: 1,
    }*/

    // with shorthand; param names must be the same
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}
