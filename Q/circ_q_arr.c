#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int Q[MAX];
int rear = 0, front = -1;
int en_q(int val);
int de_q();
void print();
int isFull();
int isEmpty();
int main()
{
    int val, p_val, pop_val;

    do
    {
        printf("\n\n M E N U \n1. PUSH\n2. POP\n3. PRINT\n\n");
        scanf("%d", &val);

        switch (val)
        {
        case 1:
            printf("ENTER VALUE TO BE PUSHED ");
            scanf("%d", &p_val);
            en_q(p_val);

            break;
        case 2:
            pop_val = de_q();
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

int en_q(int val)
{

    if (isFull())
    {
        printf("Q IS FULL");
        return 0;
    }
    else
    {
        if (front == -1)
        {
            Q[rear++] = val;
            front++;
        }
        else if (rear >= MAX)
        {
            Q[((rear) % MAX)] = val;
            rear++;
        }
        else
        {
            Q[rear++] = val;
        }
    }
    print();
}
int de_q()
{

    if (isEmpty())
    {
        printf("q is empty");
    }
    else
    {
        int val = Q[front];
        if ((front + 1) == rear)
        {
            front = -1, rear = 0;
        }
        else
            front++;

        return val;
    }
}

void print()
{
    int j;
    if (isEmpty())
    {
        printf("Q IS EMPTY ");
    }
    else
    {
        for (int i = front; i < rear; i++)
        {   
            if (i <MAX)
            {
                j = i;
            }
            else
               { j = i % MAX;}

            printf("|__%d__|\n", Q[j]);
        }
    }
}

int isFull()
{

    if (front == (rear) % MAX || (front == 0 && rear == MAX))
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    else
        return 0;
}