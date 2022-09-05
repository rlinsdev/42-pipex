/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/09/05 07:21:21 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	start(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_handler(ERROR_ARGS);

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
