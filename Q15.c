#include <stdio.h>  
#include <stdint.h>  

typedef struct
{
uint32_t get_count;
uint32_t set_count;
float out;
}ramp_t;
void ramp_init(ramp_t *ramp,uint32_t target_count)
{
ramp->get_count = 0;
ramp->set_count = target_count;
ramp->out = 0;
}
float ramp_calc(ramp_t *ramp)
{
if(ramp->set_count <= 0)
return 0;
if(ramp->get_count >= ramp->set_count)
ramp->get_count = ramp->set_count;
else
ramp->get_count++;
ramp->out = (float)ramp->get_count/(float)ramp->set_count;
return ramp->out;
}

void buffer(float* a, float b, float high_parameter, float low_parameter) {
    if (((*a - b) <= high_parameter) && ((*a - b) >= -low_parameter)) {
        *a = b;
    }
    else {
        if (*a < b)
            *a += high_parameter;
        if (*a > b)
            *a -= low_parameter;
    }
}

int main()
 {
    float now1 = 0, ref1 = 10;
    float high = 1, low = 1;
    float now2 = 20, ref2 = 10;

    ramp_t ramp1, ramp2;
    ramp_init(&ramp1, 100); 
    ramp_init(&ramp2, 200); 

    for (int i = 0; i < 100; i++) 
    {
        buffer(&now1, ref1, high, low);
        buffer(&now2, ref2, high, low);

        float out1 = ramp_calc(&ramp1);
        float out2 = ramp_calc(&ramp2);
        printf("Iteration %d: now1 = %.2f, now2 = %.2f, ramp1 = %.2f, ramp2 = %.2f\n",i, now1, now2, out1, out2);
    }

    return 0;
}