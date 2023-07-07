/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:39:41 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:42:02 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exucution(int *arr ,char **tab, t_node *head)
{
    char **env = from_list_to_tab(head);
    char **paths;
    char *path;
    int i = 0;
    exit_status();
    path = find_path(env, 4, "PATH");
    paths = split(path, ':');

    i = 0;
    int pid = fork();

    if(pid == 0)
    {
        if(tab[0][0] == '/' || tab[0][0] == '.')
            execve(tab[0], tab, env);
        else
        {
            i = 0;
            tab = var_expantion(arr, tab, head, 0);
            while (paths[i])
            {
                char *cmd_slash = join(paths[i], "/");
                char *cmd = join(cmd_slash, tab[0]);
                free(cmd_slash);
                if(execve(cmd, tab, env) == -1)
                    free(cmd);
                i ++;
            }
            write(2, "command not found\n", 18);
            exit(1);
        }       
    }
    wait(NULL);
    free_tab(env);
    free(path);
    free(paths);
}

char **var_expantion(int *arr, char **tab, t_node *head, int h)
{
    int i = 0;
    int k = 0;

    i = h;
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

t_node *commands(char **tab, t_node *head, int *arr)
{
    (void)arr;
    modification(tab, 25, ' ');
    tab = var_expantion(arr, tab, head, 1);
    if (compare(tab[0], "export"))
        head = ft_export(tab, head);
    else if (compare(tab[0], "echo") && !compare(tab[1], "-n"))
        echo(tab);
    else if (compare(tab[0], "echo") && compare(tab[1], "-n"))
        echo_n(tab);
    else if (compare(tab[0], "env") && !tab[1])
        env(head);
    else if (compare(tab[0], "unset") && tab[1])
        head = unset(tab, head);
    else if (compare(tab[0], "pwd"))
        pwd(head);
    else if (compare(tab[0], "exit"))
        ft_exit(tab);
    else if (compare(tab[0], "cd"))
        cd(tab, head);
    else// env ls (ls exucute)
        exucution(arr, tab, head);
    return(head);
}