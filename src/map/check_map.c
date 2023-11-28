/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:19:39 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/28 19:32:55 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief check if there is space, '\n', '\0' next to wallkable space 
 * 
 * @param map 
 */
void	ft_check_inside(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == '0' && (map->map[x - 1][y] == '\n'
				|| map->map[x - 1][y] == ' ' || map->map[x - 1][y] == '\0'))
			{
				printf("%s\n", map->map[x]);
				printf("Error\nNo wall closed\n");
				exit(1);
			}
		}
	}
}

/**
 * @brief check if there first and  last lines of the map are walls(1)
 * 
 * @param str string recived
 * @return int return 1 in case of error
 */
static	int	ft_check_top_bot(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1')
			return (1);
	}
	return (0);
}

/**
 * @brief check if the string has wall(1) at the beging and end,
 * 		  also check if the is spaces inside map
 * 
 * @param str string receibed
 * @return int return 1 in case of error
 */
static	int	ft_check_side(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '1' || str[len - 1] != '1')
		return (1);
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if ((str[i] == '0' || str[i] == 'N' || str[i] == 'S' || str[i] == 'E'
				|| str[i] == 'W')
			&& (str [i - 1] == ' ' || str[i + 1] == ' '))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief check if there are no walls or empty espaces inside map,
 * 		  in error case return a custom messagge
 * 
 * @param map 
 */
void	ft_check_wall(t_map *map)
{
	int	x;

	x = 0;
	if (ft_check_top_bot(map->map[x]))
	{
		printf("Error\nNo wall on top\n");
		exit(1);
	}
	while (map->map[x])
	{
		if (ft_check_side(map->map[x]))
		{
			printf("Error\nNo wall on side\n");
			exit(1);
		}
		x++;
	}
	ft_check_inside(map);
	if (ft_check_top_bot(map->map[x - 1]))
	{
		printf("Error\nNo wall on bottom\n");
		exit(1);
	}
}

/**
 * @brief gives the longest line of map to limit raycast
 * 
 * @param map 
 */
void	ft_map_dimensions(t_map *map)
{
	int		x;
	int		max;
	int		now;

	max = ft_strlen(map->map[0]);
	x = 0;
	while (map->map[x])
	{
		now = ft_strlen(map->map[x]);
		if (now > max)
			max = now;
		x++;
	}
	map->height = x;
	map->width = max;
}
