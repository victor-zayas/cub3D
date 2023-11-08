/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_attrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:33:50 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/08 13:59:33 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

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
 * @brief check if there is more than one starting possition,
 * 		  if there is no starting possition, in error case
 * 		  return a custom message
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
		if ((attrb->n && (attrb->s || attrb->e || attrb->w))
			|| (attrb->s && (attrb->n || attrb->e || attrb->w))
			|| (attrb->e && (attrb->s || attrb->n || attrb->w))
			|| (attrb->w && (attrb->s || attrb->e || attrb->n)))
		{
			printf("Error\nThere is more than one starting possition\n");
			exit(1);
		}
	}
}

/**
 * @brief check if the map has all acepted characters in map,
 * 		  in error case return the possition of invalid character
 * 
 * @param map 
 */
void	ft_check_attrb(t_map *map, t_attrb *attrb)
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
	ft_check_init_poss(map, attrb);
}
