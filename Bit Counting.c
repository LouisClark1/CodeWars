#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t countBits(unsigned value){
    int sum = 0;
    while (value >= 1){
        sum += 1 & value;
        value = value >> 1;
    }
	return sum;
}





int main(){


    printf("\nsum: %i\n", countBits(9));

    return 0;
}