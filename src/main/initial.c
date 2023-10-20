/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:31 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/05 11:11:28 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3D.h"

/**
 * @brief initialize map struct
 * 
 * @param map map info struct
 * @param name name of .cub file
 */
static	void	ft_init_map(t_map *map, char *name)
{
	map->raw = NULL;
	map->map = NULL;
	map->name = name;
	map->fd = -1;
	map->height = 0;
	map->width = 0;
}

/**
 * @brief initialize attrb struct
 * 
 * @param attrb attributes of map info struct
 */
static	void	ft_init_attrb(t_attrb *attrb)
{
	attrb->n = 0;
	attrb->s = 0;
	attrb->e = 0;
	attrb->w = 0;
}

/**
 * @brief initialize texture struct
 * 
 * @param texture texture path from .cub file
 */
static	void	ft_init_texture(t_texture *texture)
{
	texture->NO = NULL;
	texture->SO = NULL;
	texture->EA = NULL;
	texture->WE = NULL;
	texture->C = NULL;
	texture->F = NULL;
}

/**
 * @brief initialize all structs
 * 
 * @param all main struct
 * @param name name of .cub file form name field in map struct
 */
void	ft_init_struct(t_all *all, char *name)
{
	ft_init_map(&all->map, name);
	ft_init_attrb(&all->attrb);
	ft_init_texture(&all->texture);
}
