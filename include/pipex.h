/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/09/07 20:36:08 by rlins            ###   ########.fr       */
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
# define E_PIPE_MSG "Error code 2. Problems to create Pipe\n"
# define ACCESS_DEN "The action failed.!\n"
# define E_INV_PARA "Invalid input file param. Follow: ./pipex [file1] [cmd1] [cmd2] [file2]\n"

typedef struct s_data
{
	int argc;
	char **argv;
	char **envp;
	int	fd_in;
	int	fd_out;
	int	pipe_fd[2];
	int pipe_result;
	pid_t	pid;
	int	status;
	char **cmd; // TODO: Inicializar
	char *path; // TODO: Inicializar
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
 * @brief
 *
 * @param code
 */
void	error_handler(int code);


void	error_data_handler(t_data data);

/**
 * @brief
 *
 * @param argv
 */
void validate_files(char **argv);

int	file_open(char *file, int mode);

//Testes - Del this
// int	startTest(int argc, char **argv);
// int	startTest2(int argc, char **argv);
// int	startTest3(int argc, char **argv);
// int	startTest4(int argc, char **argv);
// int	startTest5(int argc, char **argv);
// int	startTest6(int argc, char **argv, char **envp);
//int	startTest7(int argc, char **argv, char **envp);



#endif
