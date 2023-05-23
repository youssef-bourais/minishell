/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:05:20 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/23 20:12:39 by ybourais         ###   ########.fr       */
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
        // printf("%c", str[i++]);
    }
    return i;
}

void check_quoting(char *str)
{
    int i;
    int j = 0;
    char token[100];
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != 34 && str[i] != 39)
            token[j] = str[i];
        else if(str[i] == 34)
        {
            i = i + 1;
            while (str[i] != 34)
                token[j++] = str[i++];
            j--;
        }
        else if(str[i] == 39)
        {
            i = i + 1;
            while (str[i] != 39)
                token[j++] = str[i++];           
            j--;
        }
        i ++;    
        j ++;    
    }
    token[j] = '\0';
    printf("%s\n", token);
    
}

// i = inside_quot(str, i + 1, 34, token); /* double quot */
// i = inside_quot(str, i + 1, 39, token); /* single quot */
// void parssing(char *str)
// {

// }