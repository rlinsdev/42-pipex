/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/08/29 21:40:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	startTest(int argc, char **argv)
{
	// Ping google.com -> Execute a Path
	// execl("/bin/ping",
	// 	"/bin/ping",
	// 	"google.com",
	// 	NULL);

	// Ping Google.com -> Searching in the Path
	// execlp("ping",
	// 	"ping",
	// 	"google.com",
	// 	NULL);

	// char *arr[] = {
	// 	"ping",
	// 	"google.com",
	// 	NULL
	// };
	// // Ping Google.com -> Array of arguments
	// execvp("ping", arr);

	char *arr[] = {
		"ping",
		"google.com",
		NULL
	};

	char *env[] = {
		"TEST=environnment variable",
		NULL
	};

	execvpe(
		"ping",
		arr,
		env);

	return (0);
}
