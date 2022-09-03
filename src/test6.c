/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/09/03 20:33:30 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <pipex.h>

int	startTest6(int argc, char **argv, char **envp)
{
	//printf("OIOI");
	char *options[3]  = {"ls", "-la", NULL};

	(void)argc;
	(void)argv;

	execve("/usr/bin/ls", options, envp);

	return (0);
}
