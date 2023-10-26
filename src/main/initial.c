/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:31 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/26 16:45:51 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

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

static	void	ft_init_img(t_img *img)
{
	img->img_NO = NULL;
	img->img_SO = NULL;
	img->img_EA = NULL;
	img->img_WE = NULL;
	img->addr_NO = NULL;
	img->addr_SO = NULL;
	img->addr_EA = NULL;
	img->addr_WE = NULL;
	img->bpp_NO = 0;
	img->bpp_SO = 0;
	img->bpp_EA = 0;
	img->bpp_WE = 0;
	img->size_NO = 0;
	img->size_SO = 0;
	img->size_EA = 0;
	img->size_WE = 0;
	img->end_NO = 0;
	img->end_SO = 0;
	img->end_EA = 0;
	img->end_WE = 0;
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
	ft_init_img(&all->img);
}
