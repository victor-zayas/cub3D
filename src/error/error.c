/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:36 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/04 14:01:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3D.h"

/**
 * @brief check the file descriptor, in error case exit the program with custom message
 * 
 * @param fd 
 */
void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		close(fd);
		printf("Error: Invalid fd\n");
		exit(1);
	}
}

/** check the read parameter of file, in error case exit the program with custom message
 * @brief 
 * 
 * @param rd 
 */
void	ft_check_read(int rd)
{
	if (rd <= 0)
	{
		printf("Error: empty file\n");
		exit(1);
	}
}

/**
 * @brief check the file extension, in error case exit the program with custom message
 * 
 * @param str 
 */
void	ft_check_extension(char *str)
{
	int i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (!(ft_strnstr(ft_strrchr(str, '.'), ".cub", 4)) && str[i + 4] == '\0')
	{
		printf("Error: invalid map extension %s\n", str);
		exit(1);
	}
}

/**
 * @brief check the game map, if it's empty exit the program with custom message
 * 
 * @param map 
 */
void	ft_empty_map(t_map *map)
{
	if (ft_read_map(map) == 0)
	{
		printf("Error: empty map\n");
		exit (1);
	}
}
