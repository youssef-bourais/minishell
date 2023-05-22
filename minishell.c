/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:59:39 by ybourais          #+#    #+#             */
/*   Updated: 2023/05/22 10:40:17 by ybourais         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    char *input;

    
    
    while(1)
    {
        input = readline("\e[1;32mmy_Shell-310$ \e[0m");

        printf("%s\n", input);
        // if(!parssing(input))
        //     printf("my_Shell: command not found: %s\n", input);
        // else
        //     exucution(input);
    }
    return 0;
}

// int main() {
//     // DIR *dir;
//     // struct dirent *entry;

//     // dir = opendir(".");

//     // if (dir == NULL) {
//     //     perror("opendir");
//     //     return 1;
//     // }

//     // Read directory entries
//     // while ((entry = readdir(dir)) != NULL) {
//         // printf("\n");
//     // }

//     // Close the directory
//     // closedir(dir);
//     // int ioctl(int fildes, unsigned long request, ...);
//     // char *getenv(const char *name);
//     // int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);

//     return 0;
// }

// int main() {

//     char* clear_sequence = tgetstr("cl", NULL);
//     tputs(clear_sequence, 1, putchar);
//     printf("%s\n", clear_sequence);
//     return 0;
// }
