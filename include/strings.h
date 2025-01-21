#ifndef STRINGS_H
#define STRINGS_H

//!Basic Functions
int stringLength(char* str);

int stringLengthWithSpace(char* str);

int removeWhiteSpace(char* str,int length);

void stringCopy(const char* src,char* dst);

void stringConcat(char* dest, const char* src);

int stringCompare(const char* str1, const char* str2);

bool isEmpty(char* str);

bool isEmptyLiterally(char* str);

void reverseString(char* str);

void toUpperCase(char* str);

void toLowerCase(char* str);












#endif