#include <stdio.h>
> 注意：不准在这给变量赋值，只可给函数声明！
int main() {
    int nowspeed = 5000, maxspeed = 4000;
    //请插入一个void函数 ↓

    limitSpeed(&nowspeed);

    //请在此插入一个函数 ↑
    printf("nowspeed的值：%d\n", nowspeed);

    return 0;
}

void limitSpeed(int *nowspeed) 
{
    if (*nowspeed > 4000) 
    {
        *nowspeed = 4000;
    }
    else if (*nowspeed < -4000) 
    {
        *nowspeed = -4000;
    }
}
