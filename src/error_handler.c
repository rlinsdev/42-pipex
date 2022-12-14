/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:15:39 by rlins             #+#    #+#             */
/*   Updated: 2022/09/21 23:38:00 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_open_file(t_data data)
{
	// Free from memory
	main_process_free(&data);
	perror(E_OPEN_FIL);
	exit(EXIT_FAILURE);
}

void	error_fork_handler(t_data data)
{
	// -1 = Error
	if (data.pid1 == -1 || data.pid2 == -1)
	{
		perror(E_FORK_PRO);
		exit(1);
	}
}

void	error_pipe_handler(t_data data)
{
	// -1 = Error
	if (data.pipe_status == -1)
	{
		main_process_free(&data);
		perror(E_PIPE_MSG);
		exit(1);
	}
}

void	error_fd_handler (t_data data)
{
	if (data.fd_in == -1)
	{
		int exit_code;

		exit_code = 0;
		if(access(data.argv[1], F_OK))
			exit_code = 1;

		main_process_free(&data);
		perror(ACCESS_DEN);
		exit(exit_code);
	}
	if (data.fd_out == -1)
	{
		main_process_free(&data);
		perror(E_OPEN_OUT);
		exit(1);
	}
}

void	error_args_handler(int code, t_data data)
{
	if (code == ERROR_ARGS)
	{
		main_process_free(&data);
		// perror will fetch the most recent error to interpret
		perror(E_ARGS_MSG);
		exit(code);
	}
}
