/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:59:00 by rlins             #+#    #+#             */
/*   Updated: 2022/09/12 20:23:50 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

static char	*get_cmd (char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		// ft_printf("command: %s\n", command);
		// ft_printf("tmp: %s\n", tmp);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

static void	call_run(t_data data)
{
	data.cmd = get_cmd(data.cmd_path, data.cmd_args[0]);
	if (!data.cmd)
	{
		child_process_free(&data);
		perror(INV_CMD);
		exit(1);
	}
	execve(data.cmd, data.cmd_args, data.envp);
}

void	first_child(t_data data)
{
	dup2(data.pipe_fd[1], 1);
	close(data.pipe_fd[0]);
	dup2(data.fd_in, 0);
	// cat
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
