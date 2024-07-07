#include <stdio.h>
#include <stdint.h>

//返回值 uwTick 为当前系统运行时间
float HAL_GetTick(void) 
{
    static uint32_t uwTick = 0;
    uwTick++;
    return (float)uwTick;
}

int main() {
    float lasttime = 0.0;

    while (1) {
        float Realtime = HAL_GetTick(); 

        float differtime = Realtime - lasttime;

        if (differtime >= 1.0) {
            printf("Hello, world !\n");
            lasttime = realtime;
        }
    }

    return 0;
}
