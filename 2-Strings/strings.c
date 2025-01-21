#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include"../include/strings.h"

//& MAKE SURE TO INSTALL BETTER COMMENTS EXTENSION IF YOU ARE IN VS CODE FOR BETTER READABILITY 

//!Basic Functions
int stringLength(char* str){
    int length=0;
    while (str[length] != '\0')
    {
        length++;//*iterates untill the end of the string and don't take in mind the null
    }
    
    length=removeWhiteSpace(str,length);
    return length;
    
}
int stringLengthWithSpace(char* str){
    int length=0;
    while (str[length] != '\0')
    {
        length++;//*iterates untill the end of the string and don't take in mind the null
    }
    
    
    return length;
    
}
int removeWhiteSpace(char* str,int length){

    for (int i = 0; i <= length; i++)
    {
        if (str[i] == ' ')
        {
            length--;//*removes the white space if it was a sentence so it only calculates chars
            
        }
        
    }
    return length;
}

void stringCopy(const char* src,char* dst){

    for (int i = 0; src[i] !='\0'; i++)
    {
        dst[i] = src[i];//*iterates untill the end of the string
    }//*replace every char by the same one as the source
    printf("%s",dst);//*print the copied string
}

void stringConcat(char* dest,  const char* src){


    int len2 = stringLength(dest);

   dest[len2]=' ';//*to leave white space when appending a string

    for (int i = 0; src[i]!='\0' ; i++)
    {
        
        dest[i+len2+1] = src[i];//*the appending operation
    
    }
 
    printf("%s",dest);//*printing the output
}

int stringCompare(const char* str1, const char* str2){

   int i=0;
    while (str1[i]!='\0' && str2[i]!='\0')
    {//*this is what i understand about comparing two strings lexicographically.
        if (str1[i]!=str2[i])
        {
            return str1[i]-str2[i];//*we find a mismatch
            
        }
        i++;
    }
    return str1[i]-str2[i];//*either the first chars until i+1 are identical and the words are identical or one string has the first part is identical and has an additional rest must take in place
    
}

bool isEmpty(char* str){
    int length=stringLength(str);
    if (length==0) return true;
    

    return false;
}

bool isEmptyLiterally(char* str){
    if(str[0]=='\0') return true;
    return false;
}

void reverseString(char* str){
    int len= stringLengthWithSpace(str);//*find the length of the string 
    int temp;//*to store the char and to don't let it disappear
    
    for(int i=0; i<len/2; i++)
    {
    
        temp=str[i];//*the reverse operation
        str[i]=str[len-i-1];//*first becomes last and so on..
        str[len-i-1]=temp;
        
    }
    printf("%s",str);//*print
    
}

void toUpperCase(char* str){
    int i=0;
    while (str[i]!='\0')
    {
        if (str[i]>=97 && str[i]<=122)
        {
            str[i]=str[i]-32;//*ensure that the char is in the range of lowercase char and subtract 32 to switch to it's upper case
            
        }//*like a in the ascci has the number 97 when we subtract 32 we get 65 which represents A in assci table
        i++;
    }
    printf("%s",str);
    
}

void toLowerCase(char* str){
    int i=0;
    while (str[i]!='\0')
    {
        if (str[i]>=65 && str[i]<=90)
        {
            str[i]=str[i]+32;//*ensure that the char is in the range of uppercase char and add 32 to switch to it's lower case

            
        }//*like A in the ascci has the number 65 when we add 32 we get 97 which represents a in assci table

        i++;
    }
    printf("%s",str);
    
}








