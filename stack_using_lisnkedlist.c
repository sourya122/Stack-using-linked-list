#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nThe stack is overflow.\n");
        return;
    }
    ptr->data = data;
    ptr->next = *top;
    *top = ptr;
    printf("\nThe data is inserted.\n");
}

int pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("\nThe stack is empty.\n");
        return -1;
    }
    struct node *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void display(struct node *top)
{
    if (top == NULL)
    {
        printf("\nThe stack is empty.\n");
        return;
    }
    printf("\nPrinting the data from the stack.\n");
    while (top != NULL)
    {
        printf("ELEMENT:%d\n", top->data);
        top = top->next;
    }
}

int main()
{
    struct node *top = NULL;
    int choice, value;
    while (1)
    {
        printf("\nSelect an option from the following.\n");
        printf("\n1.Push a data.\n");
        printf("\n2.Pop a data.\n");
        printf("\n3.Peek.\n");
        printf("\n4.Display the stack.\n");
        printf("\n5.Exit.\n");
        printf("\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data: \n");
            scanf("%d", &value);
            push(&top, value);
            break;
        case 2:
            value = pop(&top);
            if (value != -1)
                printf("\nPopping the data from the top is %d\n", value);
            break;
        case 3:
            printf("\nPeeking the top data: ");
            if (top != NULL)
                printf("%d\n", top->data);
            else
                printf("Stack is empty.\n");
            break;
        case 4:
            display(top);
            break;
        case 5:
            printf("\nExiting from the stack.\n");
            exit(0);
        default:
            printf("\nWrong choice please enter again.\n");
            break;
        }
    }
    return 0;
}
