const SPACE:  &str = "  ";
const FBLOCK: &str = "* ";
const RBLOCK: &str = " *";

fn main() {
    let base = 5;
    let mut sep = String::new();

    for _i in 0..base {
        sep.push_str("--");
    }

    triangle_ljust(base);
    println!("{}", sep);
    triangle_rjust(base);
    println!("{}", sep);
    pyramid(base);
}

fn pyramid(base: u32) {
    let mut k = base;

    for i in 0..base {
        for _j in 0..k {
            print!(" ");
        }
        k -= 1;
        for _j in 0..i+1 {
            print!("* ");
        }
        println!();
    }
}

fn triangle_rjust(base: u32) {
    for i in 0..base {
        let mut line = String::new();
        for _j in i..base-1 {
            line.push_str(&SPACE);
        }
        for _j in 0..i+1 {
            line.push_str(&RBLOCK);
        }
        println!("{}", line);
    }
}

fn triangle_ljust(base: u32) {
    for i in 0..base {
        // create line string
        let mut line = String::new();
        
        // add blocks
        for _j in 0..i+1 {
            line.push_str(&FBLOCK);
        }
        // add spaces
        for _j in i..base {
            line.push_str(&SPACE);
        }

        // print line
        println!("{}",line);
    }
}
