use std::io::BufferedReader;
use std::io::File;

fn main () {
  let path = Path::new("read_to_vec.rs");
  let mut file = BufferedReader::new(File::open(&path));

  // This is from the 0.10 sample, and it doesn't work anymore? wtf
  let lines: ~[~str] = file.lines().map(|x| x.unwrap()).collect();


  // unfinished
}
