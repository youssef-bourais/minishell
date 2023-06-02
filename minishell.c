// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   minishell.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
// /*   Updated: 2023/06/02 16:05:44 by ybourais         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

int search(char *str, int c)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int is_alphanumeric(char *str, int *p)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '=')
        {
            *p = i + 1;
            i = 0;
            while (str[i] != '=')
            {
                if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 95 || str[i] == ' ')) // (48 -> 57) && (65 -> 90) && (97 -> 122) && 95(underscor) && 91(equal)                       
                    return 0;
                i++;
            }
            break;
        }
        i++;
    }
    if (str[i + 1] == ' ' || !search(str, '='))
        return 0;
    return 1;
}

int *ornot(char *str, int t)
{
    
    int *arr = malloc(sizeof(int) * t);
    int j = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '$')
        {
            if (str[i - 1] == '\'')
            {
                arr[j] = 0;
                j++;
            }
            else if (str[i - 1] == '\"')
            {
                arr[j] = 1;
                j++;
            }
            i++;
        }
    }
    return arr;    
}

int slen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

typedef struct  Node 
{
    char *var;
    struct Node *next;
}               Node;

int main()
{
    char *input;
    int *arr;
    // char **tab;
    int i = 0;
    // int j = 0;
    int k = 0;
    Node *head = NULL;
    Node *current = NULL;

    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        add_history(input);
        // valid_dollar(input);// nbr $
        arr = check_quoting(input);

        if (is_alphanumeric(input, &k))
        {
            Node *new_node = malloc(sizeof(Node));
            new_node->var = malloc((slen(input) + 1) * sizeof(char));
            strcpy(new_node->var, input);
            new_node->next = NULL;
            if (head == NULL) 
            {
                head = new_node;
                current = new_node;
            } 
            else 
            {
                current->next = new_node;
                current = new_node;
            }    
            printf("%s\n", new_node->var);
        }
        // else
        // {
        //     tab = split(input);
        //     modification(tab, 25, ' ');
        //     i = 0;
        //     while (tab[i] != NULL)
        //     {
        //         printf("%s\n", tab[i++]);
        //     }
        //     free_tab(tab);
        // }
    }
    // Print the linked list for verification
    current = head;
    while (current != NULL) 
    {
        printf("%s ", current->var);
        current = current->next;
    }

    // // Free allocated memory
    // current = head;
    // while (current != NULL) 
    // {
    //     Node* temp = current;
    //     current = current->next;
    //     free(temp->var);
    //     free(temp);
    // }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int value;
//     struct node *next;
// } t_node;

// t_node *creat_node(int value)
// {
//     t_node *v = malloc(sizeof(t_node));
//     v->value = value;
//     v->next = NULL;
//     return v;
// }

// void printlist(t_node *head)
// {
//     t_node *tmp = head;
//     while (tmp != NULL)
//     {
//         printf("%d->", tmp->value);
//         tmp = tmp->next;
//     }
//     printf("\n");
// }

// void free_list(t_node* head) 
// {
//     t_node* current = head;

//     while (current != NULL) 
//     {
//         t_node* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

// int main()
// {
//     t_node *head = NULL;
//     t_node *temp;

//     int i = 0;
//     while (i < 25)
//     {
//         temp = creat_node(i); // creat node and the node.next point to null
//         temp->next = head; // the next node point to head (null) in i = 0; or 23 in i = 24
//         head = temp; // the head point to temp; head is i = 0...24;
//         i++;
//     }

//     printlist(head);
//     free_list(head);
// }
