#include<stdbool.h>
#include<math.h>


#ifndef NUMBERS_H
#define NUMBERS_H

//!Basic Functions
int sumOfDigits(int num);
int reverseNumber(int num);
bool isPalindrome(int num);

bool isPrime(int num);

int gcd(int a,int b);

int Max(int a,int b);

int lcm(int a,int b);

unsigned long long  factorial(int num);

bool isEven(int num);

//!Intermediate Functions

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

//!Advanced Functions
void toBinary(int num);

bool isNarcissistic(int num);

 double sqrtApprox(int num,double approx);

#define sqrtApproxDefault(num) sqrtApprox(num,2.220446*pow(10,-16))//*Default approximation

double power(int base,int exp);

bool isHappy(int num);

bool isAbundant(int num);

bool isDeficient(int num);

unsigned long long int sumEvenFibonacci(int num);

bool isHarshad(int num);

unsigned long long catalanNumber(int num);

void pascalPyramid(int row);
void pascalTriangle(int num);

void pascalTriangleRow(int row);

unsigned long long nCk(int num,int k);

unsigned long long bellNumber(int num);

void divideNumDigits(int *num,int num_digits,int *num1);

bool isKaprekar(int num);

bool isSmith(int num);

int primeFactorsSum(int num);

int sumOfPrimes(int num);


#endif