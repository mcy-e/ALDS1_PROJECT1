#include<stdbool.h>


#ifndef NUMBERS_H
#define NUMBERS_H
int sumOfDigits(int num);
int reverseNumber(int num);
bool isPalindrome(int num);

bool isPrime(int num);

int gcd(int a,int b);

int Max(int a,int b);

int lcm(int a,int b);

unsigned long long int factorial(int num);

bool isEven(int num);

void primeFactors(int num);

bool isArmstrong(int num);

unsigned long long int fibonacci(int num);

int numberOfDivisors(int num);

int reverse_negative(int num , bool check);

bool isNegative(int num);

bool isDivisor(int num,int divisor);

int sumDivisors(int num);

bool isPerfect(int num);
bool isMagic(int num);

int numberOfDigits(int num);

#endif