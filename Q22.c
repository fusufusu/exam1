#include <stdio.h>
> ע�⣺��׼�����������ֵ��ֻ�ɸ�����������
int main() {
    int nowspeed = 5000, maxspeed = 4000;
    //�����һ��void���� ��

    limitSpeed(&nowspeed);

    //���ڴ˲���һ������ ��
    printf("nowspeed��ֵ��%d\n", nowspeed);

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
