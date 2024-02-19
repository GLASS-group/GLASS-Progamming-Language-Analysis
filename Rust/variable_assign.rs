use std::time::Instant;
use std::thread::sleep;

fn main() {
    const ONE_BILLION_D : f64 = 1000000000.0;
    const ONE_BILLION : u64 = 1000000000;
    const ONE_MILLION : u32 = 1000000;
    const NUM_TRIALS : u16 = 50;

    let mut cumulative : f64 = 0.0;
    for _i in 0..(NUM_TRIALS-1) {
        let start_time = Instant::now();
        let mut x : u64 = 0;
        while x < ONE_BILLION {
            x += 1;
        }
        let end_time = Instant::now();
        let difference = (end_time - start_time).as_secs() * ONE_BILLION +  (end_time - start_time).subsec_nanos() as u64;
        let seconds : f64 = difference as f64 / ONE_BILLION_D;
        cumulative += seconds;
        println!("Time to process: {} seconds", seconds);
    }

    let seconds = cumulative / NUM_TRIALS as f64;
    println!("Average time to process: {} seconds", seconds);

}