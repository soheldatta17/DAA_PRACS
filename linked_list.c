#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int data;
} *head, *current;
void displayNode()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}
void createNode(int n)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = n;
    if (head == NULL)
    {
        head = newnode;
        head->next = NULL;
        current = head;
    }
    else
    {
        current->next = newnode;
        current->next->next = NULL;
        current = newnode;
    }
}
void main()
{
    int n, i;
    printf("Enter the number of Nodes: ");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++)
    {
        createNode(i);
    }
    printf("\nThe nodes are :\n");
    displayNode(i);
}