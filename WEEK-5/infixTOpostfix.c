#include <stdio.h>
#include <string.h>


#define MAX 50
char postfix[MAX];
char infix[MAX];
char stack[MAX];
int top = -1;
int j = 0;


void print();
int isEmpty();
int isFull();
void push(char ch);
char pop();
int prec(char ch);



int main()
{
    int val;

    do
    {
        printf("-----------\n");
        printf("ENTER PREFIX EXPRESSION : ");
        scanf("%s", infix);
        j = 0;

        char next;
        for (int i = 0; i < strlen(infix); i++)
        {

            char symbol = infix[i];

            switch (symbol)
            {
            case '(':
                if (!isFull())
                {
                    push(symbol);
                }
                else
                {
                    printf("STACK  IS FULL");
                    return 0;
                }

                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[j++] = next;
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':

                while (!isEmpty() && prec(stack[top]) >= prec(symbol))
                {

                    postfix[j++] = pop();
                }
                push(symbol);

                break;
            default:
            {
                postfix[j++] = symbol;
            }
            }
        }
        while (!isEmpty())
        {
            postfix[j++] = pop();
        }
        postfix[j] = '\0';

        print();

        printf("ENTER 1 TO CONTINUE , 0 TO EXIT ");
        scanf("%d", &val);
    } while (val != 0);
}

void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    if (!isEmpty())
    {
        return stack[top--];
    }
    else
    {
        printf("STACK IS EMPTY ");
        return '$';
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if (top >= MAX - 1)
    {
        return 1;
    }
    else
        return 0;
}

int prec(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void print()
{

    printf("POSTFIX EXPRESSION IS : ");
    for (int i = 0; i < j; i++)
    {
        printf("%c", postfix[i]);
    }
    printf("\n");
}