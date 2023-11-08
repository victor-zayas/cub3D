/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:39:09 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/08 14:50:45 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	floor_ceil(t_mlx *mlx, int *start, int *color, int i)
{
	int	n;
	int	rgb;
	int addr; 
 
	rgb = ((color[0] & 255) << 16) | ((color[1] & 255) << 8) | ((color[2] & 255)); //converts rgb to hex should be called before raycasting
	n = start[0];
	while (n < start[1])
	{
		//mlx_pixel_put(mlx->mlx, mlx->win, i, n, rgb);
		addr = (n * mlx->size) + (i * (mlx->bpp / 8));
		*(unsigned int*)(mlx->addr + addr) = rgb;
		n++;
	}

}

int	calc_height(t_ray *ray)
{
	int proyection =   (64) * 280 / ray->dist;
	return (proyection);
}

int get_pixel(int n, int i, t_all *all, char dir)
{
	int		addr;
	int		color;
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
	
}

void	draw_wall(t_ray *col, t_all *all, int *start_stop, int i)
{
	int		n;
	float	delta_y;
	int		color;
	int		addr;

	n = start_stop[0];
	delta_y = 64.0 / (float)col->height;
	while (n < start_stop[1])
	{
		color = get_pixel(n, i, all, col->tx);
		addr = (n * all->mlx.size) + (i * (all->mlx.bpp / 8));
		*(unsigned int*)(all->mlx.addr + addr) = color;
	}
}

void	draw_column(t_ray *col, t_all *all, t_mlx *mlx, int i)
{
	int	start_stop[2];


	start_stop[0] = 0;
	fix_fisheye(col);
	col->height = calc_height(col);
	//printf("height: %d\n", height);
	start_stop[1] = (HEIGHT - col->height) / 2;
	//printf("ceiling start: %d, end: %d\n", start_stop[0], start_stop[1]);
	floor_ceil(mlx, start_stop, all->texture.C, i);
	start_stop[0] = start_stop[1];
	start_stop[1] = col->height + ((HEIGHT - col->height) / 2);
	//printf("wall start: %d, end: %d\n", start_stop[0], start_stop[1]);
	draw_wall(col, all, start_stop, i);
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
