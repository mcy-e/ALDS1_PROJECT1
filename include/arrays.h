#ifndef ARRAYS_H
#define ARRAYS_H

//!Basic Functions
void initializeArray(int arr[], int size, int value);

void printArray(int arr[], int size);

int findMax(int arr[], int size);

int findMin(int arr[], int size);

int sumArray(int arr[], int size);

double averageArray(int arr[], int size);

void minimizedArray(int arr[], int size);

bool isSorted(int arr[], int size);

void fillArray(int arr[], int size);

void storingDigits(int arr[],int number);

void minimumValue(int arr[],int size,int *index,int pos);

void selectionSort(int arr[],int size);

int returningDigits(int arr[] ,int size );

void createArray(int arr [],int size);


void swapArray(int arr[],int arr_size);

void mergeSortedArray(int arr1[],int arr2[],int arr_size1,int arr_size2,int arr3[]);

//!Intermediate functions

void reverseArray(int arr[],int size);

void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount);

int secondLargest(int arr[], int size);

int findElementPos(int arr[], int size,int element);

void elementFrequency(int arr[], int size);

bool found(int arr[], int size,int element);

int removeDuplicatesElements(int arr[], int size);

int binarySearch(int arr[],int size ,int target);

int linearSearch(int arr[],int size,int target);

void shift_left(int arr[],int arr_size,int repeat_times);

void shift_right(int arr[],int arr_size,int repeat_times);

#endif 