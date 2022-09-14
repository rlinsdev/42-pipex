/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:59:00 by rlins             #+#    #+#             */
/*   Updated: 2022/09/14 14:38:04 by rlins            ###   ########.fr       */
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

	while (*paths)
	{
		// /home/rlins/.asdf/shims ESSE CARA NAO EXISTE NO SO. FIZ MERDA?
		aux = ft_strjoin(*paths, "/");
		// /home/rlins/.asdf/shims/cat
		command = ft_strjoin(aux, cmd); // TODO nao daria pra nao usar join??
		free(aux);
		// Test for access to this command
		if (access(command, 0) == 0)
		{
			/* /user/bin/cat foi o q deu match na 1 exec
			 * /usr/bin/wc   foi o q deu match na 2 exec */
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
	close(data.pipe_fd[0]); // TODO: Porque dar close neste cara aqui? Ver video
	dup2(data.fd_in, 0);
	// cat
	//TODO: TEstar com outros commandos q tem espaço aqui.
	data.cmd_args = ft_split(data.argv[2], ' ');
	call_run(data);
}

void	second_child(t_data data)
{
	dup2(data.pipe_fd[0], 0);
	close(data.pipe_fd[1]);
	dup2(data.fd_out, 1);
	// wc -l
	data.cmd_args = ft_split(data.argv[3], ' ');
	call_run(data);
}
