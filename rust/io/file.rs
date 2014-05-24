use std::io::File;
use std::io::BufferedReader;

fn main() {
  let mut source = BufferedReader::new(
    File::open(&Path::new("file.rs"))
  );

  let mut c:int = 0;
  for line in source.lines() {
    c+=1;
    print!("{}: {}", c, line.unwrap());
  }
}
