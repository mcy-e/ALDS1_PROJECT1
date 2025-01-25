#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"

int main(){
 // ** ||Instructions for users|| **//
  //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
  
 
  //char result[106]={0};
  //char dst[1024]="abc";
  //int v=179,c;
 //printf("%s",dst-1);
  //& Testing the basic functions

  //printf("%d",stringLength("hello world!"));
  //stringCopy("hello",dst);
  //stringConcat(dst,"world!");
  //printf("%d",stringCompare("wowe","ewow"));
  //printf("%d",isEmptyLiterally(""));
  //reverseString(dst);
  //toUpperCase(dst);
  //toLowerCase(dst);

  //& Testing the intermediate functions  
  //printf("%d",isPalindromeString(dst));
  //countVowelsConsonants(dst,&v,&c);
  //printf("v= %d ,c= %d",v,c);
  //printf("%d",findSubstring("ggvlm","mcy"));
  // printf("%d",findSubstringInsensitive("rfrMcygg","mcy"));
  //removeWhiteSpace(dst);
  //printf("%s",dst);  
  //printf("%d",isAnagram("listen","silent"));
  //charFrequency(dst);
  //printf("%d",countWords(dst));
  //removeDuplicates(dst);
  //printf("%s",dst);

  //& Testing the advanced functions
  //compressString(dst,result);
  //printf("%s \n" ,dst);    
  //printf("%s \n" ,result);
  //switchInt_Str(result,v);
  //printf("%s \n",result);
  //printf("%d \n",v);
  //longestWord(dst,result);
  //printf("%s \n" ,result); 
  //rotateLeftTimes(dst,2);
  //printf("%s \n" ,dst);
  //rotateRightTimes(result,1);
  //printf("%s \n" ,result);
  //printf("%d \n",isRotation(dst,result));
  //printf("%d\n",countChar(dst,'a'));
  //findAndReplace(dst,"mcy","m3ztt");
  //printf("%s \n" ,dst);
  //longestPalindrome(dst,result);
  //printf("%s \n" ,result); 
  //printPermutations(dst);
  //char str[999]="mcy,bb,apple,waffle,gg,bro";
  //char delimiter=',';
  //char tokens[100][100];
  //int token=0;
 // splitString(str,delimiter,tokens,&token);
  /*for (int i = 0; i < 6; i++)
  {
    
    printf("token number %d is :%s\n",i+1,tokens[i]);
    
    
  }
  printf("%d\n",token);
*/

//& Test Cypher functions

char str[100]="Hello world";
char str2[100];

//caesarCipher(str, 3);
//printf("%s\n",str);

//substitutionCipher(str, "QAZWSXEDCRFVTGBYHNUJMIKOLP");
//printf("%s\n",str);

xorCipher(str, 'k');
printf("%s\n",str);
xorCipher(str, 'k');
printf("\n%s\n",str);
xorCipher(str, 'k');
printf("\n%s\n",str);
//vigenereCipher(str, "key" ,1);
//vigenereCipher(str,"key",0);
//printf("%s\n",str);

//atbashCipher(str);
//printf("%s\n",str);

//railFenceCipher(str, str2, 3);
//printf("%s\n",str2);







  return 0;
}