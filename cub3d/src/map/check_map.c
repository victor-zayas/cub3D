/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:19:39 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 20:19:40 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3D.h"

static	void ft_count_attrb(t_map *map, t_attrb *attrb)
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

static	void	ft_chack_attrb(t_map *map)
{
	int		x;
	int		y;
	int		error;

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
				error = 1;
				break ;
			}
		}
		if (error == 1)
			break ;
	}
	if (error == 1)
	{
		printf("Error: invalid character in map: %d, %d : %c\n", x, y, map->map[x][y]);
		exit(1);
	}
}

static	void	ft_check_init_poss(t_map *map, t_attrb *attrb)
{
	ft_count_attrb(map, attrb);
	if (!(attrb->n || attrb->s || attrb->e || attrb->w))
	{
		printf("Error: starting position not found\n");
		exit(1);
	}
	else
	{
		if (attrb->n && (attrb->s || attrb->e || attrb->w))
			printf("Error: there is more than one starting possition\n");
		if (attrb->s && (attrb->n || attrb->e || attrb->w))
			printf("Error: there is more than one starting possition\n");
		if (attrb->e && (attrb->s || attrb->n || attrb->w))
			printf("Error: there is more than one starting possition\n");
		if (attrb->w && (attrb->s || attrb->e || attrb->n))
			printf("Error: there is more than one starting possition\n");
	}
}

void	ft_check_map(t_map *map, t_attrb *attrb)
{
	ft_count_attrb(map, attrb);
	//printf("CHECK_ATTRB\nN: %d\nS: %d\nE: %d\nW: %d\n", attrb->n, attrb->s, attrb->e, attrb->w);
	ft_chack_attrb(map);
	//printf("CHECK_INIT_POSS\nN: %d\nS: %d\nE: %d\nW: %d\n", attrb->n, attrb->s, attrb->e, attrb->w);
	ft_check_init_poss(map, attrb);
}
