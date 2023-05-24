/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:05:20 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/24 14:38:33 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int appear_first(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 34)
            return 2;
        if (str[i] == 39)
            return 1;
        i++;
    }
    return 0;
}

int inside_quot(char *str, int i, int p, char *token)
{
    while (str[i] != p)
    {
        token[i] = str[i];
        i++;
    }
    return i;
}

void ft_error(int n)
{
    if(n == 1)
    {
        write(n, "Error\n", 6);
        exit(0);
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
