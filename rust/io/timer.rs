use std::io::timer::Timer;

fn main() {
  let mut timer = Timer::new().unwrap();
  
  println!("sleeping for 10 ms");
  timer.sleep(10);

  let timeout = timer.oneshot(10);

  println!("oneshot sleeping for 10 ms");
  timeout.recv();

  let periodic = timer.periodic(10);
  for i in range(0,100) {
    println!("{} - periodic: sleeping for 10 ms", i);
    periodic.recv(); 
  }

   
  println!("sleep()ing for 10 ms");
  std::io::timer::sleep(10);
  
}
