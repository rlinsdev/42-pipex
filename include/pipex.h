/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 07:17:02 by rlins             #+#    #+#             */
/*   Updated: 2022/09/03 19:54:39 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// # include "../lib/minilibx-linux/mlx.h"
// # include "./libft.h"
# include <unistd.h> //Execve
// # include <fcntl.h> // To Open a file
// #include <X11/keysym.h> // Type key code pressed
// #include <X11/X.h> // Type event em mask that hooks call


/**
 * @brief First method in project.
 * @param argc Arguments count
 * @param argv Arguments Vector
 * @return int
 */
int	start(int argc, char **argv);

//Testes - deletar depois
int	startTest(int argc, char **argv);
int	startTest2(int argc, char **argv);
int	startTest3(int argc, char **argv);
int	startTest4(int argc, char **argv);
int	startTest5(int argc, char **argv);
int	startTest6(int argc, char **argv, char **envp);

#endif
