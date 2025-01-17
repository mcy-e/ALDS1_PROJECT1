#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include"../include/numbers.h"




int sumOfDigits(int num){

 
  int sum=0,digit; 
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  
  
  
 while (num > 0){
    
      digit = num % 10;
     sum = sum + digit;
     num = num / 10;
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
    reverse_num = reverse_num * 10 + num % 10;
    num = num / 10;
  }
  
 reverse_num= reverse_negative(reverse_num,check);


  return reverse_num ;
}

bool isPalindrome(int num){

  bool check=false;
  int its_reverse = reverseNumber(num);

  if (its_reverse == num )
  {
    check=true; 
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
      check=false; 
      break;
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
      return gcd=i;
    }else{
      return gcd;
    }
    

  }

  
}


int Max(int a,int b){
  if (a>b)
  {
    return a;
  }else{
    return b;
  }
}

int lcm(int a ,int b){

  return (a*b)/gcd(a,b);
}

unsigned long long  factorial(int num){

  if (num < 0)
  {
    return 0; 
  }else if (num>1){ 
  return factorial(num - 1)*num;
  }
  else
  {
    return 1;
  }
  
  
  
}

bool isEven(int num){
  if (num % 2 == 0){
    return true; 
  }else{
    return false; 
  }
  

  
}


void primeFactors(int num){
  int i,j=num;
  printf("%d =", num);
  for ( i =2; i < j; i++)
  {
    if (isPrime(i))
    {
      while (num % i == 0)
      {
        printf("%d",i);
        num = num / i;
        if (num != 1)
        {
         printf("x");
        }
      } 
    } 
  }
  

}

bool isArmstrong(int num){
  int digit_num=0,digit,sum =0,temp = num,i;
 
  if (num <0)
  {
    return false;
  }else{
    
    digit_num = numberOfDigits(num);
    for ( i = 1; i <= digit_num; i++)
    {
      digit = temp%10;
      sum = sum + pow(digit, digit_num);
      temp= temp / 10;

    }
    if (sum == num)
    {
      return true; 
    }else{
      return false; 
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
    return num;
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
 
 sum = sumDivisors_out_num(num);
    
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



void toBinary(int num){
  
 int binary_digit,binary_num=0,pos =0,negative_binary=0;
 bool check;
 check = isNegative(num);
 num = reverse_negative(num,check);
 int temp=num;

  

 while (temp>0)
 {
  binary_digit = temp%2;
  temp = temp/2;
  binary_num = binary_num + binary_digit*pow(10,pos);
  pos++;
   
 }
 
 int pos2 = 0;
 if (!check){printf("(%d)10 =(%d)2",num,binary_num);
 }else{
    
    
    
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
    negative_binary = negative_binary +1;
    
    int carry = 1;
    
    int verification=0,temp= negative_binary,calc_var;
    
    while ( verification==0)
    {
     
      binary_digit=temp%10;
     
     
      if (binary_digit == 1||binary_digit == 0)
      {
        verification=1;
      }else{
        calc_var=negative_binary/pow(10,carry);
        
        negative_binary=calc_var*pow(10,carry) + pow(10,carry);
        
        
      }
      temp = negative_binary/pow(10,carry);
      
      
      carry++;
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
  
  return isArmstrong(num);
}
 double sqrtApprox(int num,double approx){


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
  
  if (sumDivisors_out_num(num) > num )
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
 return 0;
}
else if (num >10){
  int d=2*(2*num -1);
  return (d*catalanNumber(num -1))/(num+1);
}else{
  return factorial(2*num)/(factorial(num +1)*factorial(num)); 
  
}

}

void pascalPyramid(int row){

  int k,nCr,space;

  printf("------------------------------------------------------------------------------\n");
  
  
    for ( int temp = 0; temp <=row; temp++)
    {
      
    
      
      printf("Row [%d]: ",temp);
      space = row-1;
      
      while (space >= temp)
      {
        printf(" ");
        space--;
      }
    

    
     printf("[");
      for ( k = 0; k <= temp; k++)
      {
        nCr = nCk(temp,k);
        printf("%d",nCr);
        if (k!=temp)
        {
         printf(",");
        }
    

      }
    
     printf("]\n");
    }
    printf("-------------------------------------------------------------------------------\n");



}

void pascalTriangle(int row){

 
  int k,nCr;

  printf("------------------------------------------------------------------------------\n");
  
  
    for ( int temp = 0; temp <=row; temp++)
    {
      
    
      
      printf("Row [%d]: ",temp);
      
    

    
     printf("[");
      for ( k = 0; k <= temp; k++)
      {
        nCr = nCk(temp,k);
        printf("%d",nCr);
        if (k!=temp)
        {
         printf(",");
        }
    

      }
    
     printf("]\n");
    }
    printf("-------------------------------------------------------------------------------\n");

}
    

void pascalTriangleRow(int row){
  int k,nCr,space;

  printf("------------------------------------------------------------------------------\n");
  
  
    
    
      
    
      
   printf("Row [%d]: ",row);
    space = row-1;
    while (space >= row)
    {
      printf(" ");
      space--;
    }
    

    
    printf("[");
    for ( k = 0; k <= row; k++)
    {
      nCr = nCk(row,k);
      printf("%llu",nCr);
      if (k!=row)
      {
        printf(",");
      }
    

    }
    
    printf("]\n");
    
  printf("-------------------------------------------------------------------------------\n");
    



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
  int Power;
  
  if (isEven(num_digits))
  {
    Power = pow(10,num_digits/2); 
    *num1 = *num%Power;
    *num= *num/Power;
    

  }else{
    Power = pow(10,(num_digits+1)/2);
    *num1 = *num%Power;
    *num= *num/Power;
    
  }
  
}

bool isSmith(int num){
  if (isPrime(num))
  {
    return false;
  }else{
    int sum_digits = sumOfDigits(num);
    int sum_PrimeFactors = sumOfDigits(primeFactorsSum(num));
    if (sum_digits == sum_PrimeFactors)
    {
      return true;
    }else{
      return false;
    }
    

  }
  
}
int primeFactorsSum(int num){
  int i,j,factor=0;
  for ( i =2; i <=num; i++)
  {
    if (isPrime(i))
    {
      while (num % i == 0)
      {
        
        num = num / i;
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


