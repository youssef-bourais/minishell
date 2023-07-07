/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:23:52 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:28:25 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void env(t_node *head)
{
    t_node *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        if(cheak_exist(tmp->var, '='))
        {
            printf("%s\n", tmp->var);
        }
        tmp= tmp->next;
    }
}

int cheak_exist(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}