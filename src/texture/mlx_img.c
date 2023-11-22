/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:10:01 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/22 13:10:49 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief get address of textures & and free
 * 
 * @param all principal struct
 */
void	ft_get_img(t_all *all, int *txt_size)
{
	all->north.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.no,
			txt_size, txt_size);
	all->south.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.so,
			txt_size, txt_size);
	all->east.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.ea,
			txt_size, txt_size);
	all->west.img = mlx_xpm_file_to_image(all->mlx.mlx, all->texture.we,
			txt_size, txt_size);
	if (!all->north.img || !all->south.img || !all->west.img || !all->east.img)
		return (ft_putstr_fd("Texture error, only 64x64px\n", 2), ft_close(all));
	all->north.addr = mlx_get_data_addr(all->north.img, &all->north.bpp,
			&all->north.size, &all->north.end);
	all->south.addr = mlx_get_data_addr(all->south.img, &all->south.bpp,
			&all->south.size, &all->south.end);
	all->east.addr = mlx_get_data_addr(all->east.img, &all->east.bpp,
			&all->east.size, &all->east.end);
	all->west.addr = mlx_get_data_addr(all->west.img, &all->west.bpp,
			&all->west.size, &all->west.end);
	free(all->texture.no);
	free(all->texture.so);
	free(all->texture.ea);
	free(all->texture.we);
}

/**
 * @brief free img struct
 * 
 * @param all 
 */
void	ft_free_img(t_all *all)
{
	if (all->north.img)
		mlx_destroy_image(all->mlx.mlx, all->north.img);
	if (all->south.img)
		mlx_destroy_image(all->mlx.mlx, all->south.img);
	if (all->west.img)
		mlx_destroy_image(all->mlx.mlx, all->east.img);
	if (all->east.img)
		mlx_destroy_image(all->mlx.mlx, all->west.img);
}
