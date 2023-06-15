
# include <stdlib.h>
# include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} t_node;

t_node *creat_node(t_node *head, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL)
    {    
        head = new_node;
    }
    else
    {
        t_node *tmp;
        tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    return head;
}

void print_list(t_node *head)
{
    t_node *tmp;
    tmp = head;
    while (tmp)
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int find_in(t_node *head, int value)
{
    t_node *tmp;
    tmp = head;
    while (tmp)
    {
        if (tmp->data == value)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

t_node *unset_node(t_node *head, int value)
{
    if(!find_in(head, value))
        return head;
    else
    {
        if (head->data == value)
        {
            t_node *first = head;
            head = first->next;
            free(first);
            return head;
        }
        t_node *tmp;
        t_node *prev;;
        tmp = head;
        prev = head;
        while (tmp->data != value)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = tmp->next;
        free(tmp);
        return head;
    }
    return head;
}

t_node *replace_node(t_node *head, int del, int new)
{
    if (!find_in(head, del))
        return head;
    else
    {
        t_node *new_node = malloc(sizeof(t_node));
        new_node->data = new;

        t_node *curr;
        t_node *prev;
        curr = head;
        prev = head;
        while (curr->data != del)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = new_node;
        new_node->next = curr->next;
        free(curr);
        return head;
    }
    return head;
}

t_node *add_back(t_node *head, int value)
{
    head = creat_node(head, value);
    return head;
}

t_node *add_front(t_node *head, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = value;

    t_node *tmp;
    tmp = head;
    head = new_node;
    new_node->next = tmp->next;
    return head;
}

t_node *add_between(t_node *head, int value1, int value2, int add)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->data = add;

    t_node *curr;
    curr = head;
    while (curr->data != value1)
        curr = curr->next;

    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

int main()
{
    t_node *head = NULL;

    int i = 0;
    while (i < 30)
        head = creat_node(head, i++);

    printf("my list                                 = ");
    print_list(head);

    head = unset_node(head, 5);
    printf("my list after deleting one elem         = ");
    print_list(head);

    head = replace_node(head, 26, 76);
    printf("my list after replacing one elem        = ");
    print_list(head);
    
    head = add_back(head, 2023);
    printf("my list after adding one elem at end    = ");
    print_list(head);

    head = add_front(head, -2023);
    printf("my list after adding one elem at front  = ");
    print_list(head);
    
    head = add_between(head, 6, 7, 1000);
    printf("my list after adding one elem in midlle = ");
    print_list(head);
}
