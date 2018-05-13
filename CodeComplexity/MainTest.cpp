/*
Complexity Lesson

You are expected to run main function in this lesson multiple times, 
for each function,play around with multiple inputs,Form random large samples of data,
note down timings and report them in forum .We hope you learn in correct way. 
This is the reason we allocated 10 days for this lesson

How to do this lesson.
This lesson is not about passing testcases and submitting, Its about learning how to measure your code
how to find compelxity of your code etc. So dont just finish lesson asap, just by passing testcases,
Spend atleast 1-2 hours on each question finiding complexity,measuring time etc.

1st Activity is TimeComplexity.cpp where you will be given 10-15 code samples, you need to find out what each code
complexity is.

2) In PrimeNumber Testing you will write code in multiple ways to find whether a number is prime or not
and note down the performance measurements.

The same thing you will do for other questions as well Search,TwoSum,NPrime etc. 

Solve questions in this order TimeComplexity,PrimeNumber,Search,TwoSum,NPrime.

For each question there will be a observations comment box at top, fill it with your timings etc.

The test cases are timed for optimized functions, if you get timeout exception ,you really need to think and optimize your code.

Note :
If you give largeinputs to a bruteforce function it takes lot of time to execute. Think and Test.

We are expecting timings like this for a sample question:

Way1 : BruteForce :
100 loopCount, 1000 Elements. Time took : 50 seconds

Way 2: Optimized :
1000 loopCount, 1000 Elements : Time took : 3seconds.

Helpful Links : (Go through these before starting lesson, Copy Paste links)
•https://www.youtube.com/watch?v=PFd5s0bHgAQ
•https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/tutorial/
•http://discrete.gr/complexity/
•Robert Sedgewick's Algorithms(4th edition)

Author: Abhijith Ravuri & SVSRK Praveen
*/


#include <stdio.h>
#include "FunctionHeaders.h"
#include <iostream>
#include <time.h>

void measurePrimeNumberCheckingBruteForce();
void measurePrimeNumberCheckingSquareRoot();
void measurePrimeNumberCheckingOptimized();

int main(){

	//printf("Prime checking for 9 should return 0, Got %d\n", isPrimeOptimized(9));

	printf("Running your code, it might take some time to finish...\n");


	//Prime Check sample code
	measurePrimeNumberCheckingBruteForce();
	measurePrimeNumberCheckingSquareRoot();
	//measurePrimeNumberCheckingOptimized();
	
	//Do similar observations for Search
	/*
		See and understand how timing code is written for prime functions and write the same.
		You need to start time before calling searchFunction and then end time after calling.
		You wont notice much difference between linear search and binary search if you do it for small arrays
		Do it fo either very large array (100,0000 elements) or do it 10000 times for 10000elements. 
		Check Search_Test3.
		(Same which we did for prime)
	*/

	//Do similar observations for 2Sum

	//Do similar observations for nPrime.
	
}

void measurePrimeNumberCheckingBruteForce() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	int numberOfTimes = 5;
	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		//The below number 232910011 is a prime number.
		int primeCheck = isPrimeBruteForce(232910011);
		if (primeCheck == 0) {
			printf("You are returning a wrong answer for brute force prime checking\n");
			break;
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in bruteForce\n", numberOfTimes, cpu_time_used);
}

void measurePrimeNumberCheckingSquareRoot() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	//You can increase or decrease it to fully understand the effect.
	int numberOfTimes = 10000;
	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		//The below number 232910011 is a prime number.
		int primeCheck = isPrimeSquareRoot(232910011);
		if (primeCheck == 0) {
			printf("You are returning a wrong answer for is prime square root checking\n");
			break;
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in square root way\n", numberOfTimes, cpu_time_used);
}

void measurePrimeNumberCheckingOptimized() {
	clock_t start, end;
	double cpu_time_used;
	//we are running multiple times just to understand the effect of time complexity.(Good vs Bad)
	int numberOfTimes = 1000;
	start = clock();
	for (int i = 0; i < numberOfTimes; i++){
		//The below number 232910011 is a prime number.
		int primeCheck = isPrimeOptimized(232910011);
		if (primeCheck == 0) {
			printf("You are returning a wrong answer for is prime optimized checking\n");
			break;
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("For %d times, Took %f seconds in square root way\n", numberOfTimes, cpu_time_used);
}