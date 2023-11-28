/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfilesize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:05:34 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/28 19:30:44 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getfile_size(int fd)
{
	char	character;
	int		size;

	size = 0;
	while (read(fd, &character, 1))
	{
		if (character == '\n')
			size++;
	}
	return (size);
}
