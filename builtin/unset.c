/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:23:05 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:35:59 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *unset(char **tab, t_node *head)
{
    int j = 1;
    while (tab[j])
    {
        if(is_alphanumeric(tab[j]) || without_equal(tab[j]))
            head = unset_node(head, tab[j]);
        else
            printf("my Shell: no matches found: %s\n", tab[j]);
        j++;
    }
    return head;
}

t_node *unset_node(t_node *head, char *to_delete)
{
    t_node *curr;
    t_node *prev;

    curr = head;
    prev = head;

    if(!find_value(head, to_delete))
        return head;
    else
    {
        if(compare_len(to_delete, curr->var))
        {
            head = curr->next;
            free(curr->var);
            free(curr);
            return head;
        }
        while (!compare_len(to_delete, curr->var))
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr->var);
        free(curr);
        return head;
    }
    return head;
}
