#include <iostream>
#include <math.h>

#define LOOP for (;;)

long sumSeries(long first, long last){
  long n = (last-first)+1;
  return (n * ((2*first) + ((n-1)*1)))/2 ;
}

int main() {
   
  int numbers = 0;
  long home = 1;
  long end = 2;
  long lowSum = 1;
  long highSum = 2;

  for(numbers=0; numbers < 10; numbers++){
    LOOP {
      if(lowSum < highSum) home ++;
      end++;
      lowSum = sumSeries(1, home-1);
      highSum = sumSeries(home+1, end);
      if(lowSum == highSum) break; 
    }
    std::cout << numbers << " - " << home << "    " << end << "\n";
  }  
}

