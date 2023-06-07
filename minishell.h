/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:00:07 by ybourais          #+#    #+#             */
/*   Updated: 2023/06/06 12:04:49 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <fcntl.h> /* open */
# include <stdio.h> /* printf strerror perror*/
#include <readline/readline.h> /* redline */
#include <readline/history.h> /* redline */
#include <stdlib.h> /* malloc, free getenv */
#include <unistd.h> /* access, fork, getcwd, chdir, unlink execve dup dup2 pipe isatty ttyname ttyslot*/
#include <sys/wait.h> /* waitpid */
#include <sys/stat.h> /* stat */
#include <dirent.h> /* opendir readdir closedir*/
#include <sys/ioctl.h> /* ioctl */
#include <termios.h> /* tcsetattr */
#include <termcap.h> /* tgetent */
#include <string.h>

typedef struct  node 
{
    char *var;
    struct node *next;
} node;

void ft_error(int n);
int *check_quoting(char *str);
int nbr_words(char *str);
int word_len(char *str);
char **split(char *s);
void free_tab(char **tab);
void modification(char **tab, int n, int t);
int valid_dollar(char *str);
int real_lenth(char *str);

#endif