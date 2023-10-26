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
# include "../../includes/raycast.h"

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

	arctan = -1 / tan(ray->ra);
	if (ray->ra > PI) //looking down
	{
		ray->ry = (((int)p_pos->py >> 6) << 6) - 0.0001;
		ray->rx = (p_pos->py - ray->ry) * arctan + p_pos->px;
		ray->yo = -64;
		ray->xo = -ray->yo * arctan;
	}
	if (ray->ra < PI) //looking up
	{
		ray->ry = (((int)p_pos->py >> 6) << 6) +64;
		ray->rx = (p_pos->py - ray->ry) * arctan + p_pos->px;
		ray->yo = 64;
		ray->xo = -ray->yo * arctan;
	}
	if (ray->ra == 0 || ray->ra == PI) //looking straight left or straight right
	{
		ray->rx = p_pos->px;
		ray->ry = p_pos->py;
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

t_ray	check_h_colision(t_playerpos *p_pos, t_map *map, float ra)
{
	t_ray	ray;
	int		end;

	end = 0;
	ray.ra = ra;
	ray.end = 0;
	h_offset_calc(p_pos, &ray);
	while (!end)
	{
		ray.mx = (int) (ray.rx) >> 6;
		ray.my = (int) (ray.ry) >> 6;
		if (map->map[ray.my][ray.mx] == '1') // have to add out of map control just in case
		{
			ray.cx = ray.rx;
			ray.cy = ray.ry;
			end = 1;
		}
		else
		{
			ray.rx += ray.xo;
			ray.ry += ray.yo;
		}
	}
	if (ray.ra > PI) //looking down
		return (ray.tx = 'S', ray);
	else
		return (ray.tx = 'N', ray);
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

	ntan = -tan(ray->ra);
	if (ray->ra > P2 && ray->ra < P32) //looking left
	{
		ray->rx = (((int)p_pos->px >> 6) << 6) - 0.0001;
		ray->ry = (p_pos->px - ray->rx) * ntan + p_pos->py;
		ray->xo = -64;
		ray->yo = -ray->xo * ntan;
	}
	if (ray->ra < P2 || ray->ra > P32) //looking right
	{
		ray->rx = (((int)p_pos->px >> 6) << 6) +64;
		ray->ry = (p_pos->px - ray->rx) * ntan + p_pos->py;
		ray->xo = 64;
		ray->yo = -ray->yo * ntan;
	}
	if (ray->ra == P2 || ray->ra == P32) //looking straight up or straight down
	{
		ray->rx = p_pos->px;
		ray->ry = p_pos->py;
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

t_ray	check_v_colision(t_playerpos *p_pos, t_map *map, float ra)
{
	t_ray	ray;
	int		i;

	ray.ra = ra;
	ray.end = 0;
	i = 0;
	v_offset_calc(p_pos, &ray);
	printf("ray angle %f\n", ra);
	while (!ray.end)
	{
		printf("iteration %d\n", i++);
		ray.mx = (int) (ray.rx) >> 6;
		ray.my = (int) (ray.ry) >> 6;
		printf("ray mx:%d ray my%d\n", ray.mx, ray.my);
		if (map->map[ray.my][ray.mx] == '1') // have to add out of map control just in case
		{
			ray.cx = ray.rx;
			ray.cy = ray.ry;
			ray.end = 1;
		}
		else
		{
			ray.rx += ray.xo;
			ray.ry += ray.yo;
		}
	}
	if (ray.ra > P2 && ray.ra < P32)
		return (ray.tx = 'W', ray);
	else
		return (ray.tx = 'E', ray);
}

/**
 * @brief casts the  rays and decide the texture that is needed for the column.
 * 
 * @param p_pos	playerposition structure
 * @param map	map structure
 * @param text	texture
 */

void	raycaster(t_playerpos *p_pos, t_all *all, t_mlx *mlx) //here we need to get the big structure as we will need it later to draw the line.
{
	t_ray	vc;
	t_ray	hc;
	float	ra;
	int		i;

	ra = p_pos->pa + (46 * DEG);
	i = 0;
	while (i < 90)
	{
		ra = fix_angle(ra - DEG);
		vc = check_v_colision(p_pos, &all->map, ra);
		hc = check_h_colision(p_pos, &all->map, ra);
		if (dist(&vc, p_pos) > dist(&hc, p_pos))
		{
			//take_texture(&hc, text);
			draw_column(&hc, all, mlx, i);
		}
		else
		{
			//take_texture(&vc, text);
			draw_column(&vc, all, mlx, i);
		}
		i++;
	}
}
