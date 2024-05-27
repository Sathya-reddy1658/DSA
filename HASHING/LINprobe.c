#include <stdio.h>
#include <stdlib.h>
int arr[100];
int check[100];
void insert(int val);
int size, n = 0, val, size2, flag, l = 0;
void print();
int isPrime(int n);
int main()
{
    char ch;
    int choice;
    printf("ENTER TABLE SIZE (any prime <100) : ");
    scanf("%d", &size);

    do
    {
        printf("1. insert\n2. print");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            if (n != size)
            {
                if (n >= 0.50 * size)
                {
                    size2 = 2 * size;
                    while (!isPrime(size2))
                    {
                        size2++;
                    }

                    for (int i = 0; i < size; i++)
                    {
                        arr[i] = 0;
                    }

                    size = size2;
                    int n1 = n;
                    n = 0;
                    l = 0;
                    for (int i = 0; i < n1; i++)
                    {
                        insert(check[i]);
                    }
                    print();
                }

                printf("ENTER VALUE TO BE INSERTED ");
                scanf("%d", &val);
                insert(val);
            }
            else
            {
                printf("STACK IS FULL\n");
            }
            break;
        }
        case 2:
            print();
        default:
            printf("invalid operator ");
        }
        printf("\nDo you want to continue : ");
        scanf("%s", &ch);
    } while (ch == 'Y' || ch == 'y');
}

void insert(int val)
{

    int idx;

    idx = val % size;

    while (arr[idx] != 0)
    {
        idx = (idx + 1) % size;
    }

    arr[idx] = val;
    check[l++] = val;
    n++;
}
void print()
{ 
    for (int i = 0; i < size; i++)
    {
        printf(" [%d] : %d\n", i, arr[i]);
    }
}

int isPrime(int n)
{
    int cnt = 0;
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
    }
    if (!cnt)
    {
        return 1;
    }
    else
        return 0;
}
