/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/09/04 18:54:00 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//# include "./libft.h"
# include <libft.h>
# include <unistd.h> //Execve, fork, dup, dump2, write,
# include <stdio.h> // perror
# include <string.h> // strerror
# include <fcntl.h> // To Open a file

// # define STDIN		0
// # define STDOUT		1
# define STDERR		2 // TODO: fileDescriptor 2

# define GREY 			"\033[0;90m"
# define RED			"\033[0;31m"
# define RESET 			"\033[0m"


# define ERROR_ARGS 	1
# define E_ARGS_MSG "\nError Code 1. Invalid number of arguments. Expected 5 \nSample: ./bin/pipex file1 cmd1 cmd2 file2\n\n"


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

/**
 * @brief
 *
 * @param argv
 */
void validate_files(char **argv);

//Testes - Del this
// int	startTest(int argc, char **argv);
// int	startTest2(int argc, char **argv);
// int	startTest3(int argc, char **argv);
// int	startTest4(int argc, char **argv);
// int	startTest5(int argc, char **argv);
int	startTest6(int argc, char **argv, char **envp);



#endif
