/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:22:53 by rlins             #+#    #+#             */
/*   Updated: 2022/09/12 20:02:15 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	file_open(char *file, int mode)
{
	if (mode == IN)
	{
		// chmod: ----rw-r--
		return (open(file, O_RDONLY, 0644));
	}
	else
	{
		// TODO: Remove - To test forcing error:
		// file = "test_test_";
		/* Flags. Itś possible add multiple flags.
		 * (Truncated to 0 if something exist in file),
		 * (if file does not exist, create)
		 * (read and write)
		 */
		return (open(file, O_TRUNC | O_CREAT | O_RDWR, 0644));
	}
}
