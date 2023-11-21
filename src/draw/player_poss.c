/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_poss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:59:12 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 16:32:26 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_column(t_ray *col, t_all *all, t_mlx *mlx, int i)
{
	int	start_stop[2];

	start_stop[0] = 0;
	fix_fisheye(col, &all->player);
	col->height = calc_height(col);
	start_stop[1] = (HEIGHT - col->height) / 2;
	floor_ceil(mlx, start_stop, all->texture.c, i);
	start_stop[0] = start_stop[1];
	start_stop[1] = col->height + ((HEIGHT - col->height) / 2);
	draw_wall(col, all, start_stop, i);
	start_stop[0] = start_stop[1];
	start_stop[1] = HEIGHT;
	floor_ceil(mlx, start_stop, all->texture.f, i);
}

void	get_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size, &mlx->endian);
}

void	search_playerpos(char **map, t_playerpos *p_pos)
{
	int	n;
	int	m;

	n = -1;
	while (map[++n])
	{
		m = -1;
		while (map[n][++m])
		{
			if (map[n][m] == 'N' || map[n][m] == 'E' || map[n][m] == 'W'
				|| map[n][m] == 'S')
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
