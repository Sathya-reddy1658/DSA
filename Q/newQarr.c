#include <stdio.h>
#define MAX 20

int Q[MAX], front = -1, rear = -1;

void en_q();
void de_q();
void print();
int isEmpty();
int isFull();

int main()
{
    int value;
    char ch;
    do
    {
        printf("Operations available:\n1 - Enqueue\n2 - Dequeue\n3 - Print\n4 - Exit\n");
        printf("Enter your choice:");
        scanf("%d", &value);
        switch(value)
        {
            case 1:
                en_q();
                break;
            case 2:
                de_q();
                break;
            case 3:
                print();
                break;
            case 4:
                return;
            default:
                printf("Invalid Choice!\n");
        }
        printf("Would you like to continue(Y/N)?:\n");
        scanf("%s", &ch);
    } while (ch=='y'||ch=='Y');
}

int isEmpty()
{
    if(rear == -1)
        return 1;
    return 0;
}

int isFull()
{
    if(front == 0 && rear == MAX-1 || front == rear+1)
        return 1;
    return 0;
}

void en_q()
{
    if(isFull())
        printf("Queue is Full\n");
    else
    {
        int val;
        printf("Enter the value to insert: ");
        scanf("%d", &val);
        if(front == -1)
        {
            front = 0;
        }
        rear = (rear + 1)%MAX;
        Q[rear] = val;
    }
}
void de_q()
{
    if(isEmpty())
        printf("Queue is Empty!\n");
    else
    {
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%MAX;
        }

    }
}
void print()
{
    if(isEmpty())
        printf("Queue is Empty\n");
    else
    {
        printf("The values in the Queue are: \n");
        for(int i = front; i <= rear; i++)
        {
            printf("%d\t", Q[i]);
        }
        printf("\n");
    }
}