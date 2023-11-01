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

	arctan = -tan(ray->ra);
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

t_ray	check_h_colision(t_playerpos *p_pos, t_map *map, float ra)
{
	t_ray	ray;

	ray.end = 0;
	ray.ra = ra;
	ray.end = 0;
	h_offset_calc(p_pos, &ray);
	while (!ray.end)
	{
		//printf("horizontal iteration %d\n", i++);
		ray.my = (int) (ray.ry) >> 6;
		ray.mx = (int) (ray.rx) >> 6;
		printf("horizontal=======================\nray mx:%d ray my: %d\n", ray.mx, ray.my);
//		printf("map in pos is %s\n", map->map[ray.my]);
		if (ray.my < 0 || ray.mx < 0 ||map->height <= ray.my || (int)ft_strlen(map->map[ray.my]) <= ray.mx)
		{
			//printf("first condition: %d second condition %d\n", map->height < ray.ry, map->width < ray.rx);
			ray.end = 2;
		}
		else if (map->map[ray.my][ray.mx] == '1') // have to add out of map control just in case
		{
			//printf("hit\n");
			ray.cx = ray.ry;
			ray.cy = ray.rx;
			ray.end = 1;
		}
		else
		{
			ray.ry += ray.yo;
			ray.rx += ray.xo;
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

	ntan = tan(ray->ra);
	printf("pi rads ra: %f\n", ray->ra / PI);
	printf("ntan: %f\n", ntan);
	if (ray->ra > P2 && ray->ra < P32) //looking left
	{
		ray->rx = (((int)p_pos->px >> 6) << 6) - 0.0001;
		ray->ry = (p_pos->px - ray->rx) * ntan + p_pos->py;
		printf("rx: %d ry: %d\n", (int)ray->rx>>6, (int)ray->ry>>6);
		printf("px - rx: %f, * ntan: %f, + py: %f\n", p_pos->px - ray->rx, (p_pos->px - ray->rx) * ntan, (p_pos->px - ray->rx) * ntan + p_pos->py);
		ray->xo = -64;
		ray->yo = ray->xo * -ntan;
		printf("xo: %f yo: %f\n", ray->xo, ray->yo);
	}
	if (ray->ra < P2 || ray->ra > P32) //looking right
	{
		ray->rx = (((int)p_pos->px >> 6) << 6) +64;
		ray->ry = (p_pos->px - ray->rx) * ntan + p_pos->py;
		ray->xo = 64;
		ray->yo = ray->xo * -ntan;
	}
	if (ray->ra == P2 || ray->ra == P32) //looking straight up or straight down
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

t_ray	check_v_colision(t_playerpos *p_pos, t_map *map, float ra)
{
	t_ray	ray;

	ray.ra = ra;
	ray.end = 0;
	v_offset_calc(p_pos, &ray);
	while (!ray.end)
	{
		//printf("vertical iteration %d\n", i++);
		//printf("player position x:%d y:%d\n", (int)(p_pos->px) >> 6, (int)(p_pos->py) >> 6);
		ray.my = (int) (ray.ry) >> 6;
		ray.mx = (int) (ray.rx) >> 6;
		printf("vertical========================\nray rx %f mx:%d ray ry %f my: %d\n",ray.rx, ray.mx,ray.ry, ray.my);
		if (map->height <= ray.my || (int)ft_strlen(map->map[ray.my]) <= ray.mx || ray.mx < 0 || ray.my < 0)
		{
//			printf("first condition: %d second condition %d\n", map->height < ray.ry, map->width < ray.rx);
			ray.end = 2;
		}
		else if (map->map[ray.my][ray.mx] == '1') // have to add out of map control just in case
		{
			//printf("hit\n");
			ray.cx = ray.ry;
			ray.cy = ray.rx;
			ray.end = 1;
		}
		else
		{
			ray.ry += ray.yo;
			ray.rx += ray.xo;
		}
	}
	if (ray.ra > P2 && ray.ra < P32)
		return (ray.tx = 'W', ray);
	else
		return (ray.tx = 'E', ray);
}


void	print_map(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	printf("   ");
	while (i < map->width)
		printf("%s|%s%03d",CY, BL, i++);
	printf("%s|\n", CY);
	i = 0;
	while (map->map[i])
	{
		k = 0;
		while (k < map->width * 3)
		{
			printf("%s__", CY);
			k++;
		}
		printf("\n");
		printf("%s%03d", BL, i);
		j = 0;
		while (map->map[i][j])
		{
			printf("%s|%s %c ", CY, WT, map->map[i][j++]);
		}
		printf("%s|\n%s", CY, WT);
		i++;
	}
}
/**
 * @brief casts the  rays and decide the texture that is needed for the column.
 * 
 * @param p_pos	playerposition structure
 * @param map	map structure
 * @param text	texture
 */

void	raycaster(t_playerpos *p_pos, t_all *all/*, t_mlx *mlx*/) //here we need to get the big structure as we will need it later to draw the line.
{
	t_ray	vc;
	t_ray	hc;
	float	ra;
	int		i;
	char	c;

	ra = p_pos->pa + (46 * DEG);
	i = 0;
	printf("playerpos: px = %f py = %f pa = %f\n", p_pos->px, p_pos->py, p_pos->pa);
	printf("ra in rads: %f\n", ra / PI);
	while (i < 90)
	{
		ra = fix_angle(ra - DEG);
		vc = check_v_colision(p_pos, &all->map, ra);
		hc = check_h_colision(p_pos, &all->map, ra);
		if (dist(&vc, p_pos) > dist(&hc, p_pos))
		{
			printf("horizontal %f vertical %f\n", hc.dist, vc.dist);
			//printf("horizontal\n");
			//take_texture(&hc, text);
			// printf("ray.mx: %d ray.my: %d\n", hc.mx, hc.my);
			// printf("dist: %f\n", hc.dist);
			//draw_column(&hc, all, mlx, i);
		}
		else
		{
			printf("horizontal %f vertical %f\n", hc.dist, vc.dist);
			//take_texture(&vc, text);
			//printf("vertical\n");
			// printf("dist: %f\n", vc.dist);
			// printf("ray.mx: %d ray.my: %d\n", hc.mx, hc.my);
			//draw_column(&vc, all, mlx, i);
		}
		print_map(&all->map);
		scanf("%c\n", &c);
		printf("%d\n", i);
		i++;
	}
	//mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
