#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *ptr;
};
struct stack *top = NULL, *newnode, *temp;
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
    newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->data = val;
    newnode->ptr = NULL;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->ptr = top;
        top = newnode;
    }
    print();
}

int pop()
{
    if (top == NULL)
    {
        printf("STACK IS EMPTY");
    }
    else
    {
        temp = top;
        top = top->ptr;
        int val = temp->data;
        free(temp);
        return val;
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
        while (temp != NULL)
        {
            printf("|__%d__|\n", temp->data);
            temp = temp->ptr;
        }
    }
}
