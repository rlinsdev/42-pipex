/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:59:00 by rlins             #+#    #+#             */
/*   Updated: 2022/09/19 12:23:32 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

/**
 * @brief Will find what command will match with path to execute the command
 * @param paths Paths to possible execute the command
 * @param cmd command to be applied to execute
 * @return char* -> Correct command with path executable
 */
static char	*get_cmd (char **paths, char *cmd)
{
	char	*aux;
	char	*command;

	// while through all variables
	while (*paths)
	{
		// /home/rlins/.asdf/shims
		aux = ft_strjoin(*paths, "/");
		// /home/rlins/.asdf/shims/cat
		command = ft_strjoin(aux, cmd);
		free(aux);
		// Test for access to this command
		if (access(command, 0) == 0)
		{
			/* /user/bin/[cat] - First Match in first execution
			 * /usr/bin/[wc][grep]   Second match in second Execution */
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
	// cmd_path = /home/rlins/.asdf/shims
	data.cmd = get_cmd(data.cmd_path, data.cmd_args[0]);
	if (!data.cmd)
	{
		child_process_free(&data);
		main_process_free(&data);
		perror(INV_CMD);
		exit(1);
	}
	/* /usr/bin/cat, cat, SHELL=/bin/bash
	 * /usr/bin/wc, wc, SHELL=/bin/bash */
	execve(data.cmd, data.cmd_args, data.envp);
}

void	first_child(t_data data)
{
	dup2(data.pipe_fd[1], 1);
	// Nothing we want to read, close pipe's read end.
	close(data.pipe_fd[0]);
	dup2(data.fd_in, 0);
	// cat
	if (contains_backslash(data.argv[2]))
	{
		// "tr ' ' _"
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
	// Duplicate a file descriptor to another standard output
	dup2(data.pipe_fd[0], 0);
	// Nothing to write, close pipe's write end.
	close(data.pipe_fd[1]);
	dup2(data.fd_out, 1);
	// wc -l
	if (contains_backslash(data.argv[3]))
	{
		//"tr b ' '"
		replace_spaces(data.argv[3]); //"tr b '\377'"
		remove_backslash(data.argv[3]); // "tr b \377 "
		data.cmd_args = ft_split(data.argv[3], ' '); //"[0]=tr [1]=b [2]=\377"
		restore_spaces(data.cmd_args); //"[0]=tr [1]=b [2]= "
	}
	else
	{
		data.cmd_args = ft_split(data.argv[3], ' ');
	}
	call_run(data);
}
