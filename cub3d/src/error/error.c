/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:36 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 20:12:51 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3D.h"

void	ft_check_fd(int fd)
{
	if (fd < 0 || fd == 2)
	{
		close(fd);
		printf("Error: Invalid fd\n");
		exit(1);
	}
}

void	ft_check_format(char *str)
{
	if (!ft_strnstr(str, ".cub", ft_strlen(str)))
	{
		printf("Error: invalid map format\n");
		exit(1);
	}
}

void	ft_empty_map(t_map *map)
{
	if (ft_read_map(map) == 0)
	{
		printf("Error: empty map\n");
		exit (1);
	}
}
