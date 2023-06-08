use std::collections::HashMap;

fn main() {
    // initialize a hashmap like this
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    // OR
    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];
    let mut scores: HashMap<_, _> =
        teams.into_iter().zip(initial_scores.into_iter()).collect();

    // accessing data
    let team_name = String::from("Blue");
    let score = scores.get(&team_name);

    // iteration
    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }

    // update value based on old value
    let text = "hello world wonderful world";
    let mut map = HashMap::new();
    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }
    println!("{:?}", map);
}
