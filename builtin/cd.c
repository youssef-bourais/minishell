/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:34 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:27:45 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cd(char **tab, t_node *head) 
{
    char **env = from_list_to_tab(head);
    char *path;
    path = find_path(env, 4, "HOME");

    char cwd[1024];
    if(tab[0] && !tab[1])
    {
        head = change_env(head, getcwd(cwd, sizeof(cwd)), "OLDPWD=");
        chdir(path);
        head = change_env(head, getcwd(cwd, sizeof(cwd)), "PWD=");
    }
    else if(tab[0] && tab[1] && !tab[2])
    {
        head = change_env(head, getcwd(cwd, sizeof(cwd)), "OLDPWD=");
        chdir(tab[1]);
        head = change_env(head, getcwd(cwd, sizeof(cwd)), "PWD=");
    }
    else 
        perror("my_shell");
    free(path);
}

t_node *change_env(t_node *head, char *new, char *old)
{
    t_node *tmp;
    tmp = head;

    while (tmp)
    {
        if (compare_until(tmp->var, old, 4))
        {
            free(tmp->var);
            tmp->var = malloc(sizeof(char) * slen(new) +  slen(old) + 1);
            char *str = join(old, new);
            copy_str(tmp->var, str);
            free(str);
        }
        tmp = tmp->next;
    }
    return head;
}

char *find_path(char **env, int j, char *str)
{   
    char *paths = NULL;
    int i = 0;

    if(!env)
        return NULL;

    while (env[i])
    {
        if(compare_until(env[i], str, j))
        {
            paths = malloc(sizeof(char) * (slen(env[i]) + 1 - slen(str)));
            copy_str(paths, env[i] + 5);
            break;
        }
        i++;
    }
    return paths;
}

char **from_list_to_tab(t_node *head)
{
    char **tab;
    t_node *tmp;
    tmp = head;
    
    int i = 0;
    while (tmp)
    {
        tmp = tmp->next;
        i++;   
    }
    tab = malloc(sizeof(char *) * i + 1);
    tmp = head;
    i = 0;
    while (tmp)
    {
        tab[i] = malloc(sizeof(char) * slen(tmp->var) + 1);
        copy_str(tab[i], tmp->var);
        i++;
        tmp = tmp->next;
    }
    tab[i] = NULL;
    return tab;
}