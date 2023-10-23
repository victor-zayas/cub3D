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

#include <math.h>
#include "../../includes/cub3D.h"
#include "../../includes/raycast.h"

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
	return (ray);
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

	ray.ra = ra;
	ray.end = 0;
	v_offset_calc(p_pos, &ray);
	while (!ray.end)
	{
		ray.mx = (int) (ray.rx) >> 6;
		ray.my = (int) (ray.ry) >> 6;
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
	return (ray);
}

void	raycaster(t_playerpos *p_pos, t_map *map, t_texture *text)
{
	t_ray	vc;
	t_ray	hc;
	float	ra;
	int		i;

	ra = p_pos->pa + (45 * DEG);
	i = 0;
	while (i < 90)
	{
		ra = fix_angle(ra);
		vc = check_v_colision(p_pos, map, ra);
		hc = check_h_colision(p_pos, map, ra);
		if (dist(vc.cx, vc.cy, p_pos, vc.end)
			> dist(hc.cx, hc.cy, p_pos, hc.end))
		
	}
}
