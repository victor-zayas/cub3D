/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:36 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:40 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief check the file descriptor, in error case exit the program
 * 		  with custom message
 * 
 * @param fd 
 */
void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		close(fd);
		ft_exit("Invalid fd");
	}
}

/** 
 * @brief check the read parameter of file, in error case exit the program
 * 		  with custom message
 * 
 * @param rd 
 */
void	ft_check_read(int rd)
{
	if (rd <= 0)
		ft_exit("Invalid file");
}

/**
 * @brief check the file extension, in error case exit the program
 * 		  with custom message
 * 
 * @param str 
 */
void	ft_check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 5 && ft_strncmp(str + len - 4, ".cub", 4) == 0)
		return ;
	printf("Error\nInvalid map extension '%s'\n", str);
	exit(1);
}

/**
 * @brief check the file extension, in error case exit the program
 * 		  with custom message
 * 
 * @param str 
 */
void	ft_check_ext_texture(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 5 && ft_strncmp(str + len - 4, ".xpm", 4) == 0)
		return ;
	printf("Error\nInvalid map extension '%s'\n", str);
	exit(1);
}

/**
 * @brief check the game map, if it's empty exit the program
 * 		  with custom message
 * 
 * @param map 
 */
void	ft_empty_map(t_map *map)
{
	if (ft_read_map(map) == 0)
		ft_exit("Empty map");
}
