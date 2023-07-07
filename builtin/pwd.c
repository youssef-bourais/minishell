/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:03 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:35:07 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(t_node *head)
{
    // t_node *curr;
    // curr = head;
    // while (curr)
    // {
    //     if (curr->var[0] == 'P' && curr->var[1] == 'W' && curr->var[2] == 'D')
    //     {
    //         printf("%s\n", curr->var + 4);
    //         return;
    //     }
    //     curr = curr->next;
    // }

    // (void)head;
    // if (getenv("PWD") != NULL)
    //     printf("%s\n", getenv("PWD"));

    (void)head;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) 
        printf("%s\n", cwd);
}

