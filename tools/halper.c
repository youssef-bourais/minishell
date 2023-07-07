/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:38:20 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/07 17:40:51 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int copy_tab(char **tab1, char **tab2)
{
    int i = 0;
    while (tab2[i])
    {
        tab1[i] = malloc(sizeof(char) * slen(tab2[i] + 1));
        copy_str(tab1[i], tab2[i]);
        i++;
    }
    tab1[i] = 0;
    return i;
}

char *join(char *s1, char *s2)
{
    char *str = malloc(sizeof(char) * (slen(s1) + slen(s2) + 1));

    copy_str(str, s1);
    copy_str(str + slen(s1), s2);
    return str;
}

int is_alphanumeric(char *str)
{
    int i = 0;
    if(str[0] == '=' || (str[0] >= 48 && str[0] <= 57))
        return 0;
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

int without_equal(char *str)
{
    int i = 0;
    while (str[i])
    {
        if(!((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == 95 || str[i] == ' '))
            return 0;
        i++;
    }
    return 1;
}

int	a_toi(char *str, int *handler)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		*handler = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
    if(!(str[i] >= '0' && str[i] <= '9'))
        *handler = 0;
	return (res);
}