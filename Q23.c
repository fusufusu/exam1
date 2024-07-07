
#include <stdio.h>

typedef enum 
{
    GIMBAL_INIT_NEVER,
    GIMBAL_INIT_DONE,
    NO_ACTION,
    IS_ACTION
} gimbal_state_t;

int main() 
{
    gimbal_state_t gimbal_state = GIMBAL_INIT_DONE;

    switch (gimbal_state) 
    {
        case GIMBAL_INIT_NEVER:
            printf("当前状态的枚举值：GIMBAL_INIT_NEVER\n");
            break;
        case GIMBAL_INIT_DONE:
            printf("当前状态的枚举值：GIMBAL_INIT_DONE\n");
            break;
        case NO_ACTION:
            printf("当前状态的枚举值：NO_ACTION\n");
            break;
        case IS_ACTION:
            printf("当前状态的枚举值：IS_ACTION\n");
            break;
        default:
            printf("未知状态\n");
    }

    return 0;
}
