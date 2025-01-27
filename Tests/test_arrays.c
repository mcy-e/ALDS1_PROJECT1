#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"

int main(){
  // ** ||Instructions for users|| **//
  //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
  
  //& Testing Basic Functions 
  /*
  int testArr1[5] = {10, 20, 30, 40, 50};
  int testArr2[5] = {1, 2, 3, 4, 5};
  
  printf("Initialize Array Test:\n");
  initializeArray(testArr1, 5, 0);
  printArray(testArr1, 5);
  
  printf("Find Max Test: %d\n", findMax(testArr2, 5));
  printf("Find Min Test: %d\n", findMin(testArr2, 5));
  printf("Sum Array Test: %d\n", sumArray(testArr2, 5));
  printf("Average Array Test: %f\n", averageArray(testArr2, 5));
  
  minimizedArray(testArr1, 5);
  printf("Minimized Array Test:\n");
  printArray(testArr1, 4);
  
  int digitArr[10];
  storingDigits(digitArr, 12345);
  printf("Storing Digits Test:\n");
  printArray(digitArr, 5);
  
  printf("Returning Digits Test: %d\n", returningDigits(digitArr, 5));
  */

  //& Testing Intermediate Functions
  /*
  int testArr3[6] = {10, 20, 30, 40, 50, 60};
  int evenCount = 0, oddCount = 0;
  
  countEvenOdd(testArr3, 6, &evenCount, &oddCount);
  printf("Even Count: %d, Odd Count: %d\n", evenCount, oddCount);
  
  printf("Second Largest Test: %d\n", secondLargest(testArr3, 6));
  
  printf("Element Position Test: %d\n", findElementPos(testArr3, 6, 30));
  
  printf("Element Found Test: %d\n", found(testArr3, 6, 40));
  
  printf("Element Frequency Test:\n");
  elementFrequency(testArr3, 6);
  
  printf("Remove Duplicates Test: %d\n", removeDuplicatesElements(testArr3, 6));
  
  printf("Linear Search Test: %d\n", linearSearch(testArr3, 6, 40));
  
  int sortedArr[6] = {10, 20, 30, 40, 50, 60};
  printf("Binary Search Test: %d\n", binarySearch(sortedArr, 6, 40));
  */

  //& Testing Sorting Algorithms
  
  /*
  int bubbleArr[5] = {64, 34, 25, 12, 22};
  printf("Before Bubble Sort:\n");
  printArray(bubbleArr, 5);
  bubbleSort(bubbleArr, 5);
  printf("After Bubble Sort:\n");
  printArray(bubbleArr, 5);
 
  int selectionArr[5] = {64, 34, 25, 12, 22};
  printf("Before Selection Sort:\n");
  printArray(selectionArr, 5);
  selectionSort(selectionArr, 5);
  printf("After Selection Sort:\n");
  printArray(selectionArr, 5);
  
  int insertionArr[5] = {64, 34, 25, 12, 22};
  printf("Before Insertion Sort:\n");
  printArray(insertionArr, 5);
  insertionSort(insertionArr, 5);
  printf("After Insertion Sort:\n");
  printArray(insertionArr, 5);
  
  int mergeArr[5] = {64, 34, 25, 12, 22};
  printf("Before Merge Sort:\n");
  printArray(mergeArr, 5);
  mergeSort(mergeArr, 0, 5);
  printf("After Merge Sort:\n");
  printArray(mergeArr, 5);
  
  int quickArr[5] = {64, 34, 25, 12, 22};
  printf("Before Quick Sort:\n");
  printArray(quickArr, 5);
  quickSort(quickArr, 0, 4);
  printf("After Quick Sort:\n");
  printArray(quickArr, 5);
  */

  //& Testing Advanced Functions
  /*
  int testArr4[5] = {10, 20, 30, 40, 50};
  printf("Is Empty Array Test: %d\n", isEmptyArray(testArr4, 5));
  
  int missingArr[5] = {1, 2, 4, 5, 6};
  printf("Find Missing Number Test: %d\n", findMissingNumber(missingArr, 5));
  
  int pairArr[6] = {10, 5, 2, 3, 7, 6};
  printf("Find Pairs With Sum Test:\n");
  findPairsWithSum(pairArr, 6, 10);
  
  int subArr[5] = {20, 3, 10,1, 4};
  printf("Find Subarray With Sum Test:\n");
  findSubArrayWithSum(subArr, 5, 33);
  
  int altArr[6] = {-1, 2, -3, 4, 5, 6};
  printf("Rearrange Alternate Positive Negative Test:\n");
  rearrangeAlternatePositiveNegative(altArr, 6);
  
  int majorityArr[7] = {3, 3, 4, 2, 4, 4, 2};
  printf("Find Majority Element Test: %d\n", findMajorityElement(majorityArr, 7));
  
  int subsequenceArr[6] = {10, 22, 9, 33, 21, 50};
  printf("Longest Increasing Subsequence Test: %d\n", longestIncreasingSubsequence(subsequenceArr, 6));
  
  int duplicateArr[7] = {0, 3, 4, 2, 3, 5, 4};
  printf("Find Duplicates Test:\n");
  findDuplicates(duplicateArr, 7);
  
  int arr1[5] = {1, 2, 4, 5, 6};
  int arr2[5] = {2, 3, 5, 7, 8};
  printf("Find Intersection Test:\n");
  findIntersection(arr1, 5, arr2, 5);
  
  printf("Find Union Test:\n");
  findUnion(arr1, 5, arr2, 5);
  */

  return 0;
}