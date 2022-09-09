/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:59:00 by rlins             #+#    #+#             */
/*   Updated: 2022/09/08 22:43:41 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

static char	*get_cmd (t_data data)
{
	char	*aux;
	char	*command;
	// data.cmd_path
	// while (*paths)
	while (*data.cmd_path)
	{
		// aux = ft_strjoin(*paths, "/");
		aux = ft_strjoin(*data.cmd_path, "/");
		command = ft_strjoin(aux, data.cmd);
		free(aux);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		// paths++;
		*data.cmd_path++;
	}
	return (NULL);
}

static void	call_run(t_data data)
{
	data.cmd = get_cmd(data);
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
	data.cmd_args = ft_split(data.argv[2], ' ');
	call_run(data);
}

void	second_child(t_data data)
{
	dup2(data.pipe_fd[0], 0);
	close(data.pipe_fd[1]);
	dup2(data.fd_in, 1);
	data.cmd_args = ft_split(data.argv[3], ' ');
	call_run(data);
}
