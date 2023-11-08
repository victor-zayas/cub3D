/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:10:01 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/08 17:16:02 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_get_img(t_all *all)
{
	// IMAGE
	all->north.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.NO, 64, 64);
	all->south.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.SO, 64, 64);
	all->east.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.EA, 64, 64);
	all->west.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.WE, 64, 64);
	// ADDRESS
	all->north.addr = mlx_get_data_addr(all->north.img, &all->north.bpp, &all->north.size, &all->north.end);
	all->south.addr = mlx_get_data_addr(all->south.img, &all->south.bpp, &all->south.size, &all->south.end);
	all->east.addr = mlx_get_data_addr(all->east.img, &all->east.bpp, &all->east.size, &all->east.end);
	all->west.addr = mlx_get_data_addr(all->west.img, &all->west.bpp, &all->west.size, &all->west.end);
}
