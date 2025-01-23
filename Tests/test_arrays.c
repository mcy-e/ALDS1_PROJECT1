#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"
int main(){
 // ** ||Instructions for users|| **//
  //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
  int size=5;
  int arr[]={1,1,1,3,5};

  //& Testing the basic functions
    //initializeArray(arr,size,5);
    //fillArray(arr,size);
    //printArray( arr,size);
    //printf("%d",findMax( arr, size));  
    //printf("%d",findMin( arr, size));
    //printf("%d",sumArray( arr, size));
    //printf("%f",averageArray( arr, size));
    //printArray( arr,size);
    //printf("%d",isSorted( arr, size));

  //& Testing the intermediate functions

    //reverseArray(arr,size);
    //printArray(arr,size);
    //int odd=0,even=0;
    //countEvenOdd(arr,size,&even,&odd);
    //printf("odd : %d\n",odd);printf("even : %d \n",even);
    //printf("%d",secondLargest(arr,size));
    //elementFrequency(arr,size);
    printf("%d",removeDuplicatesElements(arr,size));

  //& Testing the advanced functions


    return 0;
}