#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool IsIsogram (const char *string);





int main (){

    bool result;
    result = IsIsogram("Aa");
    printf("%s\n", result ? "true" : "false");

    printf("True means there are no matching characters\n\n");

    return 0;
}


bool IsIsogram (const char *string){
    unsigned int charCountOuter = 0;
    unsigned int charCountInner = 0;

    while (*(string + charCountOuter) != '\0'){
        charCountInner = 0;
        while (*(string + charCountInner) != '\0'){
            if ( (tolower(*(string + charCountOuter)) == tolower(*(string + charCountInner)))
                && 
                (charCountInner != charCountOuter) ){
                    return 0;
            }
            charCountInner++;
        }
        charCountOuter++;
    }
    return 1;
}