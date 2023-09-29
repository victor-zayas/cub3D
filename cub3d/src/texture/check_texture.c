/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:19:53 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/29 13:42:19 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief find the path to textures on map->raw info
 * 
 * @param map 
 * @param id name of texture you want to find
 * @return char* return the path to texture selected by ID
 */
static	char	*ft_find_texture(t_map *map, char *id)
{
	int y;
	char *path;

	y = -1;
	path = NULL;
	while (map->raw[++y])
	{
		// printf("Entra en el bucle\n");
		if (ft_strnstr(map->raw[y], id, ft_strlen(map->raw[y])))
		{
			// printf("Encuentra el ID\n");
			if (ft_strnstr(map->raw[y], "./", ft_strlen(map->raw[y])))
			{
				// printf("Encuentra el PATH\n");
				path = ft_strdup(ft_strnstr(map->raw[y], "./", ft_strlen(map->raw[y])));
				break ;
			}
		}
	}
	return (path);
}

/**
 * @brief fill the texture struct with path to textures
 * 
 * @param map 
 * @param texture 
 */
void	ft_get_texture(t_map *map, t_texture *texture)
{
	texture->NO = ft_find_texture(map, "NO");
	texture->SO = ft_find_texture(map, "SO");
	texture->EA = ft_find_texture(map, "EA");
	texture->WE = ft_find_texture(map, "WE");
}

/**
 * @brief find the path to RGB colors on map->raw info
 * 
 * @param map 
 * @param id 
 * @return char* path of RGB color
 */
static	char	*ft_find_color(t_map *map, char id)
{
	int y;
	int x;
	char path;

	y = -1;
	x = 0;
	path = NULL;
	while (map->raw[++y])
	{
		if (ft_strchr(map->raw[y], id))
		{
			while (ft_isalnum(map->raw[y][x]))
				x++;
			path = ft_strdup(map->map[y]); // TODO buscar como coño hago esta mierda;
		}
	}
	return (path);
}

/**
 * @brief fill the texture struct with path to RGB colors
 * 
 * @param map 
 * @param texture 
 * @return * void 
 */
void	ft_get_color(t_map *map, t_texture *texture)
{
	texture->C = ft_find_color(map, 'C');
	printf("Ceiling -> %s\n", texture->C);
	texture->F = ft_find_color(map, 'F');
	printf("Floor -> %s\n", texture->F);
}
