/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:05:20 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/27 17:06:37 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_error(int n)
{
    if(n == 1)
    {
        write(n, "Error\n", 6);
        exit(n);
    }
}

void check_quoting(char *str)
{
    int i;
    int j = 0;
    int quote;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != 34 && str[i] != 39)
            str[j] = str[i];
        else if(str[i] == 34 || str[i] == 39)
        {
            quote = str[i++];
            if (quote == 34 && str[i] == 34 && str[i + 1] == ' ')
                str[j++] = 25;
            while (str[i] != quote)
            {
                if(str[i] == '\0')
                    ft_error(1);
                str[j++] = str[i++];
            }
            j--;
        }
        i ++;    
        j ++;
    }
    str[j] = '\0';
}

void modification(char **tab, int n, int t)
{
    int i = 0;
    while (tab[i] != NULL)
    {
        int j = 0;
        while (tab[i][j] != '\0')
        {
            if (tab[i][j] == n)
            {
                tab[i][j] = t;
            }
            j++;
        }
        i++; 
    }
}