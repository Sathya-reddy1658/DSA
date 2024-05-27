#include <stdio.h>
int main()
{

    int idx, val;
    int arr[] = {1, 2, 3, 4};
    scanf("%d", &idx);

    for (int i = idx; i<3; i++)
    {

        arr[i] = arr[i+1];
    }

    for (int i = 0; i < 3; i++)
    {
        printf(" \n%d", arr[i]);
    }
}
