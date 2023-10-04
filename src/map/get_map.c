/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:42 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/04 13:40:12 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief read the map
 * 
 * @param map 
 * @return int size of .cub file
 */
int	ft_read_map(t_map *map)
{
	int		rd;
	int		i;
	char	c;

    i = 0;
	ft_check_extension(map->name);
	map->fd = open(map->name, O_RDONLY);
	ft_check_fd(map->fd);
	rd = 1;
	while ((rd = read(map->fd, &c, 1)) > 0)
        i++;
	close(map->fd);
    return (i);
}

/**
 * @brief split the .cub file by '\n' & fill map->raw with all data to be checked
 * 
 * @param map 
 */
void	ft_get_data(t_map *map)
{
	char	*aux;
	int		rd;
	int		len;
	
	rd = 0;
	len = ft_read_map(map);
	aux = malloc((sizeof(char) * len) + 1);
	if (!aux)
		return ;
	map->fd = open(map->name, O_RDONLY);
	rd = read(map->fd, aux, len);
	ft_check_read(rd);
	aux[rd - 1] = '\0';
	map->raw = ft_split(aux, '\n');
	ft_empty_map(map);
	close(map->fd);
	free(aux);
}

/**
 * @brief start all actions of program
 * 
 * @param map 
 * @param texture 
 */
void	ft_start(t_map *map, t_texture *texture)
{
	ft_read_map(map);
	ft_get_data(map);
	ft_get_texture(map, texture);
	ft_get_color(map, texture);
}
