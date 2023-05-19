/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/19 17:46:59 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int parssing(char *input)
{
    int i = 0;
    while(input[i] != '\0')
    {
        if (input[i])
            return 0;
        i++;
    }
    return 1;   
}

void exucution(char *input)
{
    system(input);
}

int mn(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    int execve(const char *path, char *const argv[], char *const envp[]);
    int dup(int fildes);
    
    DIR *opendir(const char *filename);
    struct dirent *readdir(DIR *dirp);
    int closedir(DIR *dirp);
    
    // while(1)
    // {
    //     input = readline("\e[1;32mmy_Shell-310$ \e[0m");

    //     // printf("%d\n", );
    //     // if(!parssing(input))
    //     //     printf("my_Shell: command not found: %s\n", input);
    //     // else
    //         // exucution(input);
    // }
    return 0;
}
#include <stdio.h>
#include <dirent.h>

int main() {
    // DIR *dir;
    // struct dirent *entry;

    // dir = opendir(".");

    // if (dir == NULL) {
    //     perror("opendir");
    //     return 1;
    // }

    // Read directory entries
    // while ((entry = readdir(dir)) != NULL) {
        printf("\n");
    // }

    // Close the directory
    // closedir(dir);

    return 0;
}
