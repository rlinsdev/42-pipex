/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/09/07 20:42:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Initialize all variables in data type
 * @param data Object initialized
 */
static void	ini_data(t_data data, int argc, char **argv, char **envp)
{
	data.fd_in = -1;
	data.fd_out = -1;
	// TODO: Inicializar todas variáveis
	data.argc = argc;
	data.argv = argv;
	data.envp = envp;
}

void	execute (t_data data)
{
	//cmd_space_substitution

}

void	child_process(t_data data)
{
	dup2 (data.pipe_fd[OUT], STDOUT);
	close (data.pipe_fd[IN]);
	//execute (data.argv[2], data.envp);
}

void	main_process(t_data data)
{
	dup2(data.pipe_fd[IN], STDIN);
	close(data.pipe_fd[OUT]);
	//execute(data.argv[3], data.envp);
}

int	start(int argc, char **argv, char **envp)
{
	t_data data;
	ini_data(data, argc, argv, envp);

	if (argc == 5)
	{
		// Open files
		data.fd_in = file_open(argv[1], IN);
		data.fd_out = file_open(argv[4], OUT);

		// Duplicate File descriptor to another code
		dup2(data.fd_in, STDIN);
		dup2(data.fd_out, STDOUT);

		// Create pipe. Get output from one to input to another
		data.pipe_result = pipe(data.pipe_fd);
		error_handler(ERROR_PIPE);

		// Fork the process
		data.pid = fork();
		error_data_handler(data);
		child_process(data);
		// Waiting execution of first process
		waitpid(data.pid, &data.status, 0);
		main_process(data);
	}
	else
		error_handler(ERROR_ARGS);

	//startTest7(argc, argv, envp);

	// validate_files(argv);

	return (0);
}
