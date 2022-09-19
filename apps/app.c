/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:55:06 by rlins             #+#    #+#             */
/*   Updated: 2022/09/19 17:30:09 by rlins            ###   ########.fr       */
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
int	main(int argc, char *argv[], char *envp[])
{
	return (start(argc, argv, envp));
}
