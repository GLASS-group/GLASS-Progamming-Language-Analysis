use std::time::{Instant, Duration};
use std::thread::sleep;

fn main() {
    const ONE_BILLION_D : f64 = 1000000000.0;
    const ONE_BILLION : u64 = 1000000000;
    const ONE_MILLION : u32 = 1000000;
    const NUM_TRIALS : u16 = 50;

    let mut cumulative : f64 = 0.0;
    for _i in 0..(NUM_TRIALS-1) {
        let start_time = Instant::now();
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
        let end_time = Instant::now();
        let difference = (end_time - start_time).as_secs() * ONE_BILLION +  (end_time - start_time).subsec_nanos() as u64;
        let seconds : f64 = difference as f64 / ONE_BILLION_D;
        cumulative += seconds;
        println!("Time to process: {} seconds", seconds);
        drop(strings);
        sleep(Duration::from_millis(3));
    }

    let seconds = cumulative / NUM_TRIALS as f64;
    println!("Average time to process: {} seconds", seconds);

}