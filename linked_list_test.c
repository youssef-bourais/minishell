
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

void delete_node(t_node *head, int value)
{
    t_node *curr;
    t_node *prev;

    curr = head;
    prev = head;

    if (curr->data == value)
    {
        head = curr->next;
        free(curr);
        return ;
    }

    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
}
 
int main()
{
    t_node *head = NULL;
    t_node *tmp;

    int i = 0;
    while (i < 30)
        head = inseart_node(head, i++);

    delete_node(head, 19);
 
    tmp = head;
    while (tmp != NULL)
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
}