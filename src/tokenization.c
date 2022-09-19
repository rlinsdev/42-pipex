/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:10:41 by rlins             #+#    #+#             */
/*   Updated: 2022/09/19 17:23:41 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Verify if char is a backslash (\). This will happened when in
 * command exist ' ' (white space between single quotes)
 * @param str
 * @return int
 */
static int	is_backslash(char str)
{
	return (str == '\'');
}

void	restore_spaces(char **exec_args)
{
	char	*str;

	while (*exec_args)
	{
		str = *exec_args;
		while (*str)
		{
			if (*str == -1)
			{
				*str = ' ';
			}
			str++;
		}
		exec_args++;
	}
}

void	remove_backslash(char *str)
{
	while (*str)
	{
		if (is_backslash(*str))
			*str = ' ';
		str++;
	}
}

void	replace_spaces(char *str)
{
	while (*str && !is_backslash(*str))
		str++;
	if (*str)
		str++;
	while (*str && !is_backslash(*str))
	{
		if (*str == ' ')
		{
			*str = -1;
		}
		str++;
	}
	if (*str)
		str++;
	if (*str)
	{
		replace_spaces(str);
	}
}

int	contains_backslash(char *str)
{
	while (*str)
	{
		if (is_backslash(*str))
			return (1);
		str++;
	}
	return (0);
}
