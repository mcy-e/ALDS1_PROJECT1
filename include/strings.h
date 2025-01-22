#ifndef STRINGS_H
#define STRINGS_H

//!Basic Functions
int stringLength(char* str);

int stringLengthWithSpace(char* str);

int removeWhiteSpaceLength(char* str,int length);

void stringCopy(const char* src,char* dst);

void stringConcat(char* dest, const char* src);

int stringCompare(const char* str1, const char* str2);

int stringCompareInsensitive(const char* str1, const char* str2);
bool isEmpty(char* str);

bool isEmptyLiterally(char* str);

void reverseString(char* str);

void toUpperCase(char* str);

void toLowerCase(char* str);

//!Intermediate Functions

bool isPalindromeString(char* str);

void countVowelsConsonants(char* str,int* vowels,int* consonants);

int findSubstring(const char* str, const char* sub);

int findSubstringInsensitive(const char* str, const char* sub);

void removeWhiteSpace(char* str);

bool isAnagram(char* str1, char* str2);

void charFrequency(char* str);

int countWords(char* str);

void removeDuplicates(char* str);

//!Advanced functions
void compressString(char* str, char* result);

void switchInt_Str(char* str,int num);

void longestWord(char* str, char* result);

bool isRotation(char* str1, char* str2);

void rotateLeft(char* str);

void rotateLeftTimes(char* str,int times);

void rotateRightTimes(char* str,int times);

int countChar(char* str, char character);

void findAndReplace(char* str, char* find, char* replace);

void findAndReplace2(char* str, char* find, char* replace,char* new);

void longestPalindrome(char* str, char* result);

void printPermutations(char* str);

void splitString(char* str, char delimiter, char tokens[][100], int* tokenCount);

#endif