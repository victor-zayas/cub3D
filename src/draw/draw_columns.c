/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:39:09 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/21 16:31:01 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief paints the ceiling and the floor with plain colors
 * 
 * @param mlx	mlx struct
 * @param start	a pointer that has the info of start and stop points
 * @param color	the color to be used to paint
 * @param i		the column of the window that will be painted. also ray number
 */

void	floor_ceil(t_mlx *mlx, int *start, int color, int i)
{
	int	n;
	int	addr;

	n = start[0];
	while (n < start[1])
	{
		if (n >= 0 && n < HEIGHT && i >= 0 && i < WIDTH)
		{
			addr = (n * mlx->size) + (i * (mlx->bpp / 8));
			*(unsigned int *)(mlx->addr + addr) = color;
		}
		n++;
	}
}

/**
 * @brief Calculates the height of the coulmn based on distance, texture
 			size and distance to the proyection plane
 * 
 * @param ray	
 * @return int the proyections height
 */

int	calc_height(t_ray *ray)
{
	int	proyection;

	proyection = (64) * 2.5 * 280 / ray->dist;
	return (proyection);
}

/**
 * @brief Gets the pixel from the texture
 * 
 * @param n 
 * @param i 
 * @param all 
 * @param dir 
 * @return int 
 */

unsigned	get_pixel(int n, int y_pos, t_all *all, char dir)
{
	t_img	img;
	int		addr;

	if (dir == 'N')
		img = all->north;
	else if (dir == 'S')
		img = all->south;
	else if (dir == 'E')
		img = all->east;
	else if (dir == 'W')
		img = all->west;
	if (n >= 64)
		n = 63;
	addr = (n * img.size) + (y_pos * (img.bpp / 8));
	return (*(unsigned int *)(img.addr + addr));
}

int	rev_check(int rev, t_ray *col)
{
	if (col->tx == 'S' || col->tx == 'W')
		return (63 - rev);
	else
		return (rev);
}

void	draw_wall(t_ray *col, t_all *all, int *start_stop, int i)
{
	int		n;
	float	delta_y[2];
	int		addr;
	int		pos;

	n = start_stop[0];
	delta_y[0] = 64.0 / (float)col->height;
	delta_y[1] = delta_y[0];
	if (col->tx == 'N' || col->tx == 'S')
		pos = ((int)col->cx % 64);
	else
		pos = ((int)col->cy % 64);
	while (n < start_stop[1])
	{
		if (n >= 0 && n < HEIGHT && i >= 0 && i < WIDTH)
		{
			addr = (n * all->mlx.size) + (i * (all->mlx.bpp / 8));
			*(unsigned int *)(all->mlx.addr + addr)
				= get_pixel((int)delta_y[0], rev_check(pos, col), all, col->tx);
		}
		delta_y[0] += delta_y[1];
		n++;
	}
}
