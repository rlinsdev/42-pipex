/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:15:39 by rlins             #+#    #+#             */
/*   Updated: 2022/09/07 10:04:43 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	error_handler(int code)
{
	// TODO: Chamar PrintF, nao write
	if (code == ERROR_ARGS)
		write(STDERR, E_ARGS_MSG, ft_strlen(E_ARGS_MSG));

	exit(code);
}
