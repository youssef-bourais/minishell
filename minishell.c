/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/23 10:10:10 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void exucution(char *input)
{
    system(input);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    char *input;
    // struct stat s;
    
    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");

        // parssing(input);
        exucution(input);
    }

    // DIR *d;
    // struct dirent *dd;

    // d = opendir("/Users/ybourais/Desktop/minishell");

    // while ((dd = readdir(d)) != NULL)
    //     printf("%hhu\n", dd->d_name);

    // closedir(d);
    // char *tab[] = {"/bin/ls", "-a", NULL};
    // execve(tab[0], tab, NULL);
    // unlink("/Users/ybourais/Desktop/minishell/yichiba");
    // stat("/Users/ybourais/Desktop/minishell/note.txt", &s);
    // printf("%lld\n", s.st_size);
    //chdir("..");
    // printf("%s\n", getcwd(input, 250));
    // printf("%d\n", access("note.txt", W_OK | R_OK));
    return 0;
}

