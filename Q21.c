#include <stdio.h>

typedef struct 
{
    int max; 
} BackMax;

BackMax findMax(int *arr, int length) 
{
    BackMax BACK;
    BACK.max = arr[0];

    for (int i = 1; i < length; ++i) 
    {
        if (arr[i] > BACK.max) 
        {
            BACK.max = arr[i];
        }
    }

    return BACK;
}

int main() {
    int arr[] = {8, 11, 4, 2, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    int max;

    BackMax BACK = findMax(arr, length);
    max = BACK.max;

    printf("×î´óÖµ£º%d\n", max);

    return 0;
}

