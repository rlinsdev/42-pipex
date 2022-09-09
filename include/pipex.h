/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/09/08 22:47:47 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//# include "./libft.h"
# include <libft.h>
# include <unistd.h> //Execve, fork, dup, dump2, write, pipe
# include <stdio.h> // perror
# include <string.h> // strerror
# include <fcntl.h> // To Open a file
# include <sys/wait.h> // waitpid

# define IN 	0
# define OUT 	1

// Child process - File descriptors code
# define STDIN		0
# define STDOUT		1
# define STDERR		2 // TODO: fileDescriptor 2

# define GREY 			"\033[0;90m"
# define RED			"\033[0;31m"
# define RESET 			"\033[0m"


# define ERROR_ARGS 	1
# define ERROR_PIPE 	2
# define E_ARGS_MSG "Error Code 1. Invalid number of arguments. Expected 5 \nSample: ./bin/pipex file1 cmd1 cmd2 file2\n"
# define E_PIPE_MSG "Problems to create Pipe"
# define ACCESS_DEN "The action failed!\n"
# define E_OPEN_OUT "Invalid output file"
# define INV_CMD "Invalid command\n"

typedef struct s_data
{
	int argc;
	char **argv;
	char **envp;
	int	fd_in; // OK (InFile)
	int	fd_out; // OK (outFile)
	int	pipe_fd[2]; //OK (Tube)
	pid_t	pid1; // OK
	pid_t	pid2; // OK
	char *cmd; // OK
	char **cmd_path; // OK
	char **cmd_args; // OK
	char *path; // OK
	int pipe_status;
} t_data;



/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @param envp Environment pointer (PATH)
 * @return int
 */
int	start(int argc, char **argv, char **envp);

/**
 * @brief Verify errors in app - Number of params
 * @param code
 */
void	error_args_handler(int code);

/**
 * @brief Verify errors in app - File Descriptor error
 * @param data Obj Data
 */
void	error_fd_handler (t_data data);

/**
 * @brief Verify errors in app - Pipe return
 * @param data obj Data
 */
void	error_pipe_handler(t_data data);

/**
 * @brief
 *
 * @param argv
 */
void validate_files(char **argv);

/**
 * @brief Open files with path in param
 * @param file path of file
 * @param mode if will be in or out
 * @return int File descriptor Code
 */
int	file_open(char *file, int mode);

void	second_child(t_data data);
void	first_child(t_data data);
void	child_process_free(t_data *data);
void	main_process_free(t_data *data);
void	close_pipes_fd(t_data *data);

//Testes - Del this
// int	startTest(int argc, char **argv);
// int	startTest2(int argc, char **argv);
// int	startTest3(int argc, char **argv);
// int	startTest4(int argc, char **argv);
// int	startTest5(int argc, char **argv);
// int	startTest6(int argc, char **argv, char **envp);
//int	startTest7(int argc, char **argv, char **envp);



#endif
