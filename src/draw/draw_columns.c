/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:39:09 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/08 12:42:48 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	floor_ceil(t_mlx *mlx, int *start, int *color, int i)
{
	int	n;
	int	rgb;
	int addr; 
 
	// int	end = i * C_WIDTH + 12;
	// i *= 12;
	rgb = ((color[0] & 255) << 16) | ((color[1] & 255) << 8) | ((color[2] & 255)); //converts rgb to hex should be called before raycasting
	// while (i < end)
	// {
		n = start[0];
		while (n < start[1])
		{
			//mlx_pixel_put(mlx->mlx, mlx->win, i, n, rgb);
			addr = (n * mlx->size) + (i * (mlx->bpp / 8));
			*(unsigned int*)(mlx->addr + addr) = rgb;
			n++;
		}
	// 	i++;
	// 	//printf("i: %d n: %d\n", i, n);
	// }
}

int	calc_height(t_ray *ray)
{
	int proyection =   (64) * 280 / ray->dist;
	return (proyection);
}

void	draw_column(t_ray *col, t_all *all, t_mlx *mlx, int i)
{
	int	height;
	int	start_stop[2];


	start_stop[0] = 0;
	fix_fisheye(col);
	height = calc_height(col);
	//printf("height: %d\n", height);
	start_stop[1] = (HEIGHT - height) / 2;
	//printf("ceiling start: %d, end: %d\n", start_stop[0], start_stop[1]);
	floor_ceil(mlx, start_stop, all->texture.C, i);
	start_stop[0] = start_stop[1];
	start_stop[1] = height + ((HEIGHT - height) / 2);
	//printf("wall start: %d, end: %d\n", start_stop[0], start_stop[1]);
	//draw_wall(col, mlx, start_stop, i);
	start_stop[0] = start_stop[1];
	start_stop[1] = HEIGHT;
	//printf("floor start: %d, end: %d\n", start_stop[0], start_stop[1]);
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
				p_pos->pa = P_2;
			else if (map[n][m] == 'E')
				p_pos->pa = (float)0;
			else if (map[n][m] == 'W')
				p_pos->pa = PI;
			else if (map[n][m] == 'S')
				p_pos->pa = P3_2;
		}
	}
}
