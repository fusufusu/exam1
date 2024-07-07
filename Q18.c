#include <stdio.h>
#include <stdint.h>

uint8_t alpha = 0;
uint8_t beta = 0;
uint16_t gama = 20001;

int main()
{

    alpha = (uint8_t)(gama & 0xFF);        
    beta = (uint8_t)((gama >> 8) & 0xFF);  


    printf("gama = %u\n", gama);
    printf("alpha = %u\n", alpha);
    printf("beta = %u\n", beta);

    return 0;
}
