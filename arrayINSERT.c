#include <stdio.h>
int main()
{

    int idx, val;
    int arr[50] = {1, 2, 3, 4};
    scanf("%d", &idx);

    for (int i = 3; i >= idx; i--)
    {

        arr[i + 1] = arr[i];
    }
    scanf("%d", &val);
    arr[idx] = val;

    for (int i = 0; i < 5; i++)
    {
        printf(" \n%d", arr[i]);
    }
}
