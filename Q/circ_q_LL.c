#include <stdio.h>
#include <stdlib.h>
struct Q
{
    int data;
    struct Q *ptr;
};
struct Q *top = NULL, *newnode, *temp, *rear = NULL;
void push(int val);
void print();
int pop();
int main()
{
    int val, p_val, pop_val;
    do
    {
        printf("\n\n M E N U \n1. PUSH\n2. POP\n3. PRINT\n\nchoice : ");
        scanf("%d", &val);

        switch (val)
        {
        case 1:
            printf("ENTER VALUE TO BE PUSHED : ");
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

void push(int val)
{
    newnode = (struct Q *)malloc(sizeof(struct Q));
    newnode->data = val;
    newnode->ptr = NULL;
    if (top == NULL)
    {
        rear = top = newnode;
        rear->ptr = newnode;
    }
    else
    {
        rear->ptr = newnode;
        rear = newnode;
        rear->ptr = top;
    }
    print();
}

int pop()
{
    if (top == NULL)
    {
        printf("Q IS EMPTY\n");
        return -1;
    }

    else
    {
        if (top->ptr == top)
        {
            top = rear = NULL;
        }
        else
        {
            temp = top;
            int val = top->data;
            top = top->ptr;
            rear->ptr = top;
            free(temp);
            return val;
        }
    }
}

void print()
{
    temp = top;
    if (top == NULL)
    {
        printf("STACK IS EMPTY ");
    }
    else
    {

        do
        {

            printf("|__%d__|\n", temp->data);
            temp = temp->ptr;

        }

        while (temp != top);
    }
}
