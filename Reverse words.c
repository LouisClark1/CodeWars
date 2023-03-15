#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// returned string has to be dynamically allocated and will be freed by the caller
char* reverseWords(const char* text) {
    char *output = (char*)malloc( (strlen(text)+1) * sizeof(char));
    char *input = (char*)malloc( (strlen(text)+1) * sizeof(char));

    char *pSpace;
    int index = 0;
    strcpy(input, text);

    unsigned int a = 0, b = 0;
    while (input[a] != 0){
        pSpace = strchr( (input + index + 1) , ' ');
        if(pSpace != NULL){
            index = (int)(pSpace - input);
        }else{
            index = strlen(input);
        }

        b = 1;
        while (input[a] != ' ' && input[a] != 0){
            output[a] = input[index - b];
            b++;
            a++;
        }
        output[a] = input[a];
        a++;
    }
    if(input != NULL){
        free(input);
    }
    return output;
}

int main (){

    char test1[] = "  V!<{ jvUTpu 'n*1K5 6<;a-|% O!}";

    char *outputString = NULL;
    outputString = reverseWords( reverseWords(test1) );

    printf("%s\n\n", outputString);
    if(outputString != NULL){
        free(outputString);
    }


    return 0;
}