
# include <stdlib.h>
# include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} t_node;

t_node *inseart_node(t_node *head, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = value;
    new_node->next = NULL;
    t_node *last;

    if (head == NULL)
        head = new_node;
    else
    {   
        last = head; // POINT TO THE FIRST NODE;
        while (last->next != NULL) // 
            last = last->next;
        last->next = new_node;
    }
    return head;
}

t_node *delete_node(t_node *head, int value)
{
    t_node *curr;
    t_node *prev;
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = 200;


    curr = head;
    prev = head;

    if (curr->data == value)
    {
        head = curr->next;
        free(curr);
        return head;
    }
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = new_node;
    new_node->next = curr->next->next;
    free(curr);
    return head;
}

int main()
{
    t_node *head = NULL;
    t_node *tmp;

    int i = 0;
    while (i < 30)
        head = inseart_node(head, i++);

    head = delete_node(head, 18);

    tmp = head;
    while (tmp != NULL)
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}