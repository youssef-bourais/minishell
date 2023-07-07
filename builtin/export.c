/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:54 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:32:14 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_node *ft_export(char **tab, t_node *head)
{
    t_node *tmp;
    int i = 0;
    int p = 0;

    if (tab[0] && !tab[1])
    {
        tmp = head;
        while (tmp != NULL)
        {
            print_export(tmp->var);
            tmp= tmp->next;
        }
    }
    else
    {
        i = 1;
        while (tab[i])
        {
            if (is_alphanumeric(tab[i]) || without_equal(tab[i]))
            {
                head = search_list(head, tab[i], &p);
                if (!p)
                    head = creat_list(head, tab[i]);
            }
            else
                printf("my Shell: no matches found: %s\n", tab[i]);
            i++;
        }
    }
    return head;
}

t_node *search_list(t_node *head, char *str, int *p)
{
    t_node *tmp;
    tmp = head;

    while (tmp)
    {
        if (compare_until(tmp->var, str, strchrch(tmp->var, '=')))
        {
            head = replace_node(head, str, tmp->var);
            *p = 1;
            return head;
        }
        tmp = tmp->next;
    }
    *p = 0;
    return head;
}

t_node *replace_node(t_node *head, char *new, char *to_delete)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    new_node->var = malloc(sizeof(char) * slen(new) + 1);
    copy_str(new_node->var, new);

    t_node *curr;
    curr = head;
    if(compare(curr->var, to_delete))
    {
        new_node->next = head->next;
        head = new_node;
        free(curr->var);
        free(curr);
        return head;
    }
    t_node *prev;
    curr = head;
    prev = head;
    while (!compare(curr->var, to_delete))
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = new_node;
    new_node->next = curr->next;
    free(curr->var);
    free(curr);
    return head;
}

t_node *creat_list(t_node *head, char *env)
{
    t_node *new_node = malloc(sizeof(t_node));
    new_node->var = malloc(sizeof(char) * slen(env) + 1);
    copy_str(new_node->var, env);
    new_node->next = NULL;
    if(head == NULL)
        head = new_node;
    else
    {
        t_node *tmp = head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    return head;
}

void print_export(char *str)
{
    char begin[strchrch(str, '=') + 1];
    char after[slen(str) - strchrch(str, '=') + 1];
    
    int i = 0;
    while (str[i] != '=' && str[i] != '\0')
    {
        begin[i] = str[i];
        i++;
    }
    begin[i] = '\0';
    i = i + 1;
    int j = 0;
    while (str[i] != '\0')
    {
        after[j++] = str[i++];
    }
    after[j] = '\0';
    if(strchrch(str, '=') != slen(str))
        printf("declare -x %s=\"%s\"\n", begin, after);
    else
        printf("declare -x %s\n", begin);
}

int is_alphanumeric(char *str)
{
    int i = 0;
    if(str[0] == '=' || (str[0] >= 48 && str[0] <= 57))
        return 0;
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

int without_equal(char *str)
{
    int i = 0;
    while (str[i])
    {
        if(!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 95 || str[i] == ' '))
            return 0;
        i++;
    }
    return 1;
}