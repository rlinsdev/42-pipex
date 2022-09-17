/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:21 by rlins             #+#    #+#             */
/*   Updated: 2022/09/17 13:16:14 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Will loop through all variables to retrieve the value of PATH variable
 * In all the EnvVariables (more than 70) I just need the PATH
 * @param envp variables of environment
 * @return char* result of PATH variable
 */
static char	*path_handler(char **envp)
{
	/* PATH  shows all possible paths towards program binary files,
	 * including shell commands */
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5); // Remove 'PATH=' and return all content
}

/**
 * @brief Initialize all variables in data type
 * @param data Object initialized
 * @param argc Initialize arg Count
 * @param argv Initialize arg Vector
 * @param envp Initialize Environment variables
 */
static void	ini_data(t_data *data, int argc, char **argv, char **envp)
{
	data->fd_in = -1;
	data->fd_out = -1;
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	// Just return the Path info (all string)
	data->path = path_handler(envp);
	//ft_printf("\nPath: %s\n", data->path);
	// Get all in Path variable and just split by ':'
	data->cmd_path = ft_split(data->path, ':');
	// int j = 0;
	// while (data->cmd_path[j]!= NULL)
	// {
	// 	ft_printf("cmd_path[%d]: %s\n", j, data->cmd_path[j]);
	// 	j++;
	// }
}

int	start(int argc, char **argv, char **envp)
{
	t_data data;
	ini_data(&data, argc, argv, envp);
	// Must to be 5 elements in count
	if (argc != 5)
		error_args_handler(ERROR_ARGS);
	// Open file file-in
	data.fd_in = file_open(argv[1], IN);
	// Open file file-out
	data.fd_out = file_open(argv[4], OUT);
	error_fd_handler(data);
	/* Pipe will store 2 FD. Bytes write in [1] can be read from [0]
	 * Pipe = communication between process */
	data.pipe_status = pipe(data.pipe_fd);
	error_pipe_handler(data);
	/* Create 2 process. Here we must to Fork a process, because after execve
	 * the program stop, but we don't wanna loose our own process */
	data.pid1 = fork();
	// When in child process
	if (data.pid1 == 0)
		first_child(data);
	/* Create 2 process. Here we must to Fork a process, because after execve
	 * the program stop, but we don't wanna loose our own process */
	data.pid2 = fork();
	// When in child process
	if (data.pid2 == 0)
		second_child(data);
	error_fork_handler(data);
	close_pipes_fd(&data);
	// Wait the execution of child process. This will avoid zombie process
	waitpid(data.pid1, NULL, 0); // supervising the children
	waitpid(data.pid2, NULL, 0);
	main_process_free(&data);
	return (0);
}
