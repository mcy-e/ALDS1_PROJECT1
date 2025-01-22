#include<stdbool.h>
#include<math.h>
#include<stdio.h>
#include "../lib/mainlib.h"
#include"../include/strings.h"
#include <string.h>

//& MAKE SURE TO INSTALL BETTER COMMENTS EXTENSION IF YOU ARE IN VS CODE FOR BETTER READABILITY 

//!Basic Functions
int stringLength(char* str){
    int length=0;
    while (str[length] != '\0')
    {
        length++;//*iterates untill the end of the string and don't take in mind the null
    }
    
    length=removeWhiteSpaceLength(str,length);
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
int removeWhiteSpaceLength(char* str,int length){

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
   // printf("%s",dst);//*print the copied string
}

void stringConcat(char* dest,  const char* src){
    char str1[900];
    stringCopy(src,str1);
    int len1 =stringLengthWithSpace(str1);
    int len2 = stringLengthWithSpace(dest);

   dest[len2]=' ';//*to leave white space when appending a string
    
    for (int i = 0; i<len1 ; i++)
    {
        
        dest[i+len2+1] = src[i];//*the appending operation
        
    }
    len2 =stringLengthWithSpace(dest);
    dest[len1+len2+1]='\0';
 
    //printf("%s",dest);//*printing the output
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

int stringCompareInsensitive(const char* str1, const char* str2){

   int i=0;
    while (str1[i]!='\0' && str2[i]!='\0')
    {//*this is what i understand about comparing two strings lexicographically.
        if (str1[i]!=str2[i])
        {
            return str1[i]-str2[i];//*we find a mismatch
            
        }
        i++;
    }
    return 0;//*ignore what comes after
    
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
    //printf("%s",str);//*print
    
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
   // printf("%s",str);
    
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
    //printf("%s",str);
    
}


//!Intermediate Functions
bool isPalindromeString(char* str){
    char str1[256];
    stringCopy(str,str1);
    reverseString(str);


    if (stringCompareInsensitive(str1,str)==0){ return true;}
    else {return false;}
    
        
    
    
}

void countVowelsConsonants(char* str,int* vowels,int* consonants){
    int len =stringLengthWithSpace(str);//*take consideration of white space
    *vowels=0;*consonants=0;
    toLowerCase(str);//*to handle the casses if we have upper case chars
    for (int i = 0; i < len; i++)
    {   
        if (str[i]>=97 && str[i]<=122)//*execludes special chars and handles only lower case + we force it to handle only lower case
        {
           switch (str[i])
            {
            case 'a': 
                *vowels+=1;
                break;
            case 'e': 
                *vowels+=1;
                break;
            case 'i': 
                *vowels+=1;
                break;
            case 'o': 
                *vowels+=1;
                break;
            case 'u': 
                *vowels+=1;
                break;     
            default:
                
                *consonants+=1;//*the char isn't any of the vowels so it's consonants
                
                break;
            }
        }
    }
    
}
int findSubstring(const char* str, const char* sub){
    char str1[512];stringCopy(str,str1);
    char sub1[512];stringCopy(sub,sub1);

    int len1 = stringLength(str1);
    int len2 = stringLength(sub1);
    int total=len1-len2;
    
    if (len2 > len1){
        return -1;//*impossible
    }else{
        for (int i = 0; i <= len1-len2; i++)//*to don't depace the string length
        {
            if (stringCompareInsensitive(str+i, sub) == 0){
                return i;//*means when we add i like when the strings starts from the i postion it finds the sub string so that it retruns the starting position
            }
        }
        return -1;//*there is no match between the substring and what's inside the string
    }

}

int findSubstringInsensitive(const char* str, const char* sub){
    char str1[512];stringCopy(str,str1);
    char sub1[512];stringCopy(sub,sub1);

    int len1 = stringLength(str1);
    int len2 = stringLength(sub1);
    int total=len1-len2;
    
    //*can't modify constants
   //*can't modify constants
    toLowerCase(str1);//*case insensitive
    toLowerCase(sub1);//*case insensitive
    
    if (len2 > len1){
        return -1;
    }else{
        for (int i = 0; i <= len1-len2; i++)
        {
            if (stringCompareInsensitive(str1+i, sub1) == 0){
                return i;//*means when we add i like when the strings starts from the i postion it finds the sub string so that it retruns the starting position
            }
        }
        return -1;//*there is no match between the substring and what's inside the string

    }

}

void removeWhiteSpace(char* str){
    int len = stringLengthWithSpace(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i]==' ')
        {   for (int j = i; j <= len; j++)
            {
                str[j] = str[j+1];//*shift the string ie overwrite the white space it does it when it finds any white space
                
                
            }
        
            
        }
        
    }

    
}

bool isAnagram(char* str1, char* str2){
    int len1=stringLength(str1);
    int len2=stringLength(str2);
    int k=0;
    int arr[512];
    
    if (len1 != len2) {return false;}
    else{
        
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (str1[i]==str2[j])
                {
                    arr[k]=1; 
                }
                
            }
            k++;
        }
        
        for ( k = 0; k < len1; k++)
        {
            if (arr[k]!=1) return false;
        }
        return true;



    }
    
}


void charFrequency(char* str)
{
    char arr[30] = {0};//*itnitialize chars with '\0'       
    int freq;
    int len = stringLength(str);  

    for (int i = 0; i < len; i++) {
        freq = 0;//*every frequency of char starts with 0
        
        int already_counted = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] == str[i]) {
                already_counted = 1;//*the arrays has seen that char before
                break;
            }
        }

        if (already_counted==1) {
            continue;  //*if so it will skip to the next iteration
        }

        for (int j = 0; j < len; j++) {
            if (str[i] == str[j]) {
                freq++;//*now it will looks for chars like the same as the one we have and add untill we are at the end of the line
            }
        }

        arr[i] = str[i];//*save the char in the arr incase we found it again  so we're going to skip 
        printf("'%c' has been repeated %d times\n", str[i], freq);
    }
}


int countWords(char* str){
    int len =stringLengthWithSpace(str);
    int count=1;
    for (int i = 0; i < len; i++)
    {
        if (str[i]==' ')
        {
            count++;//*logically any 2 words is seperated by white space unless the writer can't write
        }
        
    }
    return count;
}

void removeDuplicates(char* str){
    int len =stringLength(str);
    char arr[30];//*to store the repeated chars
    int check;//*used for chrcking
    int new_len=0;//*to reduce the length of the string because we're going to remove duplicates
    for (int i = 0; i < len; i++)
    {
        for (int k = 0; k < len; k++)
        {
            if(arr[k]==str[i]) {check = 1;
            break;}

        }//*chacks for previous chars if we used them
        if(check==1){
            continue;
            new_len++;//*remove to the next iteration
        
        }else{
            for (int j = i+1; j < len; j++)
            {
                if (str[j]==str[i])
                {
                    for (int l = j; l < len-1; l++)
                    {
                        str[l]=str[l+1];//*it finded a duplicate char so it's going to override it by the next chars
                    }
                    
                }
                
            }
            new_len++;//*the new lentgh of the new string

        }
        
        arr[i]=str[i];//*used for checking
    }
    
 str[new_len]='\0';//*the delimiter because the last char will be repeated untill the lentgh so we delete thos lentgh and put a new lenght as the effective length



}

//!Advanced functions
void compressString(char* str, char* result)
{
    int len=stringLength(str);
    int start=0;int count;
    result[0]='\0';//*initialize the delimiter
    
    for (int i = 0; i < len; i=i+count)
    {
        count=0;//*to reset at every iteration
        for (int  j = i; j < len; j++)
        {
            if (str[j]==str[i])
            {
                count++;
            }else{break;}//*to not look over other chars in between others like don't look for the last a in it's treared sperately aaabba
            
        }

        int numberDigits = numberOfDigits(count);
        result[start] = str[i];//*to concatenate i can use concat function but i don't want to creat another one because i set a space to separate the added string to the original string
        char countStr[numberDigits];
        switchInt_Str(countStr,count);//*this i nedd to creat i can use sprintf but i have my own one now ;)
        for (int k = 0; k < numberDigits; k++){
            result[start+1+k] = countStr[k];//*the same talk ican but iam too lazy to do it and it's easy it's only one line  so what's the problem
        }
        
       
        start=start+numberDigits+1;//*to move up by the number of digits added and the string to avoid overwrite
        
    }

    result[start]='\0';//*to set the new delimiter
}
void switchInt_Str(char* str,int num){
    int digit_num=numberOfDigits(num);
    int digit;
    for (int i = digit_num-1; i >=0; i--)
    {
        digit = num%10;
        //*this what hits in mind i don't think there is a better way 
        switch (digit)
        {
        case 0:
            str[i]='0';
            break;
        case 1:
            str[i]='1';
            break;
        case 2:
            str[i]='2';
            break;
        case 3:
            str[i]='3';
            break;
        case 4:
            str[i]='4';
            break;
        case 5:
            str[i]='5';
            break;
        case 6:
            str[i]='6';
            break;
        case 7:
            str[i]='7';
            break;
        case 8:
            str[i]='8';
            break;
        case 9:
            str[i]='9';
            break;
        
        
        }
        num=num/10;//*decrease the number

    }
    str[digit_num]='\0';//*set the new delimiter
    
}

void longestWord(char* str, char* result){
    int words_num=countWords(str);//*number of words so iam going to do linear search 
    int len =stringLengthWithSpace(str);
    int max=-1;//*initialize the max
    int count;
    int pos=0;//*initialize the position
    for (int i = 0; i < words_num; i++)
    {
        count = 0;//*resets every time to ensure we find the max
        for (int j =pos; j < len; j++)
        {
            if (str[j]!=' ')
            {
                count++;
                pos++;
            }else{break;}
            
            
        }
        
        if (count >= max)
        {   
            int temp=pos;//*to preserve the position because it will be modified  and we need it 
            max=count;
            for (int i = max-1; i >= 0; i--)
            {
                result[i]=str[temp-1];
                temp--;//*what i comment here i mean it's obvious
            }
        }
        pos++;//*escape the blank delimiter
        
    }
    //reverseString(result);
    result[max]='\0';//*set the new delimiter know the end of the string
    

}

bool isRotation(char* str1, char* str2){
    int len=stringLength(str1);
    for (int i = 0; i < len; i++)
    {
        rotateLeft(str2);//*rotate left by 1 then rotate it another time until it finds a match or complete one rotation around the string
        if (stringCompare(str1, str2)==0) return true;
        
    }
    return false;//*didn't find any matches

    
    
}
void rotateLeft(char* str){
    int len=stringLength(str);
    char temp=str[0];//*store the first char
    for (int i = 0; i < len-1; i++)
    {
        str[i]=str[i+1];//*position the second char in the first pos
    }
    str[len-1]=temp;//*puts the first char last
}

void rotateLeftTimes(char* str,int times){
    for (int i = 0; i < times; i++)
    {
        rotateLeft(str);//*loops number of times
    }
}

void rotateRightTimes(char* str,int times){
    int len=stringLength(str);
    rotateLeftTimes(str,abs(len-times));//*rotating right by a number is like the inverse of rotating left by a number  
    //*so if i rotate something 4 times right and it has 3 char it's the same as rotating it left by 1 time 
}

int countChar(char* str, char character){
    int len=stringLengthWithSpace(str);
    int count=0;
    for (int i = 0; i < len; i++){//*it's obvious like it starts from the beginning preforming a linear search when it finds a match the counter increases by 1
        if (character==str[i])
        {
            count++;//*find a match
        }
        
    }
    return count;//*count=
}

void findAndReplace(char* str, char* find, char* replace){
    int len=stringLengthWithSpace(str);
    int find_len=stringLength(find);
    int replace_len=stringLength(replace);
    int pos=0;
    while(pos<len){
        
        if (stringCompareInsensitive(str+pos, find)==0)
        {
            for (int i = 0; i < replace_len; i++)
            {
                str[pos+i]=replace[i];//*overwrite the existing substring with the new one
            }

            pos=pos+replace_len;//*escape the substring that it's been replaced
        } else{
            pos++;//*if there isn't match it will move to the second postion and compare
        }
        
    }
    
}



void longestPalindrome(char* str, char* result){
    int len = stringLength(str);//*like usual string length
    
    for (int start = 0; start < len; start++)
    {
        
        for (int end = len - 1; end >= start; end--) { //*corrected the decrement logic and boundary check
            int pos=0; //*used later to store every char in the string to temp
            char temp[len +1];//*creat a temp string with space for null terminator
            
          
            for (int j = start; j <= end; j++)
            {   
                temp[pos]=str[j];//*start from the start paramater until the end
                pos++;
                
            }
            
            temp[pos]='\0';//*here is the key to determine every substring possible of a string
            printf("%s\n", temp);
            //*THE DELIMITER
            if (isPalindromeString(temp))
            {   
            
                if (stringLength(temp) > stringLength(result)){            
                    stringCopy(temp,result);//*check if it's palindrome if so it will copy the temp to the result and then break
                    //*in the first iteration the first combination if it's not palindrome the first char will be the largest palindrome 
                    //*so if there was a seconde combination that's palindrome and bigger than the char we will take it
                }break;   //*the way it performs break and the way of dividing the string let the procedure always handle the largest palindromes first         
            }
        }
    } 
}

void printPermutations(char* str){
    int len=stringLength(str);int pos=1;//*the first is usall the second for good look print statement
    
    char arrOfStr[5212]="";//*didn't know why it doesn't work with a pointer probablly i need to locate some memory before and that's why python is the best it doesn't ask you for this it tels you do whatever you want i will handle it
   //*the number is chosen randomly so that i can store so many of those strings combination
    for (int i = 0; i < len; i++)
    {

        for (int j = 0; j <len; j++)
        { 
            rotateLeft(str);//*rotate the string
            int verification=0;
            
            
            if (findSubstring(arrOfStr,str)!=-1)
            {
                verification=1;//*we found the exsistance of the sub string in previous states
                break; 
            }
                
          
        
            if(verification==0){printf("permutation[%d]is : %s\n",pos,str);
            stringConcat(arrOfStr,str);
            pos++;}//*we will ignore this combination
                
            //*we add the string to his familly for future checks and we only add once we are low on space
           
           
           //*the position increase every time we print the string 
            
        }
        rotateLeft(str);//*return the string to it's original position
        char temp=str[0];
        str[0]=str[i+1];//*swap between the first and the others to ensure every possible combination
        str[i+1]=temp;
      
    }
    
}






void splitString(char* str, char delimiter, char tokens[][100], int* tokenCount) {
    int len = stringLengthWithSpace(str);

    int pos = 0;
    int new_len = 0;
    for (int i = 0; i < len; i++) {
        new_len++;//*to inform when adding the lenght of each token
        if (str[i] == delimiter) {

            int k = i - 1;
            for (int j = new_len -2; j >= 0; j--) {
                tokens[*tokenCount][pos] = str[k];
                k--;
                pos++;//*the item will set reverse order
            }
            reverseString(tokens[*tokenCount]);//*we reverse it back
            tokens[*tokenCount][pos] = '\0';//*the delimiter 
            new_len = 0;//*we reset the new length for the other token
            pos = 0;//*we reset tho postion
            *tokenCount = *tokenCount + 1;//*we move to the ohter token
           
        }
        
    }
    //*we handle the last string because it won't get the delimiter check

    if (new_len > 0) {
        int k = len - new_len;
        for (int j = 0; j < new_len; j++) {
            tokens[*tokenCount][j] = str[k + j];
        }//*the same process but it's ordered because everything is known we don't need to keep track of it
        tokens[*tokenCount][new_len] = '\0';//*set the delimiter
        *tokenCount = *tokenCount + 1;//*add a token
    }
}


