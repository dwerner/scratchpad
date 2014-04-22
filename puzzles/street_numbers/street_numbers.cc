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
- Your program must run no longer than a few seconds.

 */

#include <iostream>
#include <math.h>

double sumSeries(double first, double last){
  double n = (last-first)+1;
  return (n/2) * ((2*first) + ((n-1)*1) );
}

double left_walk(double start) {
  return 2*sumSeries(1, start);
}

double right_walk(double start, double end) {
  return 2*sumSeries(start, end);
}

// brute force approach: 
int main() {
   
  // mean = avg of first and last term
  // (remembering to exclude the term representing the woman's own home
  
  int numbers = 0;
  double end = 8;
  double home = 1;

  while (numbers < 9){

    for (home = 1; home < end; home += 1.0) {
        
      if (left_walk(home-1) == right_walk(home+1, end)){

        std::cout << home << "   " << end << "\n";
        numbers++;
        break;
      }
    }

    end += 1;
  }  
  
}

