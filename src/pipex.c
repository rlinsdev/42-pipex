/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/09/06 07:23:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Initialize all variables in data type
 * @param data Object initialized
 */
static void	ini_data(t_data data)
{
	data.fd_in = -1;
	data.fd_out = -1;
}

int	start(int argc, char **argv, char **envp)
{
	// t_data data;
	// ini_data(data);

	// if (argc == 5)
	// {
	// 	data.fd_in = file_open(argv[1], IN);
	// 	data.fd_out = file_open(argv[4], OUT);

	// }
	// else
	// 	error_handler(ERROR_ARGS);

	startTest7(argc, argv, envp);


	// int i = 0;
	// while (argv[i] != '\0')
	// {
	// 	ft_printf("\n%s\n", argv[i]);
	// 	i++;
	// }

	// validate_files(argv);

	// ft_printf("\nDone?\n\nDone?\n\nDone?\n");
	// ft_printf("%d\n", ft_strlen("ABC"));
	return (0);
}
