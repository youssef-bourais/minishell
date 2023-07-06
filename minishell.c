/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/06 18:00:32 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_value_dollar(t_node *head, char *str)
{
    t_node *curr;
    t_node *after;

    curr = head;
    after = head;

    while (curr)
    {
        if(!compare_len(str, curr->var))
        {
            after = curr;
            curr = after->next;
        }
        else
        {
            int indice = strchrch(curr->var, '=') + 1;
            char *find = malloc(sizeof(char) * (slen(curr->var) - indice) + 1);
            int i = 0;
            while (i < slen(curr->var) - indice)
            {
                find[i] = curr->var[indice + i];
                i++;
            }
            find[i] = '\0';
            return find;
        }
    }
    return NULL;
}

char **resize_and_find(char **tab, t_node *head, int i)
{
    char str[slen(tab[i])];
    int j = 0;
    while (j < slen(tab[i]) - 1)
    {
        str[j] = tab[i][j + 1];
        j++;
    }
    str[j] = '\0';
    if(find_value(head, str))
    {
        free(tab[i]);
        tab[i] = find_value_dollar(head, str);
    }
    else
    {
        free(tab[i]);
        tab[i] = malloc(sizeof(char));
        copy_str(tab[i], " ");
    }
    return tab;
}

// char **tab_mod(char **tab)
// {
//     char **table;
//     int counter = 0;
//     int i = 0;
//     while (tab[i])
//     {
//         if (tab[i] == ' ' || tab[i] == '$' || tab[i] == '.')
//             counter ++;
//         i++;
//     }
//     table = malloc(sizeof(char *) * counter + 1);
    
// }

char **var_expantion(int *arr, char **tab, t_node *head)
{
    int i = 0;
    int k = 0;

    // while(tab[i])
    // {
    //     printf("%s\n", tab[i++]);
    // }
    // copy_tab();
    // exit(0);
    i = 1;
    while (tab[i])
    {
        if(search(tab[i], '$') && arr[k] == 34)
        {
            k++;
            tab = resize_and_find(tab, head, i);
        }
        else if(search(tab[i], '$') && arr[k] == -1)
        {
            k++;
            tab = resize_and_find(tab, head, i);
        }
        else if(search(tab[i], '$') && arr[k] == 39 )
            k++;
        i++;
    }
    return tab;
}

t_node *commands(char **tab, t_node *head, int *arr)
{
    (void)arr;
    modification(tab, 25, ' ');
    tab = var_expantion(arr, tab, head);
    if (compare(tab[0], "export"))
        head = ft_export(tab, head);
    else if (compare(tab[0], "echo") && !compare(tab[1], "-n"))
        echo(tab);
    else if (compare(tab[0], "echo") && compare(tab[1], "-n"))
        echo_n(tab);
    else if (compare(tab[0], "env"))
        env(head);
    else if (compare(tab[0], "unset") && tab[1])
        head = unset(tab, head);
    else if (compare(tab[0], "pwd") && !tab[1])
        pwd(head);
    else if (compare(tab[0], "exit"))
        exit(0);
    else
        printf("%s ERROR\n", tab[0]);
    return(head);
}

t_node *creat_env(t_node *head, char **env)
{
    int i = 0;
    while (env[i])
        head = creat_list(head, env[i++]);
    return head;
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *input;
    char **tab;
    int *arr = {0};
    t_node *head = NULL;

    head = creat_env(head, env);
    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        if(!input)
        {
            printf("\n");
            break;
        }
        if(input[0] == '\0')
        {
            free(input);
            continue;
        }
        add_history(input);
        arr = check_quoting(input);
        tab = split(input);
        head = commands(tab, head, arr);
        free_tab(tab);
        free(input);
    }
    return 0;
}

// int main()
// {
//     // int execve(const char *path, char *const argv[], char *const envp[]);

//     char *cmd = "/bin/";
//     char *argv[] = {"./test", NULL};
//     char *env[] = {"red", "bleu", NULL};
    
//     execve(cmd, argv, NULL);
//     printf("helll\n");
// }