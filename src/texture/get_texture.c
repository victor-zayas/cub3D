/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:19:53 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/08 15:38:34 by vzayas-s         ###   ########.fr       */
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
	int		y;
	char	*path;

	y = -1;
	path = NULL;
	while (map->raw[++y])
	{
		if (ft_strnstr(map->raw[y], id, ft_strlen(map->raw[y])))
		{
			if (ft_strnstr(map->raw[y], "./", ft_strlen(map->raw[y])))
			{
				path = ft_strdup(ft_strnstr(map->raw[y], "./", ft_strlen(map->raw[y])));
				break ;
			}
			else
			{
				printf("Error\nNo texture path '%s' \n", map->raw[y]);
				exit(1);
			}
		}
	}
	if (!map->raw[y])
	{
		printf("Error\nNo id '%s' \n", id);
		exit(1);
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
	ft_check_texture(texture);
}

/**
 * @brief find the path to RGB colors on map->raw info
 * 
 * @param map 
 * @param id 
 * @return char* path of RGB color
 */
static	int	*ft_find_color(t_map *map, char id)
{
	int	y;
	int	x;
	int	*rgb;

	y = -1;
	x = 0;
	rgb = NULL;
	while (map->raw[++y])
	{
		if (ft_strchr(map->raw[y], id))
		{
			while (map->raw[y][x] == ' ')
				x++;
			while (ft_isalnum(map->raw[y][x]))
				x++;
			rgb = ft_check_color(ft_strtrim(map->raw[y] + 2, " "));
		}
	}
	return (rgb);
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
	int *rgb;
	
	rgb = ft_find_color(map, 'C');
	texture->C = ((rgb[0] & 255) << 16) | ((rgb[1] & 255) << 8) | ((rgb[2] & 255));
	free(rgb);
	rgb = ft_find_color(map, 'F');
	texture->F = ((rgb[0] & 255) << 16) | ((rgb[1] & 255) << 8) | ((rgb[2] & 255));
	free(rgb);
}
