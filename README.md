# Amicable-Pairs
Program to find all the amicable pairs in the first 100M numbers

Amicable numbers are two different numbers so related that the sum of the proper divisors of each is equal to the other number.
The smallest pair of amicable numbers is (220, 284). They are amicable because the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110, of which the sum is 284; and the proper divisors of 284 are 1, 2, 4, 71 and 142, of which the sum is 220.

The goal was to find all such amicable pairs with a runtime of less than 45 seconds. 

Steps to run the program:-
1. cd amicable-pairs
2. g++ -std=c++11 amicable.cpp amicabletest.cpp -o amicablepairs
3. ./amicablepairs
