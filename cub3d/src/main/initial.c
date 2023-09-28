/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:31 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 23:44:16 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3D.h"

void    ft_init_map(t_map *map, char *name)
{
    map->map = NULL;
    map->name = name;
    map->fd = -1;
}

/* void	ft_init_attrb(t_attrb *attrb)
{
	attrb->n = 0;
	attrb->s = 0;
	attrb->e = 0;
	attrb->w = 0;
} */

/* void	ft_init_texture(t_texture *texture)
{
	texture->NO = NULL;
	texture->SO = NULL;
	texture->EA = NULL;
	texture->WE = NULL;
} */
