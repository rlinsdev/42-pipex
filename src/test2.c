/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/08/30 07:39:45 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/pipex.h"

int	startTest2(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
	{
		printf("Error!:%d\n", pid);
		return (1);
	}

	if (pid == 0)
	{
		printf("Child Process ID:%d\n", pid);
		// Child process
		// execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	else
	{
		// Parent Process
		wait(NULL);
		// printf("Success!!\n");
		printf("Parent Process ID:%d\n", pid);
	}

	return (0);
}
