/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/08/30 21:16:08 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/pipex.h"

int	startTest3(int argc, char **argv)
{
	int	id = fork();
	int n;

	if(id == 0)
		n = 1;
	else
		n = 6;

	if (id != 0)
	{
		wait();
	}

	int i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id !=0)
		printf("\n");
	return (0);
}
