
struct Transition {
    read: String,
    write: String,
}

struct State {
    name: String,
    transitions: Vec<Transition>
}
