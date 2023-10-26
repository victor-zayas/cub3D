/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:10:01 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/26 16:33:00 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_get_img(t_all *all)
{
	// IMAGE
	all->img.img_NO = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.NO, 64, 64);
	all->img.img_SO = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.SO, 64, 64);
	all->img.img_EA = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.EA, 64, 64);
	all->img.img_WE = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.WE, 64, 64);
	// ADDRESS
	all->img.addr_NO = mlx_get_data_addr(all->img.img_NO, &all->img.bpp_NO, &all->img.size_NO, &all->img.end_NO);
	all->img.addr_SO = mlx_get_data_addr(all->img.img_SO, &all->img.bpp_SO, &all->img.size_SO, &all->img.end_SO);
	all->img.addr_EA = mlx_get_data_addr(all->img.img_EA, &all->img.bpp_EA, &all->img.size_EA, &all->img.end_EA);
	all->img.addr_WE = mlx_get_data_addr(all->img.img_WE, &all->img.bpp_WE, &all->img.size_WE, &all->img.end_WE);
}
