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
    int ch, n, i;
    printf("\n");
    printf("Enter your choice:\n 1) Enter 1 to add a new node\n 2) Enter 2 to display all the nodes\n 3) Enter 3 to Quit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter the value: ");
        scanf("%d", &n);
        createNode(n);
        printf("\n");
        main();
        break;
    case 2:
        printf("The nodes are: \n");
        displayNode();
        printf("\n");
        main();
        break;
    case 3:
        break;
    default:
        printf("Wrong Choice");
        main();
    }
}