use std::fs;

fn main() {
    let contents = list_dir("./").unwrap();
    println!("{:?}", contents);
}

fn list_dir(path: &str) -> Result<Vec<String>, std::io::Error> {
    Ok(fs::read_dir(path)?
        .map(|d| String::from(
                d.expect("[ERR] Failed to unwrap DirEntry")
                 .path()
                 .file_name()
                 .expect("[ERR] Failed to parse filename into OsStr")
                 .to_str()
                 .expect("[ERR] Failed to convert OsStr to str"))
        ).collect())
}
