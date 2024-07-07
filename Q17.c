#include <stdio.h>  
  
#define VALUE_B 217  
#define VALUE_C 219.321  
  
static int alpha;  
static float beta;  
  
void STDRxCallback(int* b, float* c) 
{  
    *b = VALUE_B;  
    *c = VALUE_C;  
}  

void (*callback)(int*, float*) = STDRxCallback; 

int main() 
{   
    callback(&alpha, &beta);    
    return 0;  
}