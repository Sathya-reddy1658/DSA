#include <stdio.h>
#include <stdlib.h>

struct node_circ
{
  int data;
  struct node *ptr;
};
struct node_circ *start, *temp, *newnode;
void create();
int main()
{
  create();
}
void create()
{
  int n;
  printf("enter no of nodes : ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    newnode = (struct node_circ *)malloc(sizeof(struct node_circ));
  }
}