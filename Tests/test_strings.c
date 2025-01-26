#include<stdio.h>
#include<stdbool.h>
#include "../lib/mainlib.h"

int main(){
    // ** ||Instructions for users|| **//
    //TODO: // Uncomment the lines below to test specific functions./ You can modify the arguments or add new tests as needed.
    
    //& Testing Basic String Functions 
    /*
    char dst[1024] = "hello world";
    printf("String Length: %d\n", stringLength(dst));
    
    char copy[1024];
    stringCopy(dst, copy);
    printf("Copied String: %s\n", copy);
    
    stringConcat(copy, " test");
    printf("Concatenated String: %s\n", copy);
    
    printf("String Compare: %d\n", stringCompare("hello", "world"));
    
    printf("Is Empty: %d\n", isEmpty(dst));
    printf("Is Literally Empty: %d\n", isEmptyLiterally(""));
    
    reverseString(dst);
    printf("Reversed String: %s\n", dst);
    
    toUpperCase(dst);
    printf("Uppercase: %s\n", dst);
    
    toLowerCase(dst);
    printf("Lowercase: %s\n", dst);
    */

    //& Testing Intermediate String Functions
    /*
    char test[1024] = "hello world";
    printf("Is Palindrome: %d\n", isPalindromeString(test));
    
    int vowels = 0, consonants = 0;
    countVowelsConsonants(test, &vowels, &consonants);
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    
    printf("Substring Position: %d\n", findSubstring("hello world", "world"));
    printf("Case Insensitive Substring: %d\n", findSubstringInsensitive("Hello World", "world"));
    
    removeWhiteSpace(test);
    printf("Removed Whitespace: %s\n", test);
    
    printf("Is Anagram: %d\n", isAnagram("listen", "silent"));
    
    charFrequency(test);
    
    printf("Word Count: %d\n", countWords("hello world test batata"));
    
    removeDuplicates(test);
    printf("Removed Duplicates: %s\n", test);
    */

    //& Testing Advanced String Functions
    /*
    char test[1024] = "hello world";
    char result[1024] = {0};
    
    compressString(test, result);
    printf("Compressed String: %s\n", result);
    
    char num_str[100];
    switchInt_Str(num_str, 179);
    printf("Integer to String: %s\n", num_str);
    
    longestWord("quick brown fox jumps", result);
    printf("Longest Word: %s\n", result);
    
    rotateLeftTimes(test, 2);
    printf("Rotated Left: %s\n", test);
    
    printf("Is Rotation: %d\n", isRotation("hello", "llohe"));
    
    printf("Char Count: %d\n", countChar(test, 'l'));
    
    findAndReplace(test, "world", "earth");
    printf("Find and Replace: %s\n", test);
    
    longestPalindrome("racecar hello", result);
    printf("Longest Palindrome: %s\n", result);
    
    printPermutations("abc");
    
    char str[999] = "apple,banana,cherry,mcy,bro,tt";
    char delimiter = ',';
    char tokens[100][100];
    int token_count = 0;
    splitString(str, delimiter, tokens, &token_count);
    for (int i = 0; i < token_count; i++) {
        printf("Token %d: %s\n", i+1, tokens[i]);
    }
    */

    //& Testing Cipher Functions
    /*
    char cipher_test[100] = "Hello World";
    
    caesarCipher(cipher_test, 3);
    printf("Caesar Cipher: %s\n", cipher_test);
    
    strcpy(cipher_test, "Hello World");
    substitutionCipher(cipher_test, "QAZWSXEDCRFVTGBYHNUJMIKOLP");
    printf("Substitution Cipher: %s\n", cipher_test);
    
    strcpy(cipher_test, "Hello World");
    xorCipher(cipher_test, 'k');
    printf("XOR Cipher: %s\n", cipher_test);
    
    strcpy(cipher_test, "Hello World");
    vigenereCipher(cipher_test, "key", 1);
    printf("Vigenere Encrypt: %s\n", cipher_test);
    
    vigenereCipher(cipher_test, "key", 0);
    printf("Vigenere Decrypt: %s\n", cipher_test);
    
    strcpy(cipher_test, "Hello World");
    atbashCipher(cipher_test);
    printf("Atbash Cipher: %s\n", cipher_test);
    
    char rail_result[100];
    railFenceCipher(cipher_test, rail_result, 3);
    printf("Rail Fence Cipher: %s\n", rail_result);
    */

    return 0;
}