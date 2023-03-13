#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void move_zeros(size_t len, int arr[len]);

int main(){

    move_zeros(17, ((int []) {0, 1, 0, 2, 0, 3, 4, 5,5,8,4,0,1,5,6,0,0}));


    return 0;
}

void move_zeros(size_t len, int arr[len]){
    int *pTempArray = (int*)malloc(len * sizeof(int));
    unsigned int arrayCount = 0; //counts up to the number of nonzero values
    for(unsigned int loopCount = 0; loopCount< (int)len; loopCount++){
        if (arr[loopCount] != 0)        {
            pTempArray[arrayCount] = arr[loopCount];
        }else{
            arrayCount--;
        }
        arrayCount++;
        printf("%i ", arr[loopCount]);
    }
    printf("\narraycount is %i\n", arrayCount);

    // write the temp array onto the original
    for(unsigned int a = 0; a < (int)len; a++){
        if (a < arrayCount){
            arr[a] = pTempArray[a];
        }else{
            arr[a] = 0;
        }
    }
    free(pTempArray);
}
