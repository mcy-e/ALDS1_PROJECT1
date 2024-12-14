#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include"numbers.h"

//!Basic Functions
int sumOfDigits(int num){

 
  int sum=0,digit; //*declare variables //*initialize sum of digits
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  
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
 
  sum = reverse_negative(sum, check);

 return sum;
}

int reverseNumber(int num){

  int reverse_num=0;
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  

  while (num > 0){
    reverse_num = reverse_num * 10 + num % 10;//*efficient way rather than m=num%10 then reverse_num =reversenum*10 + m 
    num = num / 10;
  }
  
 reverse_num= reverse_negative(reverse_num,check);


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

unsigned long long  factorial(int num){

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

//!Intermediate Functions
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
  int digit_num=0,digit,sum =0,temp = num,i;
 
  if (num <0)
  {
    return false;//*negative numbers are not armstrong numbers
  }else{
    
    digit_num = numberOfDigits(num);
    for ( i = 1; i <= digit_num; i++)
    {
      digit = temp%10;
      sum = sum + pow(digit, digit_num);//*pow function is used to get the power of a number we can't use ^ ....
      temp= temp / 10;

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
  if (num>2){
    return fibonacci(num-1)+fibonacci(num -2);
  }else{
    return 1;
  }
}

int numberOfDivisors(int num){
  int divisor,num_divisors=0;
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  
 for ( divisor = 1; divisor<= num ; divisor++)
 {
   if (num%divisor==0)
   {
     num_divisors++;
   }
  }
 
  return num_divisors;


}
bool isNegative(int num){
  if (num>0)
  {
    return false;
  }else{
    return true;
  }
  
}

int reverse_negative(int num , bool check){
  
  if (check)
  {
    return num = num*-1;
  }else{
    return num = num;
  }
  
}

bool isDivisor(int num,int divisor){
  if (num%divisor==0){
    return true;
    
  } else{return false;}
}
int sumDivisors_out_num(int num){
  int sum = 0,divisor;

  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);

  for ( divisor= 1; divisor < num; divisor++)
  {
    if (isDivisor(num,divisor))
    {
      sum = sum +divisor;
    }
    
  }
  
  return reverse_negative(sum, check);



}

int sumDivisors(int num){
  int sum = 0,divisor;

  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);

  for ( divisor= 1; divisor <= num; divisor++)
  {
    if (isDivisor(num,divisor))
    {
      sum = sum +divisor;
    }
    
  }
  
  return reverse_negative(sum, check);



}

bool isPerfect(int num){
  int i,sum = 0;
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  for ( i = 1; i <= num/2; i++)
 {
   if (isDivisor(num,i))
    {
     sum= i+sum;   
   }
        
  }
    
  if (num == sum)
  {
    return true;

  }else{
    return false;
  }
  

}

bool isMagic(int num){
  int i,j,k,num_digits,digit,temp;
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  num_digits=numberOfDigits(num);
  for ( i = 0; i < num_digits; i++)
  {
    temp = 0;
    for (j = 0; j < num_digits; j++)
    {
      
      digit = num%10;
      num = num/10;
      temp = temp +digit;
    }
    
    num =0;
    for ( k = 0; k < num_digits; k++){
      
      digit = temp%10;
      temp = temp / 10;
      num = num +digit;

    }

    if (temp <=9&&num<=9)
    {
      break;
    }
    
   
  }
  if (temp == 1 || num == 1)
  {
    return true;
  }else{return false;}
  
  

}

int numberOfDigits(int num){
  int number_digits = 0,verify =1;
  bool check;
  check = isNegative(num);
  num = reverse_negative(num,check);
  if (num == 0)
  {
    return 1;
  }
  
 while (num>=verify)
 {
   verify = verify*10;
   number_digits++;
   
 }
 
 
  return number_digits;

}

bool isAutomorphic(int num){
  int square_num,digits,digits_num,power;
  bool check;
  check = isNegative(num);
  num = reverse_negative(num,check);
  digits_num = numberOfDigits(num); 
  square_num = num*num;
  
  power = pow(10,digits_num);
  
  digits=square_num%power;
  if (num == digits)
  {
    return true;
  }else{
    return false;
  }
  
  


}

//!Advanced Functions

void toBinary(int num){
 int binary_digit,binary_num=0,pos =0,negative_binary=0;
 bool check;
 check = isNegative(num);
 num = reverse_negative(num,check);///*To extand it
 int temp=num;//*used to make print statement good

  

 while (temp>0)
 {//*converting the number to its equivalent binary with taking in mind that every binary digit that construct a number we can consider it as a decimal digit (they won't add together)
  binary_digit = temp%2;
  temp = temp/2;
  binary_num = binary_num + binary_digit*pow(10,pos);
  pos++;
   
 }
 
 int pos2 = 0;
 if (!check){printf("(%d)10 =(%d)2",num,binary_num);//*case the number isn't negative
 }else{
    //*1's complement method
     //!(i may extend it to 2's complement method)
    int num_digit1 = numberOfDigits(binary_num);

    while (binary_num>0)
    {
      binary_digit =binary_num%10;
      if (binary_digit == 1)
      {
        binary_digit =0;
         
      }else{
       binary_digit =1;
      }
     
     negative_binary = negative_binary + binary_digit*pow(10,pos2);
      binary_num=binary_num/10;

      pos2 ++;
      

    }
    int num_digit2 = numberOfDigits(negative_binary);
    
    printf("(-%d)10 = ",num); printf("(");
    while (num_digit1 != num_digit2)
    {
      printf("0");
      num_digit2++;


    }
    printf("%d)2",negative_binary); 

    
    
    

  }
 



}

bool isNarcissistic(int num){
  //*The same as armstrong number (same approach different names )
  return isArmstrong(num);
}
 double sqrtApprox(int num,double approx){
//TODO expand to reel numbers
double root1,root,root2,initial_guess;
initial_guess = num/2.0L;
root1 = (initial_guess+(num)/initial_guess)/2.0L;
root2 = (root1+(num)/root1)/2.0L;


while (fabs(root2-root1)>=approx)
{
  root1=(root2+(num)/root2)/2.0L;
  root2=(root1+(num)/root1)/2.0L;
}




return root2;

}

double power(int base,int exp){
 /* int i,power=1;
  for ( i = 1; i <=exp; i++)
  {
    power=power*base;
  }
  return power;*/
  if (exp == 0)
  {
    return 1;
  }else{
    return power(base,exp-1)*base;
  }
  
}

bool isHappy(int num){
  int i,j,k,num_digits,digit,temp;
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  num_digits=numberOfDigits(num);
  for ( i = 0; i <= num_digits*num_digits; i++)
  {
    temp = 0;
    for (j = 0; j <num_digits; j++)
    {
      
      digit = num%10;
      num = num/10;
      temp = temp +(digit*digit);
    }
    
    num =0;
    for ( k = 0; k < num_digits; k++){
      
      digit = temp%10;
      temp = temp / 10;
      num = num +(digit*digit);

    }

    if (temp <=9&&num<=9)
    {
      break;
    }
    
   
  }
  if (temp == 1 || num == 1)
  {
    return true;
  }else{return false;}
  
  

}

bool isAbundant(int num){
  int sum ;
  sum = sumDivisors_out_num(num);
  if (sum > num )
  {
    return true;
  }else{return false;}
  
}
bool isDeficient(int num){
  if (!isAbundant(num))
  {
    return true;
  }else{
    return false;
  }
  
}

unsigned long long int sumEvenFibonacci(int num){
  
  int i,sum=0;
  for (i = 1; i <= num; i++){
    
    sum = fibonacci(3*i)+sum;
  }
  
  return sum;


}

bool isHarshad(int num){
  if (num%sumOfDigits(num) == 0)
  {
    return true;
  }else{
    return false;
  }

}

unsigned long long  catalanNumber(int num){
if (num<0)
{
 return 0;//*Negative number....
}
else if (num >10){
  int d=2*(2*num -1);
  return (d*catalanNumber(num -1))/(num+1);//*but it still very limited when we go with large numbers in case of 30 we depaces the %llu range
}else{
  return factorial(2*num)/(factorial(num +1)*factorial(num)); 
  /* i noticed a problem where my number depaces ten i can't 
  calculate the n-th catalan so i used the recursion used below */
}

}

void pascalTriangle(int num){

  int k,nCr;
  printf("Row [%d] : [",num);
  for ( k = 0; k <= num; k++)
  {
    nCr = nCk(num,k);
    printf("%d",nCr);
    if (k!=num)
    {
      printf(",");
    }
    

  }
  
  printf("]");



}

unsigned long long nCk(int num,int k){
  return factorial(num)/(factorial(k)*factorial(num-k));
}

unsigned long long bellNumber(int num){
  unsigned long long  bell=0;
  if (num>1){
    for ( int k = 0; k < num; k++)
    {
      bell =bellNumber(k)*nCk(num-1,k) +bell;
    }
   return bell; 
  }
  if (num ==1 || num == 0)
  {
    return 1;
  }
  
}

bool isKaprekar(int num){
  int num1,sum;
  int square_num=num*num;
  int num_digits = numberOfDigits(square_num);
  divideNumDigits(&square_num,num_digits,&num1);
  sum = num1 +square_num;
  if (sum == num)
  {
    return true;
  }else{
    return false;
  }

}


void divideNumDigits(int *num,int num_digits,int *num1){
  int p1;
  
  if (isEven(num_digits))
  {
    p1 = pow(10,num_digits/2); 
    *num1 = *num%p1;
    *num= *num/p1;
    

  }else{
    p1 = pow(10,(num_digits+1)/2);
    *num1 = *num%p1;
    *num= *num/p1;
    
  }
  
}

bool isSmith(int num){
  if (isPrime(num))
  {
    return false;
  }else{
    int sum_digits = sumOfDigits(num);
    int sum_PrimeFactors = sumOfDigits(primefactors(num));
    if (sum_digits == sum_PrimeFactors)
    {
      return true;
    }else{
      return false;
    }
    

  }
  
}
int primefactors(int num){
  int i,j,factor=0;
  for ( i =2; i <=num; i++)
  {
    if (isPrime(i))
    {
      while (num % i == 0)//*when i divides more than one times the num
      {
        
        num = num / i;//*to reduce the num for efficient and fast operation
        factor = factor*10 +i;
      } 
    } 
  }
  return factor;
}

int sumOfPrimes(int num){
  int sum=0;
  for (int  i = 2; i <= num; i++)
  {
    if (isPrime(i))
    {
      sum = sum+i;
    }
    
  }
  
  return sum;
}


