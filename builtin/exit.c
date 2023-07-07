/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:23:27 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:28:56 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exit(char **tab)
{
    if(tab[0] && !tab[1])
    {
        write(1, "exit\n", 5);
        exit(0);
    }
    else if(tab[0] && tab[1] && !tab[2])
    {
        int handler = 1;
        int num = a_toi(tab[1], &handler);
        if(handler == 0)
        {
            write(1, "exit\n", 5);
            perror("my_shell:numeric argument required");
            exit(1);
        }
        else
        {
            write(1, "exit\n", 5);
            exit(num);
        }
    }
    else if(tab[0] && tab[2])
        perror("exit: too many argument");
}