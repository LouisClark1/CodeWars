#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// this is the function I wrote because I didn't know sprintf existed
// char *create_phone_number(char phnum[15], const unsigned char nums[10])
// {
//     char tempStr[15] = "(LLL) LLL-LLLL";
//     unsigned int b = 0;
//     for(unsigned int a = 0; a < 15; a++){
//         if (*(tempStr + a) == 'L'){
//             *(phnum + a) = *(nums + b) + 48;
//             b++;
//         }else{
//             *(phnum + a) = *(tempStr + a);
//         }
//     }
//     return phnum;
// }

// alternative method using spritf
char* create_phone_number(char phnum[15], const unsigned char n[10]) {
    sprintf(phnum, "(%d%d%d) %d%d%d-%d%d%d%d",
        n[0], n[1], n[2], n[3], n[4], n[5], n[6], n[7], n[8], n[9]);
    return phnum;
}


int main(){

    unsigned char test[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    char nullOutput[15]; 

    char *outputString = NULL;
    outputString = create_phone_number(nullOutput, test);
    printf("\nThe output is: %s\n", outputString);

    return 0;
}