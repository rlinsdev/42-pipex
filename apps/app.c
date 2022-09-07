/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:55:06 by rlins             #+#    #+#             */
/*   Updated: 2022/09/07 06:28:41 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Main Class of program
 * @param argc Arguments Count
 * @param argv Arguments Vector
 * @param envp Contains all possible paths where the system might store the
 * program
 * @return int
 */
int	main(int argc, char **argv, char **envp)
{
	// int i = 0;
	// int j = 0;
	// while (envp[i][j] != '\0')
	// {
	// 	ft_printf("%s\n", envp[i][j]);
	// 	j++;
	// }
	start(argc, argv, envp);
	return (0);
}
