#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include"../include/numbers.h"

//& MAKE SURE TO INSTALL BETTER COMMENTS EXTENSION IF YOU ARE IN VS CODE FOR BETTER READABILITY 

//!Basic Functions
int sumOfDigits(int num){

 
  int sum=0,digit; //*declare variables //*initialize sum of digits
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  
  /*if (num < 0)
  {
    num =-num;
    check = 1; //*need it in order to return with negative value
  }*/
  
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

bool isOdd(int num){
  if(isEven(num)) return false;//*is even 
  else return true;//*is odd
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
    return fibonacci(num-1)+fibonacci(num -2);//*recursion function retrun to calculate previous function until it hits 0 1 which has 1 ,1
  }else{
    return 1;
  }
}

int numberOfDivisors(int num){
  int divisor,num_divisors=0;
  //*to expand it to even negative integers
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);
  
 for ( divisor = 1; divisor<= num ; divisor++)
 {
   if (num%divisor==0)//*the integer is a divisor
   {
     num_divisors++;//*so we a have a divisor
   }
  }
 
  return num_divisors;


}
bool isNegative(int num){
  if (num>0)
  {
    return false; //* num is positive
  }else{
    return true;//* num is negative
  }
  
}

int reverse_negative(int num , bool check){
  
  if (check)//*true when the num is negative we get it using the isNegative function
  {
    return num = num*-1;//*make the number positive to make it easier to deal with conditions
  }else{
    return num;//*don't change nothing
  }
  
}

bool isDivisor(int num,int divisor){
  //*modularity purposes what pushed me to make this function
  if (num%divisor==0){
    return true;
    
  } else{return false;}
}
int sumDivisors_out_num(int num){
  //*calculate the sum of the divisors without the number itself used in cases to find a type of numbers like perfect numbers
  
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);//*to make it work with negatives

  int sum = sumDivisors(num);
  sum = sum -num; //*remove the num from the sum
  
  return reverse_negative(sum, check);//*returns the sum of the divisors negative in case of negative numbers or positive in case of positive numbers



}

int sumDivisors(int num){
  //*calculate the sum of the divisors with the number itself 
  int sum = 0,divisor;

  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);//*to make it work with negatives

  for ( divisor= 1; divisor <= num; divisor++)
  {
    if (isDivisor(num,divisor))
    {//*when I find the divisor I add it to the sum
      sum = sum +divisor;
    }
    
  }
  
  return reverse_negative(sum, check);//*returns the sum of the divisors negative in case of negative numbers or positive in case of positive numbers



}

bool isPerfect(int num){
  int i,sum = 0;
  bool check;
  check = isNegative(num);//*to extended from natural number to integers
  num =reverse_negative(num, check);
 /* for ( i = 1; i <= num/2; i++)
 {
   if (isDivisor(num,i))
    {
     sum= i+sum;   
   }
        
  }*/
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
  num =reverse_negative(num, check);//*extend it from natural number to integers
  num_digits=numberOfDigits(num);//*to make a 'for' loop that iterates number of known times
  for ( i = 0; i < num_digits; i++)
  {
    temp = 0;//*temp to calculate the sum of digits then use it to divide it into digits and asign their sum to the num  
    for (j = 0; j < num_digits; j++)
    {
      
      digit = num%10;
      num = num/10;
      temp = temp +digit;
    }
    
    num =0;
    for ( k = 0; k < num_digits; k++){//*i don't really know why i did it to iterates until the number of digits but i had a remark that 
    //* in worst cases like if the num contains.. 999 if we add them we will get 2 digit number and so one so every number when we add its
    //*digits we will get a number that has number of digits -1 yeah like i can make it in the two loops (num_digits -i) but
    //* i don't really want to change it this is my method wether it's the best or not but at least it work 
    //* they say 'if it works leave it working'
      
      digit = temp%10;
      temp = temp / 10;
      num = num +digit;

    }

    if (temp <=9&&num<=9)//*stop the loop when both of them is smaller then or equal  9 because that's it decimal digits alone can't depace 10 
    {
      break;//*we perform break to exit the loop
    }
    
   
  }
  if (temp == 1 || num == 1)
  {
    return true;//* one of them is one means the when the number of digits add it together we eventually get 1
  }else{return false;}
  
  

}

int numberOfDigits(int num){
  int number_digits = 0,verify =1;
  bool check;
  check = isNegative(num);//* to extand it to integers
  num = reverse_negative(num,check);//*reverse the sign
  if (num == 0)
  {
    return 1;//*special case
  }
  
 while (num>=verify)
 {
   verify = verify*10;//*imagin it as log10 function but takes only the integer part of a the log10(x)
   number_digits++;
   
 }
 
 
  return number_digits;

}

bool isAutomorphic(int num){
  int square_num,digits,digits_num,power;
  bool check;
  check = isNegative(num);
  num = reverse_negative(num,check);//*extand it to integers
  digits_num = numberOfDigits(num); //*calculate the number of digits
  square_num = num*num;//*calculate the square
  
  power = pow(10,digits_num);//*i created it because i dont know why pow function doesn't work with modulo 
  
  digits=square_num%power;//*find the last digits of the square number according to the number of digits ofvthe number
  if (num == digits)//*compare in order to see if it holds
  {
    return true;
  }else{
    return false;
  }
  
  


}

//!Advanced Functions

void toBinary(int num){
  //! you may see that i overcomplicated it and i can simplify it using functions which what i will do someday...
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
    //?great news i did it
    int num_digit1 = numberOfDigits(binary_num);

    while (binary_num>0)//*we switch 0 by 1 and 1 by 0
    {
      binary_digit =binary_num%10;
      if (binary_digit == 1)
      {
        binary_digit =0;//*1 by 0
         
      }else{
       binary_digit =1;//*0 by 1
      }
     
     negative_binary = negative_binary + binary_digit*pow(10,pos2);//*we add it to previous digits on it's same position
      binary_num=binary_num/10;//*decrease the binary number

      pos2 ++;
      

    }
    negative_binary = negative_binary +1;//*two complement's method
    
    int carry = 1;//*carry to perform addition
    
    int verification=0,temp=negative_binary,calc_var;//*some var used in the 2's complement method
    
    while ( verification==0)
    {
     
      binary_digit=temp%10;//*take the digit
     //* printf("binary digit : %d\n",binary_digit);
     //!above statement used to debug because of some problems
      if (binary_digit == 1||binary_digit == 0)
      {
        verification=1;//*exit the loop when the last digit isn't bigger than two
      }else{
        calc_var=negative_binary/pow(10,carry);//*was created because the division over multiplication will logically cancel
        //* each other which is forbidden when we want to take that 2 and replace it by 0
        negative_binary=calc_var*pow(10,carry) + pow(10,carry);//*here where we update our negative number by removing that two and replace it by 0
        //*printf("negative binary :%d \n",negative_binary);
        //!above statement used to debug because of some problems
      }
      temp = negative_binary/pow(10,carry);//*decrease the temp variable to check the next digit
      //*printf("temp :%d\n",temp);
      //!above statement used to debug because of some problems
      carry++;//*to add the power of the carry like we add a carry in the n-th position
    }
    

    int num_digit2 = numberOfDigits(negative_binary);//*calculate the number of digits of that negative number (used below)
    
    printf("(-%d)10 = ",num); printf("(");//* i saw like it's a good way to display the conversion
    while (num_digit1 != num_digit2)//* a loop that adds  0 to the left until they have the same number of digits the negative number and the binary number 
    {
      printf("0");
      num_digit2++;
      //*0's are added because the 1's when are reversed on the left they wont count and they'll br ignored
      //*hope it's good explanation

    }
    printf("%d)2",negative_binary); 

    
    
    

  }
 



}

bool isNarcissistic(int num){
  //*The same as armstrong number (same approach different names )
  return isArmstrong(num);
}
 double sqrtApprox(int num,double approx){

//*it has  a default approx in the header file
double root1,root,root2,initial_guess;
initial_guess = num/2.0L;
root1 = (initial_guess+(num)/initial_guess)/2.0L;
root2 = (root1+(num)/root1)/2.0L;
//*to start the approximation i need at least two numbers the x1(root1) and x2(root2) 

while (fabs(root2-root1)>=approx/*the absolute value to get the distance (math say that's how you calculate distance) */)
{
  root1=(root2+(num)/root2)/2.0L;//*like it's root3 then in the 2nd iteration it's root5
  root2=(root1+(num)/root1)/2.0L;//*like it's root 4 then in the 2nd iteration it's root6
}




return root2;//*the last approximation

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
  }//*recursive function call 
  
}

bool isHappy(int num){
  int i,j,k,num_digits,digit,temp;
  bool check;
  check = isNegative(num);
  num =reverse_negative(num, check);//*to extend it over the negative numbers
  num_digits=numberOfDigits(num);//*calculate the number of digits
  for ( i = 0; i <= num_digits*num_digits; i++)//*the main loop iterates that number of time to ensure that on of temp or num are less than 10
  {//* it wont affect therun time because if one of the them get less than 10 it will break the loop
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
  
  //*it works like Magic number but we calculate the sum of square of its digits

}

bool isAbundant(int num){
  //*using the function that calculate the sum of divisors without the number (it will always be true ) and comparing with number 
  if (sumDivisors_out_num(num) > num )
  {
    return true;
  }else{return false;}
  
}
bool isDeficient(int num){
  if (!isAbundant(num))//*the complement of isAbundant so i will make it easy and link it with the above function
  {
    return true;
  }else{
    return false;
  }
  
}

unsigned long long int sumEvenFibonacci(int num){
  //*i can use the recursive function but i don't have time for debuging in case of some problems like i faced before (THIS IS THE TRUTH)
  int i,sum=0;
  for (i = 1; i <= num; i++){
    
    sum = fibonacci(3*i)+sum;//*the even fibonacci numbers are always the number that are divisible by three like 3,6,9,12,15...
  }
  
  return sum;


}

bool isHarshad(int num){
  if (num%sumOfDigits(num) == 0)//*the definition of a harshad number or niven number
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

void pascalPyramid(int row){
//! its maximum number is 66 so be careful playing with it...
  int k,nCr,space;

  printf("------------------------------------------------------------------------------\n");
  
  
    for ( int temp = 0; temp <=row; temp++)//*iterates unlit it gets to the row that i||you entered
    {
      
    
      
      printf("Row [%d]: ",temp);//*to make it look good on terminal
      space = row-1;//*space to make the pyramid shape such that it will renew every iteration because it changes below
      //* there is a better way using for loop but i didn't include it because i prefer my methods only \_(ツ)_/¯
      while (space >= temp)
      {
        printf(" ");//*spacing
        space--;
      }
    

    
     printf("[");//*a way to make it look decent
      for ( k = 0; k <= temp; k++)
      {
        nCr = nCk(temp,k);//*Modularity using other functions
        printf("%d",nCr);
        if (k!=temp)//*to separate the nck from each other
        {
         printf(",");
        }
    

      }
    
     printf("]\n");//* close the brackets and skip the line to the other row
    }
    printf("-------------------------------------------------------------------------------\n");

//! when debuging  i found a problem not in the code but in the numbers when it goes to row 10 the nck gets larger that make the list 
//!gets large which corrupt the pyramid shape i didn't find any helpful solution in c or i was blind to find a solution...
}

void pascalTriangle(int row){

 //*same like his older brother but prints perpendicular triangle shape
  int k,nCr;

  printf("------------------------------------------------------------------------------\n");
  
  
    for ( int temp = 0; temp <=row; temp++)//*iterates unlit it gets to the row that i||you entered
    {
      
    
      
      printf("Row [%d]: ",temp);//*to make it look good on terminal
      
    

    
     printf("[");//*a way to make it look decent
      for ( k = 0; k <= temp; k++)
      {
        nCr = nCk(temp,k);//*Modularity using other functions
        printf("%d",nCr);
        if (k!=temp)//*to separate the nck from each other
        {
         printf(",");
        }
    

      }
    
     printf("]\n");//* close the brackets and skip the line to the other row
    }
    printf("-------------------------------------------------------------------------------\n");

}
    

void pascalTriangleRow(int row){
  int k,nCr,space;
//*same like his older brother but prints only the row in case you just want the row
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
  return factorial(num)/(factorial(k)*factorial(num-k));//*it's like factorial so i used its mathematical defintion
}

unsigned long long bellNumber(int num){
  unsigned long long  bell=0;
  if (num>1){
    for ( int k = 0; k < num; k++)
    {
      bell =bellNumber(k)*nCk(num-1,k) +bell;//*the relation between the previous bell number (recursive relation ) 
      //*it's a sum that's why we added the previous calc of bell 
    }
   return bell; 
  }
  if (num ==1 || num == 0)
  {
    return 1;//*base case (starting point)
  }
  
}

bool isKaprekar(int num){
  int num1,sum;
  int square_num=num*num;
  int num_digits = numberOfDigits(square_num);//*calculate the number of digits need it in the procedure
  divideNumDigits(&square_num,num_digits,&num1);//* & is used to give the memory address of those vars to the procedure so that it can return the changed results in the same address 
  sum = num1 +square_num;//* calculate the sum (the 3rd step)
  if (sum == num)//*compare
  {
    return true;
  }else{
    return false;
  }

}


void divideNumDigits(int *num,int num_digits,int *num1){
  int Power;
  
  if (isEven(num_digits))//*to divide it evenly i.e equally
  {
    Power = pow(10,num_digits/2); 
    *num1 = *num%Power;
    *num= *num/Power;
    

  }else{//*give the priority the number from the right
    Power = pow(10,(num_digits+1)/2);
    *num1 = *num%Power;
    *num= *num/Power;
    
  }
  
}

bool isSmith(int num){
  if (isPrime(num))
  {//*exclude prime numbers because the don't have prime factors
    return false;
  }else{
    int sum_digits = sumOfDigits(num);//*calculate the sum of digits of the number
    int sum_PrimeFactors = sumOfDigits(primeFactorsSum(num));//*calculate the sum of digits of the prime factors of the number like 10 calculate the function will calc 2+5
    if (sum_digits == sum_PrimeFactors)//*compare
    {
      return true;//*result
    }else{
      return false;
    }
    

  }
  
}
int primeFactorsSum(int num){//*i know the name is bad but i want to avoid the "_" to make it easy to write although it will be auto completed if you're using vs code
  int i,j,factor=0;
  for ( i =2; i <=num; i++)
  {
    if (isPrime(i))
    {
      while (num % i == 0)//*when i divides more than one times the num
      {
        
        num = num / i;//*to reduce the num for efficient and fast operation
        factor = factor*10 +i;//*the sum of the factors 
      } 
    } 
  }
  return factor;
}

int sumOfPrimes(int num){
  int sum=0;
  for (int  i = 2; i <= num; i++)
  {
    if (isPrime(i))//*check if it's prime
    {
      sum = sum+i;//*if tru it will be added to the sum 
    }
    
  }
  
  return sum;
}


