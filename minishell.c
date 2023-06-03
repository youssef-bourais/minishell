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

int is_alphanumeric(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '=')
        {
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

void copystr(char *dst, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

t_var *store_variabl(char *input)
{
    t_var *new_node = malloc(sizeof(t_var));
    new_node->var = malloc((slen(input) + 1) * sizeof(char));

    copystr(new_node->var, input);
    new_node->next = NULL;

    return new_node;
}

int main()
{
    char *input;
    int *arr;
    char **tab;
    int i = 0;

    t_var *temp;
    t_var *head = NULL;
    t_var *current;

    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        add_history(input);
        // valid_dollar(input);// nbr $
        arr = check_quoting(input);
        if (is_alphanumeric(input))
        {
            temp = store_variabl(input);
            temp->next = head;
            head = temp;
        }
        else
        {
            tab = split(input);
            modification(tab, 25, ' ');
            i = 0;
            while (tab[i] != NULL)
            {
                printf("%s\n", tab[i++]);
            }
            free_tab(tab);
        }
        current = head;
        while (current != NULL) 
        {
            printf("%s->", current->var);
            current = current->next;
        }
    }
    current = head;
    while (current != NULL) 
    {
        t_var* temp = current;
        current = current->next;
        free(temp->var);
        free(temp);
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node
// {
//     int value;
//     struct node *next;
// } t_node;


// void printlist(t_var *head)
// {
//     t_var *tmp = head;
//     while (tmp != NULL)
//     {
//         printf("%s->", tmp->value);
//         tmp = tmp->next;
//     }
//     printf("\n");
// }

// void free_list(t_var* head) 
// {
//     t_var* current = head;

//     while (current != NULL) 
//     {
//         t_var* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

// t_var *creat_node(char *str)
// {
//     t_var *v = malloc(sizeof(t_var));
//     v->var = malloc(sizeof(char)* slen(str) + 1);
//     copystr(v->var, str);
//     v->next = NULL;
//     return v;
// }

// int main()
// {
//     t_var *head = NULL;
//     t_var *temp;

//     int i = 0;
//     while (i < 25)
//     {
//         temp = creat_node("i + '0'"); // creat node and the node.next point to null
//         temp->next = head; // the next node point to head (null) in i = 0; or 23 in i = 24
//         head = temp; // the head point to temp; head is i = 0...24;
//         i++;
//     }
//     printlist(head);
//     free_list(head);
// }
