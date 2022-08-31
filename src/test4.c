/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/08/31 06:50:29 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/pipex.h"

int	startTest4(int argc, char **argv)
{
	int	id = fork();
	if (id == 0)
	{
		sleep(1);
	}
	printf("Current Id: %d, ParentId: %d\n", getpid(), getppid());

	int res = wait(NULL);
	if (res == -1)
		printf("No children to wait for\n");
	else
		printf("%d finished execution\n", res);
	return (0);
}
