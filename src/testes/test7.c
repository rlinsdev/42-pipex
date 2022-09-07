/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:44:13 by rlins             #+#    #+#             */
/*   Updated: 2022/09/07 11:22:28 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	startTest7(int argc, char **argv, char **envp)
{
	// Open a pipe with 2 file descriptors
	int fd[2];
	// Verify errors
	if (pipe(fd) == -1)
		return (1);

	// Create 2 process
	int pid1 = fork();
	if (pid1 == -1)
		return (2);

	// Child execution (ping)
	if (pid1 == 0)
	{
		// Duplicate FD, but param Standard Output, no more input
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		// Child process 1 (ping)
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}

	// Create 2 process
	int pid2 = fork();
	if (pid2 == -1)
		return (3);

	// Child execution (grep)
	if (pid2 == 0)
	{
		//Duplicate FD,
		dup2(fd[0], STDIN_FILENO);// Standard input
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}

	// Close both core File Descriptors
	close(fd[0]);
	close(fd[1]);

	// Wait the execution of child process (ping)
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
