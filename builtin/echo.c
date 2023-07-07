/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:57 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:28:03 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void echo_n (char **tab)
{
    int i = 0;
    i = 2;
    while (tab[i])
    {
        printf("%s", tab[i]);
        if(tab[i][0] != ' ' && tab[i + 1])
            printf(" ");
        i++;
    }
}