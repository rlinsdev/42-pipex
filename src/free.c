/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:29:57 by rlins             #+#    #+#             */
/*   Updated: 2022/09/14 22:37:33 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pipex.h>

void	main_process_free(t_data *data)
{
	int	i;

	i = 0;
	close(data->fd_in);
	close(data->fd_out);
	// Run through all paths split in environment paths
	while (data->cmd_path[i])
	{
		free(data->cmd_path[i]);
		i++;
	}
	free(data->cmd_path);
}

void	child_process_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_args[i])
	{
		free(data->cmd_args[i]);
		i++;
	}
	free(data->cmd_args);
	free(data->cmd);
}

void	close_pipes_fd(t_data *data)
{
	// This is de parent/main process
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}
