/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/09/21 23:40:51 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <unistd.h> //Execve, fork, dup, dump2, write, pipe
# include <stdio.h> // perror
# include <string.h> // strerror
# include <fcntl.h> // To Open a file
# include <sys/wait.h> // waitpid

# define IN 	0
# define OUT 	1
# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define ERROR_ARGS 	1
# define ERROR_PIPE 	2
# define E_ARGS_MSG "Invalid number of arguments. Expected 5"
# define E_PIPE_MSG "Problems to create Pipe"
# define ACCESS_DEN "The action failed!\n"
# define E_OPEN_OUT "Invalid output file"
# define E_OPEN_FIL "No such file or directory"
# define E_FORK_PRO "Problem to fork process"
# define INV_CMD "Invalid command"

# define EXIT_INVCMD	127

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_path;
	char	**cmd_args;
	char	*path;
	int		pipe_status;
}	t_data;

/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @param envp Environment variables/pointer (PATH)
 * @return int
 */
int		start(int argc, char **argv, char **envp);

/**
 * @brief Verify errors in app - Number of params / args
 * @param code Code to identify this error
 * @param data Data Object - free memory
 */
void	error_args_handler(int code, t_data data);

/**
 * @brief Verify errors in app - File Descriptor error
 * @param data Obj Data
 */
void	error_fd_handler(t_data data);

/**
 * @brief Verify errors in app - Pipe return
 * @param data obj Data
 */
void	error_pipe_handler(t_data data);

/**
 * @brief Verify error when open a file
 */
void	error_open_file(t_data data);

/**
 * @brief Check if Fork process get some error
 * @param data
 */
void	error_fork_handler(t_data data);

/**
 * @brief Open files with path in param
 * @param file path of file
 * @param mode if will be in or out
 * @param data In case of error, free from memory
 * @return int File descriptor Code
 */
int		file_open(char *file, int mode);

/**
 * @brief The second command in pipe. Child command executed.
 * @param data
 */
void	second_child(t_data data);

/**
 * @brief First command. Executed like a child to not interrupt main process
 * @param data
 */
void	first_child(t_data data);

/**
 * @brief Free all memory from child process
 * @param data
 */
void	child_process_free(t_data *data);

/**
 * @brief Close File descriptors. Free all split from path variables.
 * @param data
 */
void	main_process_free(t_data *data);

/**
 * @brief Close File Descriptor from Pipes
 * @param data
 */
void	close_pipes_fd(t_data *data);

/**
 * @brief Come back white space back to the command
 * @param exec_args
 */
void	restore_spaces(char **exec_args);

/**
 * @brief Will replace \ to white space.
 * @param str
 */
void	remove_backslash(char *str);

/**
 * @brief Remove white space from code and mark with spacial char (-1)
 * @param str
 */
void	replace_spaces(char *str);

/**
 * @brief Check if the command contain backlash(\). If positive, we must
 * remove * to apply the correct command before split. It will be put in
 * special chars   *(')
 * @param str str to check
 * @return int yes or no
 */
int		contains_backslash(char *str);
#endif
