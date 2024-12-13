#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include"numbers.h"

int sumOfDigits(int num){

 
  int sum,digit,check; //*declare variables
  sum = 0;check=1;  //*initialize sum of digits

  if (num < 0)
  {
    num =-num;
    check = 1; //*need it in order to return with negative value
  }
    
 while (num > 0){
    //*the loop where we get the  digit add it to sum then moving upwards 
      digit = num % 10;//*get the digit
     sum = sum + digit;//*add it to sum
     num = num / 10;//*divide the num by 10 to reduce the number of digits
  }
 
  if (check == 1)
  {
    sum = -sum; //*if the number was negative then convert it back to negative
  }
  

 return sum;
}

int reverseNumber(int num){

  int reverse_num=0,check=0;
  if (num < 0){
    num = -num; //*if the number is negative then convert it to positive
    check=1; //*need it in order to return with negative value 
  }

  while (num > 0){
    reverse_num = reverse_num * 10 + num % 10;//*efficient way rather than m=num%10 then reverse_num =reversenum*10 + m 
    num = num / 10;
  }
  
  if (check == 1)
  {
    reverse_num = -reverse_num; //*if the number was negative then convert it back to negative
  }
  


  return reverse_num ;
}

bool isPalindrome(int num){

  bool check=false;
  int its_reverse = reverseNumber(num);//*Modularity using existing functions to make it fast and easy

  if (its_reverse == num )
  {
    check=true; //*if the reverse of num is equal to num then it is a palindrome
  }

  return check;
}

bool isPrime(int num){


  int i;
  bool check=true;
  for ( i = 2; i <= sqrt(num); i++)
  {
    if (num % i == 0)
    {
      check=false; //*if the num is divisible by any number from 2 to sqrt(num) then it is not a prime number 
      break;//! the break is because we find a divisor so we don't need to complete checking 
    }
  }
  



  return check;
}

int gcd(int a,int b){
  int i,gcd;
  gcd=1;
  for (i = 2; i <= Max(a,b); i++){
    if (a%i ==0 && b%i == 0)
    {
      return gcd=i;//*updates until it gets to the lasts one 
    }else{
      return gcd;//*means there is no common divisor
    }
    

  }

  
}


int Max(int a,int b){
  if (a>b)
  {
    return a;//* max(a,b) = a
  }else{
    return b;//* max(a,b)=b
  }
}

int lcm(int a ,int b){

  return (a*b)/gcd(a,b);//*by applying the mathematical formula
}

unsigned long long int factorial(int num){

  if (num < 0)
  {
    return 0; //* factorial of negative number is undefined
  }else if (num>1){ 
  return factorial(num - 1)*num;
  }//*recursive function
  else
  {
    return 1;//* case of 0 and 1 
  }
  /*
  
  
  
  */
  
  
}

bool isEven(int num){
  if (num % 2 == 0){
    return true; //* if the number is devisable by 2 then it's even
  }else{
    return false; //* if the number is not devisable by 2 then it's odd
  }
  

  
}

void primeFactors(int num){
  int i,j=num;//*j is to store the value of num because its changes every time
  printf("%d =", num);
  for ( i =2; i < j; i++)
  {
    if (isPrime(i))
    {
      while (num % i == 0)//*when i divides more than one times the num
      {
        printf("%d",i);
        num = num / i;//*to reduce the num for efficient and fast operation
        if (num != 1)
        {
         printf("x");//* a good way to make the printed result look better
        }
      } 
    } 
  }
  

}

bool isArmstrong(int num){
  int digit_num=0,digit,sum =0,log=1,i,num1;
 
  if (num <0)
  {
    return false;//*negative numbers are not armstrong numbers
  }else{
    num1 = num;
    while (log < num)
    {
      log = log * 10;
      digit_num++;
    }
    for ( i = 1; i <= digit_num; i++)
    {
      digit = num1%10;
      sum = sum + pow(digit, digit_num);//*pow function is used to get the power of a number we can't use ^ ....
      num1 = num1 / 10;

    }
    if (sum == num)
    {
      return true; //*if the sum of the digits raised to the power of the number of digits is equal to the original number then it's an Armstrong number
    }else{
      return false; //*if the sum of the digits raised to the power of the number of digits is not equal to the original number then it's not an Armstrong number
    }
    
  }

}

unsigned long long int fibonacci(int num){
  if (num>1){
    return fibonacci(num-1)+fibonacci(num -2);
  }else{
    return 1;
  }
}

