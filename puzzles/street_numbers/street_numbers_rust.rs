fn sumSeries(first: i64, last: i64) -> i64 {
  let n:i64 = (last-first)+1;
  (n * ((2*first) + ((n-1)*1)))/2
}


fn main() {
   
  let mut home:i64 = 1;
  let mut end:i64 = 2;
  let mut lowSum:i64 = 1;
  let mut highSum: i64 = 2;

  for numbers in range(0,10) {
    loop {
      if lowSum < highSum {home+=1}
      end += 1;
      lowSum = sumSeries(1, home-1);
      highSum = sumSeries(home+1, end);
      if lowSum == highSum { break; }  
    }
    println!("{} - {}  {}", numbers, home, end);
  }  
}

