/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: amicabletest.cpp

On linux:
g++ amicable.cpp amicabletest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test amicable object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "amicable.h"

/*----------------------------------------------------------------
initialization of static
-----------------------------------------------------------------*/
bool amicable::display = true;

/*----------------------------------------------------------------
Nothing can be changed in this file
DO Not use some weird formulas from internet
MUST solve from fundamentals.

Only knowledge required to solve this problem is to 
compute factor and resuse computed factors.
-----------------------------------------------------------------*/
int main() {
  clock_t start = clock();
  unsigned int n = 100000000;
  amicable a(n);
  clock_t end = clock();
  double d = double(end - start) / CLOCKS_PER_SEC;
  cout << "Run time for amicable for n = " << n << " is " << d << " secs" << endl;
  cout << "I will fail if you take more than 45 sec\n" ;
  return 0 ;
}

//EOF

