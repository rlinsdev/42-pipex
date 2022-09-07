/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:55:06 by rlins             #+#    #+#             */
/*   Updated: 2022/09/07 11:52:22 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Main Class of program
 * @param argc Arguments Count
 * @param argv Arguments Vector
 * @param envp Contains all possible paths where the system might store the
 * program. All the sys Variables
 * @return int
 */
int	main(int argc, char **argv, char **envp)
{
	// Code to check ArgVParams
	for (int j = 0; j < argc; j++)
		ft_printf("argv[%d]: %s\n", j, argv[j]);
	ft_printf("\n\n");

	// Code to check all the envp variables.
	int j = 0;
	while (envp[j]!= NULL)
	{
		ft_printf("envp[%d]: %s\n", j, envp[j]);
		j++;
	}

	start(argc, argv, envp);
	return (0);
}
