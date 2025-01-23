#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include "../lib/mainlib.h"
#include <string.h>
#define UNUSED INT_MIN 
#include<limits.h>
//& MAKE SURE TO INSTALL BETTER COMMENTS EXTENSION IF YOU ARE IN VS CODE FOR BETTER READABILITY 

//!Basic Functions

void initializeArray(int arr[], int size, int value){
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
    
}

void printArray(int arr[] ,int size){

    if (size == 0)
    {
        printf("Array is empty \n");
        
    }else 
    {
    
        printf(" Array =[");
        for (int i = 0; i < size; i++)
        {
            printf("%d",arr[i]);
            if (i+1 != size)
            {
                printf(",");
            }
        
        }
        printf("]\n");
   
    }
    

}

int findMax(int arr[], int size){
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
 
}

int findMin(int arr[], int size){
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
 
}

int sumArray(int arr[], int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}


double averageArray(int arr[], int size){
    return sumArray(arr, size)/(double)size;
}

void minimizedArray(int arr[], int size){
    for (int i = 0; i<size; i++)
    {   
        if (i==size-1)
        {
            break;
        }
        
        arr[i]=arr[i+1];
        
    }
    
}

bool isSorted(int arr[], int size){
    int min ;
    for (int i = 0; i < size; i++)
    {
        min = findMin(arr,size-i);
        
        if (arr[0]!=min)
        {
         return false;   
        }
        
        shift_right(arr,size,1);
    }
    return true;

    
}

void storingDigits(int arr[],int number){
    int i=0, digit;
    while (number > 0)
    {
        digit = number%10;
        arr[i]=digit;
        number=number/10;
        i++;
    }
    
}
void minimumValue(int arr[],int size,int *index,int pos)
{
    int min=arr[pos];
    for (int i = pos; i < size; i++)
    {
        if (min>=arr[i])
        {
            min=arr[i];
            *index=i;
        }
        
    }
    
}
void selectionSort(int arr[],int size){
    int temp=arr[0],index,pos=0;
    for (int i = 0; i < size; i++)
    {
        minimumValue(arr,size,&index,pos);
        arr[i]=arr[index];
        arr[index]=temp;
        temp=arr[i+1];   
        pos++;
    }
    
   
}

int returningDigits(int arr[] ,int size ){
    int number=0;
    for (int i = 0; i < size; i++)
    {
        int t=arr[i]*pow(10,i);
        number = number+ t;
    }
    return number;
}
void createArray(int arr [],int size){
    
    for (int i = 0; i <size; i++)
    {
        printf("Enter  element number %d \n",i);
        scanf("%d",&arr[i]);
        
    }
    
}

void swapArray(int arr[],int arr_size){
    int i,j,temp;
    for ( i = 0,j=arr_size-1; j>i; i++,j--)
    {   temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

    }
    
}
void mergeSortedArray(int arr1[],int arr2[],int arr_size1,int arr_size2,int arr3[]){
    int i=0,j=0,k=0,p=(arr_size1+arr_size2);
    while(k <= p)
    {
        
        
            if (arr1[i] <=arr2[j]){
                arr3[k] = arr1[i];
                k++;
                i++;
                
            }else{
                arr3[k] = arr2[j];
                k++;
                j++;
                
            }

        
        
        
    }
    

}


//!Intermediate functions

void reverseArray(int arr[],int size){
    for (int i = 0,j=size-1; i < size/2,j>=size/2; j--,i++)
    {
        int temp = arr[i];
        int temp1 = arr[j];
        arr[j] = temp;
        arr[i] = temp1;
    }
    
}

void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
            *evenCount+=1;
        }else{*oddCount+=1;}
        
    }
    
}

int secondLargest(int arr[], int size){
    int max=findMax(arr,size);
    int min=findMin(arr,size);
    int maxPos=findElementPos(arr,size,max);
    arr[maxPos] = min;
    return findMax(arr,size);
    
}

int findElementPos(int arr[], int size,int element){
    int pos=0;
    for (int i = 0; i < size; i++)
    {
        
        if (arr[i]==element) 
        {
            return pos;
        }
        pos++;
    }
    return -1;
    
}

bool found(int arr[], int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element) return true;
        
        
    }
    return false;
    
}
void elementFrequency(int arr[], int size){

    int check[size];
    for (int i = 0; i < size; i++)
    {
        int count=0;
        if (!found(check,size,arr[i]))
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i]==arr[j])
                {
                    count++;
                }
            
            }
            
        }
        
        
        
        if (!found(check,size,arr[i]))
        {
            printf("->The element %d has been found %d times \n",arr[i],count);
        
        
        }
        check[i] = arr[i];
    }
    
}

int removeDuplicatesElements(int arr[], int size){
    int new_size=0,check[size];
    for (int i = 0; i < size; i++)
    {
        
        
        if (!found(check,size,arr[i]))
        {     
           check[new_size]=arr[i];
           new_size++;
        }
            
        
        
        
    }
    
    
    return new_size;
    

}

int linearSearch(int arr[],int size,int target){
   for (int i = 0; i < size; i++)
    {
        if (arr[i]==target)
        {
            return i;
        }
        
    }
    return -1;
}

int binarySearch(int arr[],int size ,int target){
    int left=0,right=size-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if (arr[mid]==target)
        {
            return mid;
        } else if (arr[mid]<target)
        {
            left=mid+1;
        } else{
            right=mid-1;
        }
        
    }
    return -1;
}

void shift_left(int arr[],int arr_size,int repeat_times){
   int temp;
   for ( int j = 0; j < repeat_times; j++)
   {
     for (int i = arr_size-1; i >0 ; i--)
     {          
       temp= arr[i];
       arr[i]=arr[i-1];
        arr[i-1]=temp;  
     }
   }
}
void shift_right(int arr[],int arr_size,int repeat_times){
   int temp;
   for ( int j = 1; j <= repeat_times; j++)
   {
     for (int i = 0; i < arr_size-1; i++)
     {          
       temp= arr[i];
       arr[i]=arr[i+1];
        arr[i+1]=temp;  
     }
   }
}



