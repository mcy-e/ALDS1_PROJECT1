#include<stdbool.h>
#include<math.h>


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

int sumDivisors_out_num(int num);

bool isPerfect(int num);
bool isMagic(int num);

int numberOfDigits(int num);

bool isAutomorphic(int num);

void toBinary(int num);

bool isNarcissistic(int num);

 double sqrtApprox(int num,double approx);

#define sqrtApproxDefault(num) sqrtApprox(num,2.220446*pow(10,-16))//*Default approximation

double power(int base,int exp);

bool isHappy(int num);

bool isAbundant(int num);

bool isDeficient(int num);

#endif