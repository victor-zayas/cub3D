/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:19:39 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/18 18:45:51 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3D.h"

/**
 * @brief check if there first and  last lines of the map are walls(1)
 * 
 * @param str string recived
 * @return int return 1 in case of error
 */
static	int	ft_check_top_bot(char *str)
{
	int i;

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
	int i;
	int len;

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
		if ((str[i] == '0' || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
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
static	void	ft_check_wall(t_map *map)
{
	int	x;

	x = 0;
	if (ft_check_top_bot(map->map[x]))
	{
		// printf("%s\n", map->map[x]);
		printf("Error\nNo wall on top\n");
		exit(1);
	}
	while (map->map[x])
	{
		if (ft_check_side(map->map[x]))
		{
			printf("%s\n", map->map[x]);
			printf("Error\nNo wall on side\n");
			exit(1);
		}
		x++;
	}
	if (ft_check_top_bot(map->map[x - 1]))
	{
		// printf("%s\n", map->map[x - 1]);
		printf("Error\nNo wall on bottom\n");
		exit(1);
	}
}

/**
 * @brief read the map and count the start possition characters
 * 
 * @param map 
 * @param attrb 
 */
static	void	ft_count_attrb(t_map *map, t_attrb *attrb)
{
	int		x;
	int		y;
	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == 'N')
				attrb->n++;
			if (map->map[x][y] == 'S')
				attrb->s++;
			if (map->map[x][y] == 'E')
				attrb->e++;
			if (map->map[x][y] == 'W')
				attrb->w++;
		}
	}
}

/**
 * @brief check if the map has all acepted characters in map,
 * 		  in error case return the possition of invalid character
 * 
 * @param map 
 */
static	void	ft_check_attrb(t_map *map)
{
	int		x;
	int		y;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] != 'N' && map->map[x][y] != 'S'
			&& map->map[x][y] != 'E' && map->map[x][y] != 'W'
			&& map->map[x][y] != '1' && map->map[x][y] != '0'
			&& map->map[x][y] != '\n' && map->map[x][y] != ' ')
			{
				printf("Error\nInvalid character in map: %d, %d : %c\n",
					x, y, map->map[x][y]);
				exit(1);
			}
		}
	}
}

/**
 * @brief check if there is more than one starting possition & if there is no starting possition,
 * 		  in error case return a custom message
 * 
 * @param map 
 * @param attrb 
 */
static	void	ft_check_init_poss(t_map *map, t_attrb *attrb)
{
	ft_count_attrb(map, attrb);
	if (!(attrb->n || attrb->s || attrb->e || attrb->w))
	{
		printf("Error\nStarting position not found\n");
		exit(1);
	}
	else
	{
		if (attrb->n && (attrb->s || attrb->e || attrb->w))
			printf("Error\nThere is more than one starting possition\n");
		if (attrb->s && (attrb->n || attrb->e || attrb->w))
			printf("Error\nThere is more than one starting possition\n");
		if (attrb->e && (attrb->s || attrb->n || attrb->w))
			printf("Error\nThere is more than one starting possition\n");
		if (attrb->w && (attrb->s || attrb->e || attrb->n))
			printf("Error\nThere is more than one starting possition\n");
	}
}

void	ft_check_map(t_map *map, t_attrb *attrb)
{
	ft_check_wall(map);
	ft_check_attrb(map);
	ft_check_init_poss(map, attrb);
}
