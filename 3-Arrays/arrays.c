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
        arr[i] = value;//*all array elements will equal the value it's obvious
    }
    
}

void printArray(int arr[] ,int size){

    if (size == 0)
    {
        printf("Array is empty \n");//*in case the array is empty
        
    }else 
    {
    
        printf(" Array =[");//*cool print statement
        for (int i = 0; i < size; i++)
        {
            printf("%d",arr[i]);//*print the element
            if (i+1 != size)
            {
                printf(",");//*spereate the elem with , excluding first and last elem
            }
        
        }
        printf("]\n");//*close the array
   
    }
    

}

int findMax(int arr[], int size){
    int max = arr[0];//*set it as max
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];//*we found another max than max itself :)
        }
    }
    return max;
 
}

int findMin(int arr[], int size){
    int min = arr[0];//*same approach as above
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
    int sum=0;//*to add on it
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];//*add the element to the sum like sum=arr[i]+sum
    }
    return sum;
}


double averageArray(int arr[], int size){
    return sumArray(arr, size)/(double)size;//*i wanted to make a function that calc the real and effective size of the array like calc the elements but in c i didn't find usefull method we're not using python here ... 
}

void minimizedArray(int arr[], int size){
    for (int i = 0; i<size; i++)
    {   
        if (i==size-1)
        {
            break;
        }
        
        arr[i]=arr[i+1];//*overwrite the first elem and discard it
        
    }
    
}

bool isSorted(int arr[], int size){
    int min ;
    for (int i = 0; i < size; i++)
    {
        min = findMin(arr,size-i);//*i wanted to do it with max and min sometime i will
        
        if (arr[0]!=min)
        {
         return false;   //*the first element isn't the min so isn't sorted
        }
        
        shift_right(arr,size,1);//*shift the array and find another min by decrementing the size
    }
    return true;//*complete checking

    
}

void storingDigits(int arr[],int number){
    int i=0, digit;
    while (number > 0)
    {
        digit = number%10;
        arr[i]=digit;//*store the number digits i know it's reversed but we can reverse the array and still work
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
            *index=i;//*get the minumum number pos from the array later i made one that get all of them 
        }
        
    }
    //*note this function was from an older project i implemented it because it's logic helps other function to perform
}


int returningDigits(int arr[] ,int size ){
    int number=0;
    for (int i = 0; i < size; i++)
    {
        int t=arr[i]*pow(10,i);//*retruns the number digits as a whole number
        number = number+ t;
    }
    return number;
}
void createArray(int arr [],int size){
    
    for (int i = 0; i <size; i++)
    {
        printf("Enter  element number %d \n",i);
        scanf("%d",&arr[i]);//*scan the eleemnt and store it in the array
        
    }
    
}

void swapArray(int arr[],int arr_size){
    int i,j,temp;
    for ( i = 0,j=arr_size-1; j>i; i++,j--)
    {   temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;//*it's more like reverse than swap but i don't want to change it's name since there  are some functions that depends on this before the reverse to perform actions 

    }
    
}

void mergeSortedArray(int arr1[], int arr2[], int arr_size1, int arr_size2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while (i < arr_size1 && j < arr_size2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;//*increment i to compare the next element with arr2[j]
            k++;//*increment k to move to next place for the next element
        } else {
            arr3[k] = arr2[j];
            j++;//*same talk as above
            k++;
        }
    }
    while (i < arr_size1) {
        arr3[k] = arr1[i];
        i++;//*the remaining  elements that are still not yet merged
        k++;
    }
    while (j < arr_size2) {
        arr3[k] = arr2[j];
        j++;//*same
        k++;
    }
}

//!Intermediate functions

void reverseArray(int arr[],int size){
    for (int i = 0,j=size-1; i < size/2,j>=size/2; j--,i++)
    {
        int temp = arr[i];//*store the first elem in first case
        int temp1 = arr[j];//*store the last elem
        arr[j] = temp;//*swap
        arr[i] = temp1;
    }//*repeat
    
}

void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
            *evenCount+=1;//*yeah we can count only even then subtract the size from the odd but what if i fill the array till size-2 the odd count will be false
        }else{*oddCount+=1;}
        
    }
    
}

int secondLargest(int arr[], int size){
    int max=findMax(arr,size);//*find the maximum element
    int min=findMin(arr,size);//*find the minumum
    int maxPos=findElementPos(arr,size,max);//*find it's postion the maximum
    arr[maxPos] = min;//*set it to be minumum
    return findMax(arr,size);//*now logically the second maximum is the max due to the max being replaced by min
    
}

int findElementPos(int arr[], int size,int element){
    
    for (int i = 0; i < size; i++)
    {
        
        if (arr[i]==element) 
        {
            return i;//*it's like linear search but with a different name
        }
        
    }
    return -1;//*found nothing alike
    
}

bool found(int arr[], int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element) return true;//*will perform a linear search
        
        
    }
    return false;//*not found
    
}
void elementFrequency(int arr[], int size){

    int check[size];//*to store prev checked element
    for (int i = 0; i < size; i++)
    {
        int count=0;
        if (!found(check,size,arr[i]))//*the element wasn't checked before
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i]==arr[j])
                {
                    count++;
                }
            
            }
            
        }
        
        
        
        if (!found(check,size,arr[i]))//*we can print
        {
            printf("->The element %d has been found %d times \n",arr[i],count);
        
        
        }
        check[i] = arr[i];//*add the elem to the array for future checks
    }
    
}

int removeDuplicatesElements(int arr[], int size){
    int new_size=0,check[size];
    for (int i = 0; i < size; i++)
    {
        
        
        if (!found(check,size,arr[i]))
        {     
           check[new_size]=arr[i];//*we add the element and decrement the new size we can also return the array without duplicates
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
            return i;//*who else doesn't know linear search
        }
        
    }
    return -1;
}

int binarySearch(int arr[],int size ,int target){
    int left=0,right=size-1;
    while(left<=right)
    {
        int mid=(left+right)/2;//*get the middle element in the array
        if (arr[mid]==target)
        {
            return mid;//*we got 'em
        } else if (arr[mid]<target)
        {
            left=mid+1;//*the target is bigger then the middle element we start new search from the middle +1 to the right like if arr[2] is less then the target we like start searching from 3 untill size-1 which is the right
        } else{
            right=mid-1;//*same principle as above but in reverse
        }
        
    }
    return -1;//*not found
}

void shift_left(int arr[],int arr_size,int repeat_times){
   int temp;//*temporay to store
   for ( int j = 0; j < repeat_times; j++)
   {
        for (int i = arr_size-1; i >0 ; i--)
        {          
            temp= arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;//*normal swap between adjacent elements  
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
            arr[i+1]=temp;  //*what to explain to my self this is obvious
        }
    }
}

void compare_swap(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i]>arr[i+1])//*compare adjacent element swap if one is bigger than the previous one
        {
            int temp=arr[i];
            arr[i]=arr[i+1];//*normal swap
            arr[i+1]=temp;
        }
        
    }
    
}

//!Sorting Algorithms
void bubbleSort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        compare_swap(arr,size-i);//*compare and swap until we have one element we decrement the size because when comparing and swaping we can ensure that the last  element is the max of the array size
    }
    

}

void selectionSort(int arr[],int size){

    for (int i = size-1,pos=0; i >=0,pos<size ; i--,pos++)
    {
        int min=findMin(arr,size-pos);//*find min
        int minPos=findElementPos(arr,size-pos,min);//*it's pos
        int temp=arr[i];
        arr[i]=arr[minPos];
        arr[minPos]=temp;//*swap
    }
    
    reverseArray(arr,size);//*we willl get it reversed becaue the minium  will be the last elemnt
    //*here is another version i thought about but let the other one i don't know why but just let it
    /*for (int i = 0; i <size; i++)
    {
        int min=findMin(arr+i,size);
        int minPos=findElementPos(arr+i,size,min);
        int temp=arr[i];
        arr[i]=arr[minPos];
        arr[minPos]=temp;
    }*/
    
   
}


void insertionSort(int arr[],int size){
   
   int j;
   for(int i=1;i<size;i++){
        int temp=arr[i];//*used to compare the arr[i]may get overwritten so we don't want to get sick
        j=i-1;//*we start before the elem
        while (j>=0&&temp<arr[j])
        {
            arr[j+1]=arr[j];//*while we found an elem bigger than arr[i] we pass the elem to it's neighbor

            j--;//*decrement j
            //*j>=0 is added to ensure that j don't go crazy
        }
        arr[j+1]=temp;//*like if we found nothing matching the arr[i]will still the same and if we found the place in between  will stay empty due to swaping
    }
   


}


void mergeSort(int arr[], int left, int right) {
    if (left < right - 1) {
        int midle = (left + right) / 2;//*get the middle elem index
        int temp1[midle - left];//*creat two arrays to store left side and other for the right side
        int temp2[right - midle];

        for (int i = 0; i < midle - left; i++) {
            temp1[i] = arr[left + i];//*fill the array i can use fill function but it looks appealing to me like this 
        }
        for (int i = 0; i < right - midle; i++) {
            temp2[i] = arr[midle + i];//*and i don't know fill function doesn't often get used but this it does i can't risk it
        }

        mergeSort(temp1, 0, midle - left);//*recursive call divide the  left array again into others left and right
        mergeSort(temp2, 0, right - midle);//*recursive call divide the  right array again into others left and right
        mergeSortedArray(temp1, temp2, midle - left, right - midle, arr + left);//*when complex division means the size of every generated array is 1
    }//*we can merge them we start by the first two arrays will get merged sorted and then the two others and those four will get merge sorted because they are sorted
}



void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];//*the nomination is globall and the chosen of the pivot is said to be the last is more efficient
        int j = low;
        int i;
        
        for (i = low; i < high; i++) {
            if (arr[i] <= pivot) {
                swap(&arr[i], &arr[j]);//*swap the elemnt that are less then our chosen pivot
                j++;
            }
        }
        
        swap(&arr[j], &arr[high]);//*swap the pivout with the postion of j because logically that's the pivot real postion
        quickSort(arr, low, j - 1);//*recursive call
        quickSort(arr, j + 1, high);//*the pivot is in place now we imagine those are new arrays and start again
    }
}



    




//!Advanced functions

bool isEmptyArray(int arr[],int size){
    if (size==0) return true;
    return false;//*nothing to say
    
}
void swap(int* elem1,int* elem2){
    int temp;//*normal swaping 
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
int findMissingNumber(int arr[], int size){
    quickSort(arr,0,size-1);//*we sort and now i see the benefit of modularity 
    for (int i = 0; i < size; i++)
    {
        if (arr[i+1]-arr[i]==1)
        {
            continue;//*the difference between them is 1 means that they are neighbors
        }else{
            return arr[i]+1;//*they aren't ngifblur and the real neighbor what comes after that element
        }
        
        
    }
    return -1;//*no missing
}

void findPairsWithSum(int arr[], int size, int sum){
    quickSort(arr,0,size-1);//*sorted array make it easy to handle
    int i=0,j=size-1;
    bool verification=false;
    while(i<j){//*if the array is sorted we start with min and max if they match we get a match and move to the next else we compare the desired sum if our sum is bigger means we should add with the second largest same for the other case
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
        printf("Pairs not found \n");//*we didn't find any pairs in the array
    }
    
 
}

void findSubArrayWithSum(int arr[], int size, int sum){
    int delimiter=0;
    //printArray(arr+delimiter,size-delimiter);
    int check_sum= sumArray(arr,size);//*calc the sum of the whole array
    bool verification=false;
    for (int i = 0; i < size; i++)
    {
        if (check_sum==sum)
        {
            printf("Sub Array found: \n"); //*we found it
            quickSort(arr,delimiter,size-delimiter);//*sort for good looking
            printArray(arr+delimiter,size-delimiter);//*print it
            verification=true;
        }if (check_sum>sum)
        {
            delimiter++;
            check_sum=sumArray(arr+delimiter,size-delimiter);
                
        }else{
            break;//*impossible to sum a sub array and the main array can't be even closer to the sum
        }
            
               
        
        
    }
    if (!verification)
    {
        check_sum=sumArray(arr,size);//*calc the sum 
        delimiter=0;
        reverseArray(arr,size);//*assuming we didn't going from right to left we will reverse
        for (int i = 0; i < size; i++)
        {
            if (check_sum==sum)
            {
                printf("Sub Array found: \n"); //*we found it
                quickSort(arr,delimiter,size-delimiter);//*sort for good looking
                printArray(arr+delimiter,size-delimiter);//*print it
                verification=true;
            }if (check_sum>sum)
            {
                delimiter++;
                check_sum=sumArray(arr+delimiter,size-delimiter);
                
            }else{
                break;//*impossible to sum a sub array and the main array can't be even closer to the sum
            }
            
               
        
        
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
    quickSort(arr,0,size-1);//*sort
    int temp1[size];//*temp array to store negatives
    int rearrangedArray[size];//*the final array
    int startOfPositive=0;//*start of positive number to appear
    for (int i = 0; i < size; i++)
    {
        if (arr[i]<=0)
        {
            temp1[startOfPositive]=arr[i];//*fill it until we get positive
            startOfPositive++;

        }else{break;}
        
    }
    reverseArray(temp1,startOfPositive);//*revers it because it will be ordered from smaller to larger
    int j=0;
    
    for (int i = 0; i < size; i+=2)
    {
        rearrangedArray[i]=temp1[j];//*one by one
        rearrangedArray[i+1]=arr[startOfPositive];
        j++;
        startOfPositive++;
    }
    printArray(rearrangedArray,size);//*print it
    
    
}

int findMajorityElement(int arr[], int size){
    quickSort(arr,0,size-1);//*sort it
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j]) count++;//*one is found we increase the counter
        }
        if (count > size / 2)return arr[i];//*according to the defintion
    }
    return -999999999;//*no majority elem found
}

int longestIncreasingSubsequence(int arr[], int size){
    int dp[size];//*dynamic programming approach
    initializeArray(dp,size,1);//*every elm is an increasing sub sequence
    
    for (int i = 1; i < size; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] >= arr[j])
            {
                dp[i] =Max(dp[i],dp[j]+1);//*the elemnt from 0 to array[i] is an increasing sub sequence the formula was taken from def of this approach
            }
        }
    }
    
   return findMax(dp,size); //*the max number is the number of longest increasing subsequence
}

void findDuplicates(int arr[], int size){
    quickSort(arr,0,size-1);//*duplicates will be adjacent
    int count;
   for (int j = 0; j < size; j=j+count+1)
   {
        count=0;
        bool verification=false;
        for (int i = j; i < size; i++)
        {
            if (arr[i]==arr[i+1])
            {
                count++;//*adjacent is the same
                verification=true;
            }else{break;}
        
        }
        if (verification) printf("The Element %d has a duplicate \n",arr[j]);
     





    }
   
    
    
}


void findIntersection(int arr1[], int size1, int arr2[], int size2){
    quickSort(arr1,0,size1-1);//*sort both arrays
    quickSort(arr2,0,size2-1);
    
    int IntersectionArr[size1+size2];//*intersection array adding size to ensure all elements in case they were the same
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
    quickSort(IntersectionArr,0,count-1);//*sort it again
    int new_size=0;
    int newArr[count];//*the new insertion array without duplicates
    for (int i = 0; i < count; i++)
    {
        if (i == 0 || IntersectionArr[i] != IntersectionArr[i - 1])
        {
           newArr[new_size]=IntersectionArr[i];//*remove duplicates they will be adjacent ignore the first elem
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
        UnionArr[count]=arr1[i];//*the union has all elements of both arrays
        count++;
    }
    for (int j = 0; j < size2; j++)
    {
        UnionArr[count]=arr2[j];
        count++;
    }
    quickSort(UnionArr,0,count-1);//*sort them and remove duplicates
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


