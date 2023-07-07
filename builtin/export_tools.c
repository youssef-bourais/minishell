/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:32:29 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:34:31 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int find_value(t_node *head, char *str)
{
    t_node *curr;
    t_node *after;

    curr = head;
    after = head;

    while (curr)
    {
        if(!compare_len(str, curr->var))
        {
            after = curr;
            curr = after->next;
        }
        else
            return 1;
    }
    return 0;
}

int compare_until(char *s1, char *s2, int n)
{
    int i;
    i = 0;
    while (i < n)
    {
        if (s1[i] == s2[i])
            i++;
        else
            return 0;
    }
    return 1;
}

int strchrch(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return i;
        i++;
    }
    return slen(str);
}

void copy_str(char *dst, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

int compare(char *s1, char *s2)
{
    int i = 0;

    if(!s1)
        return 0;
    if(slen(s1) != slen(s2))
        return 0;
    while (s1[i] && s1[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

int compare_len(char *to_delete, char *list_var)
{
    char str[slen(list_var)];
    int indice = strchrch(list_var, '=');
    int i = 0;
    while (i < indice)
    {
        str[i] = list_var[i];
        i++;
    }
    str[i] = '\0';
    if(slen(str) != slen(to_delete))
        return 0;
    else
        if(compare(to_delete, str))
            return 1;
    return 0;
}
