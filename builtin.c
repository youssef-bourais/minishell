/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:52:38 by ybourais          #+#    #+#             */
/*   Updated: 2023/06/19 15:05:18 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *export(char **tab, t_node *head)
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

void echo (char **tab)
{
    int i = 0;
    i = 1;
    while (tab[i])
    {
        printf("%s", tab[i]);
        if(tab[i][0] != ' ' && tab[i + 1])
            printf(" ");
        i++;
    }
    printf("\n");
}

void env(t_node *head)
{
    t_node *tmp;
    tmp = head;
    while (tmp != NULL && strchrch(tmp->var, '=') != slen(tmp->var))
    {
        printf("%s\n", tmp->var);
        tmp= tmp->next;
    }
}

t_node *unset(char **tab, t_node *head)
{
    int j = 1;
    while (tab[j])
    {
        head = unset_node(head, tab[j]);
        j++;
    }
    return head;
}