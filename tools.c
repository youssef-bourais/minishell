/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:12:41 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/25 20:53:20 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_tab(char **tab, int n)
{
    int i = 0;
    while (i < n)
        free(tab[i++]);
    free(tab);
}

int nbr_words(char *str)
{
    int counter = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            counter++;
        i++;
    }
    return counter;
}

int word_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            return i + 1;
        i++;
    }
    return 0;
}

char **split(char *str)
{
    char **arr = malloc((sizeof(char *) * nbr_words(str)) + 1);

    int i = 0;
    int index = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ')
            i++;
        int j = 0;
        arr[index] = malloc((sizeof(char) * word_len(str + i)) + 1);
        while (str[i] != ' ' && str[i] != '\0')
        {
            arr[index][j] = str[i];
            j++;
            i++;
        }
        arr[index][j] = '\0';
        index++;
    }
    return arr;
}
