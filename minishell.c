// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   minishell.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
// /*   Updated: 2023/06/02 16:05:44 by ybourais         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

int search(char *str, int c)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

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
    if (str[i + 1] == ' ' || !search(str, '='))
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

int slen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void copy_str(char *dst, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

// t_var *store_variabl(char *input)
// {
//     t_var *new_node = malloc(sizeof(t_var));
//     new_node->var = malloc((slen(input) + 1) * sizeof(char));

//     copy_str(new_node->var, input);
//     new_node->next = NULL;

//     return new_node;
// }

// char *join(char *s1, char *s2)
// {
//     char *str = malloc(sizeof(char) * (slen(s1) + slen(s2) + 1));

//     copy_str(str, s1);
//     copy_str(str + slen(s1), s2);
//     return str;
// }

// void printlist(t_var *head)
// {
//     t_var *tmp = head;
//     while (tmp != NULL)
//     {
//         printf("%s\n", tmp->var);
//         tmp = tmp->next;
//     }
// }

// t_var *creat_node(char *env)
// {
//     t_var *node = malloc(sizeof(t_var));
//     node->var = malloc(sizeof(char) * slen(env) + 1);

//     copy_str(node->var, env);
//     node->next = NULL;
//     return node;
// }

// t_var *creat_list(char **env)
// {
//     t_var *head = NULL;
//     t_var *temp;
//     int i = 0;
//     while (env[i])
//     {
//         temp = creat_node(env[i]);
//         temp->next = head;
//         head = temp;
//         i++;
//     }
//     return head;
// }

void add_node(node **rote, char *str)
{
   node *new_node = malloc(sizeof(node));
   new_node->next = NULL;
   copy_str(new_node->var, str);

   node *curr = *rote;
   while (curr->next != NULL)
        curr = curr->next;
   curr->next = new_node;
}

int compare(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s1[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}
int compare_until(char *s1, char *s2, int n)
{
    int i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

int copy_tab(char **tab1, char **tab2)
{
    int i = 0;
    while (tab2[i])
    {
        tab1[i] = malloc(sizeof(char) * slen(tab2[i] + 1));
        copy_str(tab1[i], tab2[i]);
        i++;
    }
    return i;
}

int strchrch(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return i;
        i++;
    }
    return 0;
}

char **add_to_env(char *str, char **env)
{
    int i = 0;
    static int num;
    int len;
    int h;
    h = strchrch(str, '=');
    i = 0;
    while (env[i])
    {
        if (compare_until(str, env[i], h))
        {
            free(env[i]);
            env[i] = malloc(sizeof(char) * slen(str) + 1);
            copy_str(env[i], str);
            return env;
        }
        i++;
    }
    i = 0;
    while (env[i]) 
        i++;
    int new_len = i + 2;
    char **env_copy = malloc(sizeof(char *) * new_len);

    len = copy_tab(env_copy, env);
    env_copy[len] = malloc(sizeof(char) * slen(str) + 1);

    copy_str(env_copy[len], str);
    env_copy[len + 1] = NULL;
    i = 0;
    if(num!= 0)
    {
        free_tab(env);
        env = malloc(sizeof(char *) * new_len);
    }
    if(num == 0)
        env = malloc(sizeof(char *) * new_len);
    len = copy_tab(env, env_copy);
    env[len + 1] = NULL;
    free_tab(env_copy);
    num++;
    return env;
}

char **commands(char **tab, char **env)
{
    int i;
    if (compare(tab[0], "export"))
    {
        if (tab[0] && !tab[1])
        {
            i = 0;
            while (env[i])
                printf("declare -x %s\n", env[i++]);
        }
        i = 1;
        while (tab[i])
        {
            if (is_alphanumeric(tab[i]))
                env = add_to_env(tab[i], env);
            else
                printf("my Shell: no matches found: %s\n", tab[i]);
            i++;
        }
    }
    else if (compare(tab[0], "echo"))
    {
        i = 1;
        while (tab[i])
        {
            printf("%s", tab[i]);
            if(tab[i][0] != ' ' && tab[i + 1])
                printf(" ");
            i++;
        }
        printf("\n");
    }
    else if (compare(tab[0], "env"))
    {
        i = 0;
        while (env[i])
            printf("%s\n", env[i++]);
    }
    else
        printf("%s command not found\n", tab[0]);
    return(env);
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;

    char *input;
    char **tab;
    int *arr;

    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");
        add_history(input);
        arr = check_quoting(input);
        tab = split(input);
        modification(tab, 25, ' ');
        env = commands(tab, env);
        free_tab(tab);
    }
    return 0;
}

    // node *root = malloc(sizeof(node));
    // root->var = "youssef";
    
    // // root->next = malloc(sizeof(node));
    // // root->next->var = "yassine";

    // // root->next->next = malloc(sizeof(node));
    // // root->next->next->var = "youness";
    // // root->next->next->next = NULL;
    
    // // while (curr != NULL)
    // // {
    // //     printf("%s->", curr->var);
    // //     curr = curr->next;
    // // }
    // add_node(&root, "soumia");
    // node *curr;
    // curr = root;
    // while (curr != NULL)
    // {
    //     printf("%s->", curr->var);
    //     curr = curr->next;
    // }
// void free_list(t_var* head) 
// {
//     t_var* current = head;

//     while (current != NULL) 
//     {
//         t_var* temp = current;
//         current = current->next;
//         free(temp);
//     }
// }

