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

void compare_swap(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        
    }
    
}

//!Sorting Algorithms
void bubbleSort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        compare_swap(arr,size-i);
    }
    

}

void selectionSort(int arr[],int size){

    for (int i = size-1,pos=0; i >=0,pos<size ; i--,pos++)
    {
        int min=findMin(arr,size-pos);
        int minPos=findElementPos(arr,size-pos,min);
        int temp=arr[i];
        arr[i]=arr[minPos];
        arr[minPos]=temp;
    }
    
    reverseArray(arr,size);
}


void insertionSort(int arr[],int size){
   
   int j;
   for(int i=1;i<size;i++){
        int temp=arr[i];
        j=i-1;
        while (j>=0&&temp<arr[j])
        {
            arr[j+1]=arr[j];

            j--;
        }
        arr[j+1]=temp;
    }
   


}


void mergeSort(int arr[], int left, int right) {
    if (left < right - 1) {
        int midle = (left + right) / 2;
        int temp1[midle - left];
        int temp2[right - midle];

        for (int i = 0; i < midle - left; i++) {
            temp1[i] = arr[left + i];
        }
        for (int i = 0; i < right - midle; i++) {
            temp2[i] = arr[midle + i];
        }

        mergeSort(temp1, 0, midle - left);
        mergeSort(temp2, 0, right - midle);
        mergeSortedArray(temp1, temp2, midle - left, right - midle, arr + left);
    }
}

void mergeSortedArray(int arr1[], int arr2[], int arr_size1, int arr_size2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < arr_size1 && j < arr_size2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
            k = k + 1;
        } else {
            arr3[k] = arr2[j];
            j++;
            k = k + 1;
        }
    }
    while (i < arr_size1) {
        arr3[k] = arr1[i];
        i++;
        k = k + 1;
    }
    while (j < arr_size2) {
        arr3[k] = arr2[j];
        j++;
        k = k + 1;
    }
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int j = low;
        int i;
        
        for (i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                swap(&arr[i], &arr[j]);
                j++;
            }
        }
        
        swap(&arr[j], &arr[high]);

      /*  printf("Pivot: %d | Array state: ", pivot);
        for (int k = low; k <= high; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
        */
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}



    




//!Advanced functions

bool isEmptyArray(int arr[],int size){
    if (size==0) return true;
    return false;
    
}
void swap(int* elem1,int* elem2){
    int temp;
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
int findMissingNumber(int arr[], int size){
    quickSort(arr,0,size);
    for (int i = 0; i < size; i++)
    {
        if (arr[i+1]-arr[i]==1)
        {
            continue;
        }else{
            return arr[i]+1;
        }
        
        
    }
    return -1;
}

void findPairsWithSum(int arr[], int size, int sum){
    quickSort(arr,0,size-1);
    int i=0,j=size-1;bool verification=false;
    while(i<j){
        if(arr[i]+arr[j]==sum){
            printf("Pair found: %d and %d\n", arr[i], arr[j]);
            i++;
            j--;
            verification=true;

        } else if(arr[i]+arr[j]<sum){
            i++;
        } else{
            j--;
        }
    }
    if (!verification)
    {
        printf("Pairs not found \n");
    }
    
 
}

void findSubArrayWithSum(int arr[], int size, int sum){
    quickSort(arr,0,size-1);
    int delimiter=0;
    int check_sum= sumArray(arr,size);
    bool verification=false;
    for (int i = 0; i < size; i++)
    {
        if (check_sum==sum)
        {
            printf("Sub Array found: \n"); 
            reverseArray(arr,size);
            quickSort(arr,i,size);
            printArray(arr+delimiter,size-delimiter);
            verification=true;
        }if (check_sum>sum)
        {
            delimiter++;
            check_sum=sumArray(arr,size-delimiter);
                
        }else{
            delimiter++;
            check_sum=sumArray(arr+delimiter,size);
        }
            
               
        
        
    }
    if (!verification)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i]==sum)
            {
                printf("Sub Array found: \n");
                printf("Array[%d]=[%d",i+1,arr[i]);
                verification=true;
                printf("]\n");
            }
        
        }
    }
    if (!verification)
    {
        printf("No Subarray found");
    }
    
        
    
}

void rearrangeAlternatePositiveNegative(int arr[], int size){
    quickSort(arr,0,size-1);
    int temp1[size];
    int rearrangedArray[size];
    int startOfPositive=0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]<=0)
        {
            temp1[startOfPositive]=arr[i];
            startOfPositive++;

        }else{break;}
        
    }
    reverseArray(temp1,startOfPositive);
    int j=0;
    
    for (int i = 0; i < size; i+=2)
    {
        rearrangedArray[i]=temp1[j];
        rearrangedArray[i+1]=arr[startOfPositive];
        j++;
        startOfPositive++;
    }
    printArray(rearrangedArray,size);
    
    
}

int findMajorityElement(int arr[], int size){
    quickSort(arr,0,size-1);
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j]) count++;
        }
        if (count > size / 2)return arr[i];
    }
    return 0;
}

int longestIncreasingSubsequence(int arr[], int size){
    int dp[size];
    for (int i = 0; i < size; i++)
    {
        dp[i]=1;
    }
    
    for (int i = 1; i < size; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] >= arr[j])
            {
                dp[i] =Max(dp[i],dp[j]+1);
            }
        }
    }
    
   return findMax(dp,size); 
}

void findDuplicates(int arr[], int size){
    quickSort(arr,0,size);
    int count;
   for (int j = 0; j < size; j=j+count+1)
   {
        count=0;
        bool verification=false;
        for (int i = j; i < size; i++)
        {
            if (arr[i]==arr[i+1])
            {
                count++;
                verification=true;
            }else{break;}
        
        }
        if (verification) printf("The Element %d has a duplicate \n",arr[j]);
     





    }
   
    
    
}


void findIntersection(int arr1[], int size1, int arr2[], int size2){
    quickSort(arr1,0,size1);
    quickSort(arr2,0,size2);
    
    int IntersectionArr[size1+size2];
    int count=0;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i]==arr2[j])
            {
                IntersectionArr[count]=arr1[i];
                count++;
            }
            
        }
        
    }
    quickSort(IntersectionArr,0,count-1);
    int new_size=0;
    int newArr[count];
    for (int i = 0; i < count; i++)
    {
        if (i == 0 || IntersectionArr[i] != IntersectionArr[i - 1])
        {
           newArr[new_size]=IntersectionArr[i];
           new_size++;
        }
    }

    printArray(newArr,new_size);
    
}

void findUnion(int arr1[], int size1, int arr2[], int size2){
    int UnionArr[size1+size2];
    int count=0;
    for (int i = 0; i < size1; i++)
    {
        UnionArr[count]=arr1[i];
        count++;
    }
    for (int j = 0; j < size2; j++)
    {
        UnionArr[count]=arr2[j];
        count++;
    }
    quickSort(UnionArr,0,count-1);
    int new_size=0;
    int newArr[count];
    for (int i = 0; i < count; i++)
    {
        if (i == 0 || UnionArr[i] != UnionArr[i - 1])
        {
           newArr[new_size]=UnionArr[i];
           new_size++;
        }
    }
    printArray(newArr,new_size);
}


