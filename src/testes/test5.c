/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/10/29 08:52:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/pipex.h"

int	startTest5(int argc, char **argv)
{
	/*fd[0] é o read. fd[1] é o write
	 */
	int fd[2];

	if (pipe(fd) == -1)
	{
		printf("An Error occurred with open Pipe\n");
		return (1);
	}

	int id  = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			return (3);
		}
		close(fd[0]);
		printf("Got by the Child process: %d\n", y);
	}

	return (0);
}
