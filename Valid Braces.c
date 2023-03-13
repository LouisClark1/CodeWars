#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool valid_braces (const char *braces){
    int count = 0;
    
    char *tempString = (char *)malloc(sizeof(char)*(strlen(braces) + 1));
   
    strcpy(tempString, braces);
    printf("%s\n", tempString);
    int shortenCount = 0;
    while(tempString[count] != '\0'){
        count++;
        if (    (tempString[count] == ']' && tempString[count - 1] == '[' ) ||
                (tempString[count] == '}' && tempString[count - 1] == '{' ) ||
                (tempString[count] == ')' && tempString[count - 1] == '(' ) ){
            if (tempString[2] == '\0'){
                return true;    
            }
            // go from the current point to the end including \0 replacing characters
            shortenCount = count - 1;
            while(tempString[shortenCount] != '\0'){
                tempString[shortenCount] = tempString[shortenCount+2];
                shortenCount++;
            }
            // go back to the start after characters have been removed to search again
            count = 0;
        }
        
    }
    free(tempString);
	return false;
}



int main (){

    bool result;
    result = valid_braces("(((((())))))(){}[]([{}])(}(}[(])[(])[({})](][({})](]");
    printf("\n%s\n", result ? "true" : "false");

    return 0;
}