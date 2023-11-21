/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:02:02 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/19 18:02:02 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

#define BL "\033[0;34m"
#define CY "\033[0;36m"
#define WT "\033[0;37m"

/**
 * @brief Calculates the first horizontal collisions position and the offset
 * for the next one in case is needed.
 * 
 * @param p_pos 
 * @param ray.
 */

void	h_offset_calc(t_playerpos *p_pos, t_ray *ray)
{
	float	arctan;

	ray->end = 0;
	arctan = (1 / tan(ray->ra));
	if (ray->ra > PI) //looking down
	{
		ray->ry = (((int)p_pos->py >> 6) << 6) + 64;
		ray->rx = (p_pos->py - ray->ry) * arctan + p_pos->px;
		ray->yo = 64;
		ray->xo = ray->yo * -arctan;
	}
	if (ray->ra < PI) //looking up
	{
		ray->ry = (((int)p_pos->py >> 6) << 6) - 0.0001;
		ray->rx = (p_pos->py - ray->ry) * arctan + p_pos->px;
		ray->yo = -64;
		ray->xo = ray->yo * -arctan;
	}
	if (ray->ra == 0 || ray->ra == PI) //looking straight left or straight right
	{
		ray->ry = p_pos->py;
		ray->rx = p_pos->px;
		ray->end = 2;
	}
}

/**
 * @brief Checks the collision with a horizontal lines of the map
 * 
 * @param p_pos	playerposition structure
 * @param map	map structure
 * @param ra 	ray angle
 * @return t_ray 
 */

void	check_h_colision(t_playerpos *p_pos, t_map *map, float ra, t_ray *ray)
{
	ray->ra = ra;
	h_offset_calc(p_pos, ray);
	while (!ray->end)
	{
		ray->my = (int)(ray->ry) >> 6;
		ray->mx = (int)(ray->rx) >> 6;
		if (ray->my < 0 || ray->mx < 0 || map->height <= ray->my
			|| (int)ft_strlen(map->map[ray->my]) <= ray->mx)
			ray->end = 2;
		else if (map->map[ray->my][ray->mx] == '1')
		{
			ray->cy = ray->ry;
			ray->cx = ray->rx;
			ray->end = 1;
		}
		else
		{
			ray->ry += ray->yo;
			ray->rx += ray->xo;
		}
	}
	if (ray->ra > PI) //looking down
		ray->tx = 'S';
	else
		ray->tx = 'N';
}

/**
 * @brief Calculates the first vertical collisions position and the offset
 * for the next one in case is needed.
 * 
 * @param p_pos 
 * @param ray.
 */

void	v_offset_calc(t_playerpos *p_pos, t_ray *ray)
{
	float	ntan;

	ntan = tan(ray->ra);
	if (ray->ra > P_2 && ray->ra < P3_2) //looking left
	{
		ray->rx = (((int)p_pos->px >> 6) << 6) - 0.0001;
		ray->ry = (p_pos->px - ray->rx) * ntan + p_pos->py;
		ray->xo = -64;
		ray->yo = ray->xo * -ntan;
	}
	if (ray->ra < P_2 || ray->ra > P3_2) //looking right
	{
		ray->rx = (((int)p_pos->px >> 6) << 6) + 64;
		ray->ry = (p_pos->px - ray->rx) * ntan + p_pos->py;
		ray->xo = 64;
		ray->yo = ray->xo * -ntan;
	}
	if (ray->ra == P2 || ray->ra == P3_2) //looking straight up or straight down
	{
		ray->ry = p_pos->py;
		ray->rx = p_pos->px;
		ray->end = 2;
	}
}

/**
 * @brief Checks the collision with a vertical lines of the map
 * 
 * @param p_pos	playerposition structure
 * @param map	map structure
 * @param ra 	ray angle
 * @return t_ray 
 */

void	check_v_colision(t_playerpos *p_pos, t_map *map, float ra, t_ray *ray)
{
	ray->ra = ra;
	v_offset_calc(p_pos, ray);
	while (!ray->end)
	{
		ray->my = (int)(ray->ry) >> 6;
		ray->mx = (int)(ray->rx) >> 6;
		if (ray->mx < 0 || ray->my < 0 || map->height <= ray->my
			|| (int)ft_strlen(map->map[ray->my]) <= ray->mx)
			ray->end = 2;
		else if (map->map[ray->my][ray->mx] == '1')
		{
			ray->cy = ray->ry;
			ray->cx = ray->rx;
			ray->end = 1;
		}
		else
		{
			ray->ry += ray->yo;
			ray->rx += ray->xo;
		}
	}
	if (ray->ra > P_2 && ray->ra < P3_2)
		ray->tx = 'W';
	else
		ray->tx = 'E';
}

// void	print_map(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	printf("   ");
// 	while (i < map->width)
// 		printf("%s|%s%03d", CY, BL, i++);
// 	printf("%s|\n", CY);
// 	i = 0;
// 	while (map->map[i])
// 	{
// 		k = 0;
// 		while (k < map->width * 3)
// 		{
// 			printf("%s__", CY);
// 			k++;
// 		}
// 		printf("\n");
// 		printf("%s%03d", BL, i);
// 		j = 0;
// 		while (map->map[i][j])
// 		{
// 			printf("%s|%s %c ", CY, WT, map->map[i][j++]);
// 		}
// 		printf("%s|\n%s", CY, WT);
// 		i++;
// 	}
// }

/**
 * @brief casts the  rays and decide the texture that is needed for the column.
 * 
 * @param p_pos	playerposition structure
 * @param map	map structure
 * @param text	texture
 */

void	raycaster(t_all *all)
{
	t_ray	vc;
	t_ray	hc;
	float	ra;
	int		i;

	ra = all->player.pa + (30 * DEG);
	i = 0;
	while (i < WIDTH)
	{
		ra = fix_angle(ra - DEG * 60 / WIDTH);
		vc.end = 0;
		hc.end = 0;
		check_v_colision(&all->player, &all->map, ra, &vc);
		check_h_colision(&all->player, &all->map, ra, &hc);
		if (dist(&vc, &all->player) > dist(&hc, &all->player))
			draw_column(&hc, all, &all->mlx, i);
		else
			draw_column(&vc, all, &all->mlx, i);
		i++;
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	return ;
}
