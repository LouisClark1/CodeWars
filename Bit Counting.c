#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t countBits(unsigned value)
{
    // value = 1234; //1 & a;
    int sum = 0;
    while (value >= 1){

        sum += 1 & value;
        printf("%i\n", value);
        value = value >> 1;
    }
    
	return sum;
}





int main(){


    printf("\nsum: %i\n", countBits(9));

    return 0;
}