use std::io;

fn main() {
  for line in io::stdin().lines() {
    print!("stdin: {}", line.unwrap());
  }
}
