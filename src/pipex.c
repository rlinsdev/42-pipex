/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/09/08 22:47:32 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Will loop through all variables to retrieve the value of PATH variable
 * @param envp variables of environment
 * @return char* result of PATH variable
 */
static char	*path_handler(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5); // Remove PATH=
}

/**
 * @brief Initialize all variables in data type
 * @param data Object initialized *
 * @param argc Initialize arg Count
 * @param argv Initialize arg Vector
 * @param envp Initialize Environment variables
 */
static void	ini_data(t_data *data, int argc, char **argv, char **envp)
{
	data->fd_in = -1;
	data->fd_out = -1;
	// TODO: init all variables?
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->path = path_handler(envp);
}

int	start(int argc, char **argv, char **envp)
{
	t_data data;
	ini_data(&data, argc, argv, envp);

	if (argc != 5)
		error_args_handler(ERROR_ARGS);
	// Open files
	data.fd_in = file_open(argv[1], IN); // TODO data.argv?
	data.fd_out = file_open(argv[data.argc - 1], OUT); // TODO: data.argc?
	error_fd_handler(data);
	data.pipe_status = pipe(data.pipe_fd);
	error_pipe_handler(data);
	//data.path = find_path(envp);
	data.cmd_path = ft_split(data.path, ':');
	data.pid1 = fork();
	if (data.pid1 == 0)
		first_child(data);
	data.pid2 = fork();
	if (data.pid2 == 0)
		second_child(data);
	close_pipes_fd(&data);
	waitpid(data.pid1, NULL, 0);
	waitpid(data.pid2, NULL, 0);
	main_process_free(&data);

	return (0);
}
