/*
*** 1.  Street Numbers ***

A computer programmer lives in a street with houses numbered consecutively 
(from 1) down one side of the street. Every evening she walks her dog by 
leaving her house and randomly turning left or right and walking to the 
end of the street and back. One night she adds up the street numbers of the houses she passes (excluding her own). 

The next time she walks the other way she repeats this and finds, to her astonishment, that the two sums are the same. Although this is determined in part by her house number and in part by the number of houses in the street, she nevertheless feels that this is a desirable property for her house to have and decides that all her subsequent houses should exhibit it. 

Write a program to find pairs of numbers that satisfy this condition.

To start your list the first two pairs are: (house number, last number):

  6         8
 35        49

- Your program must compute 10 of these pairs of numbers.
- Your program must run no i64er than a few seconds.

 */


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

