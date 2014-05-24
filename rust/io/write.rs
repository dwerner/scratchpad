use std::io;
use std::io::File;

fn main() {
  let mut file = File::create(&Path::new("write.txt"));
  for line in io::stdin().lines() {
    let result = file.write_str(format!("{}", line.unwrap()));
    println!("IoResult: {}", result);
  }
}
