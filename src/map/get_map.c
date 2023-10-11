/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:42 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/11 21:59:06 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief read the map and give the size of file
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
	int		i;

	i = -1;
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
    while (map->raw[++i])
        map->raw[i] = ft_strtrim(map->raw[i], " ");
	close(map->fd);
	free(aux);
}

/**
 * @brief check if map is the last element in file
 * 
 * @param map 
 */
static	void	ft_check_order(t_map *map)
{
	int	x;
	
	x = -1;
	while (++x < 5)
	{
		if (map->raw[x][0] != 'N' && map->raw[x][0] != 'S' && map->raw[x][0] != 'E'
			&& map->raw[x][0] != 'W' && map->raw[x][0] != 'F' && map->raw[x][0] != 'C')
		{
			//printf("line: %d, content: %s\n", x, map->raw[x]);
			printf("Error: map isn't the last parameter\n");
			exit(1);
		}
	}
}

/**
 * @brief fill the map of map->map with map->raw data & check map attributes
 * 
 * @param map 
 * @param attrb 
 */
void	ft_get_map(t_map *map, t_attrb *attrb)
{
	int	i;
	int	j;

	i = 6;
	while (map->raw[i])
		i++;
	map->map = malloc(sizeof(char *) * i);
	if (!map->map)
		return ;
	j = -1;
	while (++j < i)
	{
		if (j >= 6)	
			map->map[j - 6] = map->raw[j];
	}
	map->map[i - 6] = NULL;
	ft_empty_map(map);
	ft_check_map(map, attrb);
}

/**
 * @brief load all functions of program
 * 
 * @param map 
 * @param texture 
 */
void	ft_start(t_all *all)
{
	ft_check_extension(all->map.name);
	ft_read_map(&all->map);
	ft_get_data(&all->map);
	ft_check_order(&all->map);
	ft_get_map(&all->map, &all->attrb);
	ft_get_texture(&all->map, &all->texture);
	ft_get_color(&all->map, &all->texture);
}
