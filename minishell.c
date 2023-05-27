/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/27 17:08:06 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    char *input;
    char **tab;

    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        add_history(input);
        check_quoting(input);
        tab = split(input);
        int i = 0;
        modification(tab, 25, ' ');
        i = 0;
        while (tab[i] != NULL)
            printf("%s\n", tab[i++]);
        free_tab(tab);
    }
    return 0;
}
