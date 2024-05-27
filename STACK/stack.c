#include <stdio.h>
#include <stdlib.h>
#define max 3
int arr[max];
int top = -1;

void push(int n);
int pop();
int isEmpty();
int isFull();
void print();
int main()
{
    int val, p_val, pop_val;

    do
    {
        printf("\n\n M E N U \n1. PUSH\n2. POP\n3. PRINT");
        scanf("%d", &val);

        switch (val)
        {
        case 1:
            printf("ENTER VALUE TO BE PUSHED ");
            scanf("%d", &p_val);
            push(p_val);
            break;
        case 2:
            pop_val = pop();
            printf("%d is popped \n", pop_val);
            print();
            break;
        case 3:
            print();
            break;
        default:
            printf("INVALID OPERATOR ENTERED ");
        }
    } while (val != 0);
    return 0;
}

void push(int n)
{
    if (!isFull())
    {
        arr[++top] = n;
    }
    else
        printf("stack is full");

    print();
}

int pop()
{
    if (!isEmpty())
    {
        return arr[top--];
    }
    else
        return -1;
    print();
}

int isFull()
{
    if (top+ 1>= max)
    {
        return 1;
    }
    else
        return 0;
}
int isEmpty()
{
    if (top < 0)
    {
        return 1;
    }
    else
        return 0;
}

void print()
{

    if (top < 0)
    {
        printf("not possibel to print ");
    }

    else
    {
        int i = top;
        while (i >= 0)
        {
            printf("|__%d__|%d\n", arr[i],i);
            i--;
        }
    }
}
