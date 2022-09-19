/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:59:00 by rlins             #+#    #+#             */
/*   Updated: 2022/09/19 17:23:15 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Will find what command will match with path to execute the command
 * @param paths Paths to possible execute the command
 * @param cmd command to be applied to execute
 * @return char* -> Correct command with path executable
 */
static char	*get_cmd(char **paths, char *cmd)
{
	char	*aux;
	char	*command;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		command = ft_strjoin(aux, cmd);
		free(aux);
		if (access(command, 0) == 0)
		{
			return (command);
		}
		free(command);
		paths++;
	}
	return (NULL);
}

/**
 * @brief Will execute the program (bash command) Execve. Will verify errors
 * @param data Full object data
 */
static void	call_run(t_data data)
{
	data.cmd = get_cmd(data.cmd_path, data.cmd_args[0]);
	if (!data.cmd)
	{
		child_process_free(&data);
		main_process_free(&data);
		perror(INV_CMD);
		exit(EXIT_INVCMD);
	}
	execve(data.cmd, data.cmd_args, data.envp);
}

void	first_child(t_data data)
{
	dup2(data.pipe_fd[1], 1);
	close(data.pipe_fd[0]);
	dup2(data.fd_in, 0);
	if (contains_backslash(data.argv[2]))
	{
		replace_spaces(data.argv[2]);
		remove_backslash(data.argv[2]);
		data.cmd_args = ft_split(data.argv[2], ' ');
		restore_spaces(data.cmd_args);
	}
	else
	{
		data.cmd_args = ft_split(data.argv[2], ' ');
	}
	call_run(data);
}

void	second_child(t_data data)
{
	dup2(data.pipe_fd[0], 0);
	close(data.pipe_fd[1]);
	dup2(data.fd_out, 1);
	if (contains_backslash(data.argv[3]))
	{
		replace_spaces(data.argv[3]);
		remove_backslash(data.argv[3]);
		data.cmd_args = ft_split(data.argv[3], ' ');
		restore_spaces(data.cmd_args);
	}
	else
	{
		data.cmd_args = ft_split(data.argv[3], ' ');
	}
	call_run(data);
}
