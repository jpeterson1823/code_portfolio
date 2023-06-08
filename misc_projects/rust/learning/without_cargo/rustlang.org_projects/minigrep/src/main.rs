use std::process;
use std::env;

use minigrep::Config;

fn main() {
    // get args
    let args: Vec<String> = env::args().collect();
    let config = Config::new(&args).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep::run(config) {
        eprintln!("Process ran into a problem: {}", e);
        process::exit(1);
    }
}
