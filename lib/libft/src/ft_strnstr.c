/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlins <rlins@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:28:14 by rlins             #+#    #+#             */
/*   Updated: 2022/09/04 10:35:29 by rlins            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../../include/libft.h"
#include <libft.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	s2len;
	size_t	i;
	size_t	j;

	s2len = ft_strlen(s2);
	if (s1 == s2 || s2len == 0)
		return ((char *)s1);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0'
			&& (i + j) < len && s1[i + j] == s2[j])
		{
			j++;
			if ((j == len && j == s2len) || j == s2len)
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}
