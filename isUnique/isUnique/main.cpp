//
//  main.cpp
//  HelloWorld
//
//  Created by Janujan Selva on 2018-09-22.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


void isUnique(char* str);
void test_isUnique();
void isSubstring(char* str1, char* str2);
void test_isSubstring();
void is_Permutation(char* str1, char*str2);
void test_isPermutation();

int main(int argc, const char * argv[]) {
    
    test_isUnique();

    test_isSubstring();

    test_isPermutation();
    
    
    return 0;
}


/*
 Check if all characters in a string are unique:
Iterate through each letter in teh string
Store the each letter that appears in an array at the location of the ascii code.
if non zero value at location, duplicate found
*/
void isUnique(char* str)
{
    u_long len = strlen(str);
    int check_array[256] = {};
    cout<<"This is the string:" << str << endl;
    cout<<"Length of the string: "<< len << endl;
    
    for(int i = 0; i < len; i++)
    {
        if(check_array[str[i]] == 1)
        {
            cout<<"String has duplicate chars: "<<str[i]<<endl;
        }
        else{
            check_array[str[i]] = 1;
        }
        
    }
}

//Tester code
void test_isUnique()
{
    cout<<"TESTING UNIQUENESS"<<endl<<endl;;
    char test[] = "abcd";
    char test1[] = "aaccd";
    
    isUnique(test);
    isUnique(test1);
}
/*
 Given two strings, check if one string is a permutation of the other string
 EX:
    str1 = "abbac"
    str2 = "cad"
    str2 is a permutation of the str1
 
    1) start with first letter of smaller string. check if that char is in larger string, if so, move to next char. if not, you not its not a permutation
 
 */
void isSubstring(char* str1, char* str2)
{
    u_long len1 = strlen(str1);
    u_long len2 = strlen(str2);
    
    int check_array[256] = {};
    for(int i = 0; i<len1; i++)
    {
        check_array[str1[i]] = 1;
    }
    
    int j = 0;
    
    while(j<=len2)
    {
        if(check_array[str2[j]] == 1)
        {
            if(j < len2)
            {
                j++;
            }
            else{
                cout<<"str: " << str2 << " is a substring of " << str1 << endl;
            }
        }
        else{
            cout<< "str: " << str2 << " is not a substring of " << str1 << endl;
            break;
        }
    }
    
}


void test_isSubstring()
{
    cout<<endl<<"TESTING SUBSTRING"<<endl<<endl;;
    char str1[] = "abcdef";
    char str2[] = "cab";
    
    isSubstring(str1, str2);
    
    char str3[] = "abcdefghi";
    char str4[] = "zoo";
    
    isSubstring(str3, str4);
}


/*
 Given a string with spaces and true length, replaces spaces with %20;
 
 */
char* URLify(char* str, int length)
{
    //char output[length] = "";
    
    
    
    return str;
}

//Given two strings, return whether the strings are permutations of eachther:
/*EX

 "abcd"
 "dcba" <- is permutation
 */
void is_Permutation(char* str1, char* str2)
{
    u_long len1 = strlen(str1);
    u_long len2 = strlen(str2);
    bool flag = 1;
    if(len1 != len2)
    {
        flag = 0;
    }
    else{
        int check_array[256] = {0};
        
        for(int i = 0; i < len1; i++)
        {
            check_array[str1[i]] = 1;
        }
        
        int j = 0;
        while(j < len2 && flag == 1)
        {
            if(check_array[str2[j]] == 1) j++;
            else flag = 0;
        }
    }
    if(flag) cout<<str1 << " and " << str2 << " are permutations" << endl;
    else cout<< str1 << " and " << str2 << " are not permutations " << endl;
}

void test_isPermutation()
{
    cout<<"TESTING PERMUTATION"<<endl<<endl;;

    char str[5][6] = {""};
    
    strcpy(str[0],"abcde");
    strcpy(str[1],"deacb");
    strcpy(str[2],"a");
    strcpy(str[3],"dezfr");
    strcpy(str[4],"abcdf");
    
    for(int i = 1; i < 5; i++)
    {
        is_Permutation(str[0], str[i]);
        //cout<< "string " << i << " is " << str[i-1] << endl;
    }
}
