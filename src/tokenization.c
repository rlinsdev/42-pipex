/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:10:41 by rlins             #+#    #+#             */
/*   Updated: 2022/09/18 18:24:41 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief
 *
 * @param string
 * @param charIdentifier (/)
 * @param tokenId (-1)
 */
static void	remove_token(char *string, char charIdentifier, char tokenId)
{
	int	index;
	int	size;

	index = 0;
	size = ft_strlen(string);
	while (string[index])
	{
		if (string[index] == charIdentifier)
		{
			string[index] = tokenId;
			break ;
		}
		index++;
	}
	while (size)
	{
		size--;
		if (string[size] == charIdentifier)
		{
			string[size] = tokenId;
			break ;
		}
	}
}
/**
 * @brief
 *
 * @param cmd
 * @param limiter
 * @param tokenId (-1)
 * @param charToRemove
 * @return char*
 */
static char	*token(char *cmd, char limiter, char tokenId, char charToRemove)
{
	while (*cmd)
	{
		if (*cmd == tokenId)
			*cmd = charToRemove;
		if (*cmd == limiter)
			break ;
		cmd++;
	}
	if (*cmd == limiter)
		cmd++;
	return (cmd);
}

void	get_token(char *cmd, char limiter, char tokenId, char space)
{
	char	*tmp;
	int		index;

	index = 0;
	while (cmd[index])
	{
		if (cmd[index] == limiter)
		{
			tmp = &cmd[index];
			tmp++;
			while (*tmp)
			{
				if (*tmp == limiter)
					cmd = token(cmd + index + 1, limiter, tokenId, space);
				tmp++;
			}
		}
		index++;
	}
}

void	token_rollback(char **cmd)
{
	int	index;

	index = 0;
	while (cmd[index])
	{
		get_token(cmd[index], '\'', 1, ' ');
		get_token(cmd[index], '\"', 1, ' ');
		remove_token(cmd[index], '\'', 1);
		remove_token(cmd[index], '\"', 1);
		index++;
	}
}
