/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:19:53 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 23:49:17 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

void	ft_get_textutes(t_map *map, t_texture *texture)
{
	// int y;
	// int	x;
	// int poss;

	// y = -1;
	// x = -1;
	// poss = 0;
	// while (map->map[++y])
	// {
 	// if (ft_strncmp(map->map[y], "NO", 2) == 0)
	// 	{
	// 		printf("this is NO-> %s\n",map->map[y]);
	// 		printf("found NO\n");
	// 	 	return ;
	// 	}
	// 	while (map->map[y][++x] == ' ')
	// 		texture->NO = &map->map[y][x];
    //  else if (ft_strnstr(map->map[y], "SO", 2))
    //  	texture->SO = map->map[y];
    //   else if (ft_strnstr(map->map[y], "EA", 2))
    //   	texture->EA = map->map[y];
    //   else if (ft_strnstr(map->map[y], "WE", 2))
    //   	texture->WE = map->map[y];
	// }
	// if (texture->NO == NULL || texture->SO == NULL || texture->EA == NULL || texture->WE == NULL)
	// 	printf("Error: %s texture not found\n", map->map[y]);
	// printf("TEXTURES\nNO:%s\nSO:%s\nWE:%s\nEA:%s\n\n", texture->NO, texture->SO, texture->WE, texture->EA);
	(void)map;
	(void)texture;
}

/* void	ft_check_textures(t_texture *texture)
{
	
}
 */