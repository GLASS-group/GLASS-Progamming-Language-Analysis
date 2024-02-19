use std::io;

fn main() {
    const ONE_BILLION_D : f64 = 1000000000.0;
    const ONE_BILLION : u64 = 1000000000;
    const ONE_MILLION : usize = 1000000;
    const NUM_TRIALS : u16 = 50;

    let mut x : usize = 0;
    let mut strings: Vec<String> = Vec::with_capacity(100000);
    while x < 100000 {
        if x == 0 {
            strings.push("a".to_string());
        } else {
            strings.push(strings[x - 1].clone() + "a")
        }
        x += 1;
    }

    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

}