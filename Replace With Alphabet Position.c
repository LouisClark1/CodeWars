#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text) {
    char *pTempStr = (char*)malloc(90 * sizeof(char));

    int remainder;
    int quotient;
    int asciVal;
    int a = 0;  //input text counter
    int b = 0;  //output text counter
    while (*(text+a) != '\0'){
        asciVal = ((int)*(text+a));

        if (asciVal > 64 && asciVal < 91){      //capital letters
            remainder = (asciVal - 64) % 10;
            quotient = (asciVal - 64) / 10;
        } else if (asciVal > 96 && asciVal < 123)   //lowercase letters
        {
            remainder = (asciVal - 96) % 10;
            quotient = (asciVal - 96) / 10;
        }else{
            remainder = 0;
            quotient = 0;
        }

        if ( remainder != 0 && quotient == 0){

            *(pTempStr+b) = (char)48 + remainder;   //write the 1s
            b++;
            *(pTempStr+b) = (char)32;   //write the space
            
        }else if(remainder != 0 || quotient != 0){

            *(pTempStr+b) = (char)48 + quotient;    //write the 10s
            b++;
            *(pTempStr+b) = (char)48 + remainder;   //write the 1s
            b++;
            *(pTempStr+b) = (char)32;   //write the space

        }else{
            b--;
        }
        // increaseCount:
        a++;
        b++;

    }
    //remove the space at the end
    *(pTempStr+b-1) = '\0';


    if (strlen(pTempStr) == 0){
        return strdup("");  //this is the only way I could get am empty string to be freeable
    }
    return pTempStr;

}

int main (){

    char test1[] = "123456789";
    // char test2[40] = alphabet_position(test1);

    char *outputString = NULL;
    outputString = alphabet_position(test1);

    printf("%s\n\n", outputString);
    if(outputString != NULL){
        free(outputString);
    }

    // printf("%s\n\n", test1);


    return 0;
}