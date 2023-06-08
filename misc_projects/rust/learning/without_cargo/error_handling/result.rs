use std::fs::File;
use std::io::{self, Read, ErrorKind};

fn main() {
    let f = File::open("hello.txt");

    let f = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Problem creating the file: {:?}", e),
            },
            other_error => {
                panic!("Problem opening the file: {:?}", other_error)
            }
        },
    };

    // panic shortcut
    let b = File::open("hello.txt").unwrap();
    let c = File::open("hello.txt").expect("Failed to open file");
}

fn read_username_from_file() -> Result<String, io::Error> {
    // open file and if OK, continue. If Err, make function return Err Result
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    // read file into string. If OK, continue. If Err, make function return Err Result
    f.read_to_string(&mut s)?;
    Ok(s)
}

fn read_shorter() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}

fn read_shortest() -> Result<String, io::Error> {
    fs::read_to_string("hello.txt")
}
