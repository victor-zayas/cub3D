/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:42 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 23:48:05 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

int	ft_read_map(t_map *map)
{
	int		rd;
	int		i;
	char	c;

    i = 0;
	map->fd = open(map->name, O_RDONLY);
	ft_check_fd(map->fd);
	ft_check_format(map->name);
	rd = 1;
	while ((rd = read(map->fd, &c, 1)) > 0)
        i++;
	close(map->fd);
    return (i);
}

//TODO leer todo directamente en esta funcion y asignarlo directamente
void	ft_get_map(t_map *map)
{
	char	*aux;
	int		i;
	int		rd = 0;

	i = 0;
	aux = malloc((sizeof(char) * ft_read_map(map)) + 1);
	map->fd = open(map->name, O_RDONLY);
	rd = read(map->fd, aux, ft_read_map(map));
	aux[rd - 1] = '\0';
	map->map = ft_split(aux, '\n');
	ft_empty_map(map);
	close(map->fd);
	free(aux);
}

void	ft_split_args(t_map *map, t_texture *texture)
{
	ft_read_map(map);
	ft_get_map(map);
	ft_get_textutes(map, texture);
}
