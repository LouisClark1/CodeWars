#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
ull perimeter(unsigned int n) {
    ull *pArray = (ull*)malloc((n+1) * sizeof(ull));
    ull sum = 8;
      if ( pArray ){
        pArray[0] = 1;
        pArray[1] = 1;
        for(unsigned int a = 2; a < n+1; a++){
            pArray[a] = pArray[a-1] + pArray[a-2];
            sum += 4 * pArray[a];
            printf("%i",a);
        }
        free(pArray);
      }else{
        printf("Memory problem");
        return 0;
      }
    
    return sum;
}






int main(){

    printf("\nThe sum is: %llu\n", perimeter(30));

    return 0;
}