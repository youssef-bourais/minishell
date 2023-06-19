/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/06/19 15:05:33 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *commands(char **tab, t_node *head)
{

    if (compare(tab[0], "export"))
        head = export(tab, head);
    else if (compare(tab[0], "echo"))
        echo(tab);
    else if (compare(tab[0], "env"))
        env(head);
    else if (compare(tab[0], "unset") && tab[1])
        head = unset(tab, head);
    else
        printf("%s ERROR\n", tab[0]);
    return(head);
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *input;
    char **tab;
    int *arr;
    t_node *head = NULL;
  
    int i = 0;
    while (env[i])
        head = creat_list(head, env[i++]);

    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        add_history(input);
        arr = check_quoting(input);
        tab = split(input);
        modification(tab, 25, ' ');
        head = commands(tab, head);
        free_tab(tab);
    }
    return 0;
}
