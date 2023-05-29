/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/29 18:51:06 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_alphanumeric(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '=')
        {
            i = 0;
            while (str[i] != '=')
            {
                if (!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 95 || str[i] == ' ')) // (48 -> 57) && (65 -> 90) && (97 -> 122) && 95(underscor) && 91(equal)                       
                    return 0;
                i++;
            }
            break;
        }
        i++;
    }
    if (str[i + 1] == ' ')
        return 0;   
    return 1;
}

int *ornot(char *str, int t)
{
    
    int *arr = malloc(sizeof(int) * t);
    int j = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '$')
        {
            if (str[i - 1] == '\'')
            {
                arr[j] = 0;
                j++;
            }
            else if (str[i - 1] == '\"')
            {
                arr[j] = 1;
                j++;
            }
            i++;
            
        }
        
    }
    return arr;    
}

int main()
{
    char *input;
    int *arr;
    int **tab;

    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        add_history(input);
        valid_dollar(input);// nbr $
        arr = check_quoting(input); // struct {arr of dollar in "" and '', the string parssed}
        modification(tab, 25, ' ');
        tab = split(input);
        // int i = 0;
        // i = 0;
        // while (tab[i] != NULL)
        //     printf("%s\n", tab[i++]);
        // free_tab(tab);
    }
    return 0;
}
