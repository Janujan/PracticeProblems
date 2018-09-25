//
//  main.cpp
//  HelloWorld
//
//  Created by Janujan Selva on 2018-09-22.
//  Copyright © 2018 Janujan Selva. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;


void isUnique(char* str);

int main(int argc, const char * argv[]) {
    
    char test[] = "abcd";
    char test1[] = "aaccd";
    
    isUnique(test);
    isUnique(test1);

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

