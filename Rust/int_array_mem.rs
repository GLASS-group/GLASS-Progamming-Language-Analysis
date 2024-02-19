use std::io;

fn main() {
    const ONE_BILLION_D : f64 = 1000000000.0;
    const ONE_BILLION : u64 = 1000000000;
    const ONE_MILLION : usize = 1000000;
    const NUM_TRIALS : u16 = 50;

    let mut x : usize = 0;
    let mut ints: Vec<u32> = Vec::with_capacity(ONE_MILLION);
    while x < ONE_MILLION {
        ints.push(x as u32);
        x += 1;
    }

    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer);

}