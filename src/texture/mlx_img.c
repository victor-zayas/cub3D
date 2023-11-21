/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:10:01 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 14:51:42 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_get_img(t_all *all)
{
	int width;
	int	height;

	width = 64;
	height = 64;
	// IMAGE
	
	all->north.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.NO, &width, &height);
	all->south.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.SO, &width, &height);
	all->east.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.EA, &width, &height);
	all->west.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.WE, &width, &height);
	// ADDRESS
	all->north.addr = mlx_get_data_addr(all->north.img, &all->north.bpp, &all->north.size, &all->north.end);
	all->south.addr = mlx_get_data_addr(all->south.img, &all->south.bpp, &all->south.size, &all->south.end);
	all->east.addr = mlx_get_data_addr(all->east.img, &all->east.bpp, &all->east.size, &all->east.end);
	all->west.addr = mlx_get_data_addr(all->west.img, &all->west.bpp, &all->west.size, &all->west.end);
	free(all->texture.NO);
	free(all->texture.SO);
	free(all->texture.EA);
	free(all->texture.WE);
}

void	ft_free_img(t_all *all)
{
	mlx_destroy_image(all->mlx.mlx ,all->north.img);
	mlx_destroy_image(all->mlx.mlx ,all->south.img);
	mlx_destroy_image(all->mlx.mlx ,all->east.img);
	mlx_destroy_image(all->mlx.mlx ,all->west.img);
}
