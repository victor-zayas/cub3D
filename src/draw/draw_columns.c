/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:39:09 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/26 17:25:50 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	floor_ceil(t_mlx *mlx, int *start, int *color, int i)
{
	int	n;
	int	rgb;

	n = 0;
	rgb = ((color[0] & 255) << 16) | ((color[1] & 255) << 8) | ((color[2] & 255));
	while (n < start[0])
	{
		mlx->addr[i * mlx->size + n] =  rgb;
		n++;
	}
}

void	draw_column(t_ray *col, t_all *all, t_mlx *mlx, int i)
{
	int	height;
	int	start_stop[2];

	start_stop[0] = 0;
	fix_fisheye(col, &all->player);
	height = 300;
	start_stop[1] = ((HEIGHT - height) / 2) >> 6;
	//height = calc_height(col, p_pos);
	floor_ceil(mlx, start_stop, all->texture.C, i);
	start_stop[0] = 300 + (HEIGHT - height) / 2 ;
	start_stop[1] = HEIGHT;
	floor_ceil(mlx, start_stop, all->texture.F, i);
}

void	get_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size
		, &mlx->endian);
}

void    search_playerpos(char **map, t_playerpos *p_pos)
{
	int n;
	int m;

	n = -1;
	while (map[++n])
	{
		m = -1;
		while (map[n][++m])
		{
			if (map[n][m] == 'N' || map[n][m] == 'E' || map[n][m] == 'W' || map[n][m] == 'S')
			{
				p_pos->py = 64 * n + 32;
				p_pos->px = 64 * m + 32;
			}
			if (map[n][m] == 'N')
				p_pos->pa = P2;
			else if (map[n][m] == 'E')
				p_pos->pa = (float)0;
			else if (map[n][m] == 'W')
				p_pos->pa = PI;
			else if (map[n][m] == 'S')
				p_pos->pa = P32;
		}
	}
}
