/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:11:34 by larra             #+#    #+#             */
/*   Updated: 2023/11/06 20:37:21 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief 
 * 
 * @param rx	rays collision x coordinate
 * @param ry	rays collision y coordinate
 * @param p_pos	player position structure
 * @param end	how the collision search ended
 * @return	float distance calculated via pithagorean theorem / no collision
 * 			high number
 */

float	dist(t_ray *ray, t_playerpos *p_pos)
{
	// printf("cx: %f cy: %f\n", ray->cx, ray->cy);
	// printf("px: %f py: %f\n", p_pos->px, p_pos->py);
	// printf("dist: (%f - %f) * (%f - %f) + (%f - %f) * (%f - %f)\n", ray->cx, p_pos->px, ray->cx, p_pos->px, ray->cy, p_pos->py, ray->cy, p_pos->py);
	// printf("%f + %f\n", (ray->cx - p_pos->px) * (ray->cx - p_pos->px), (ray->cy - p_pos->py) * (ray->cy - p_pos->py));
	// printf("sqrt %f\n", ((ray->cx - p_pos->px) * (ray->cx - p_pos->px) +
	// 		(ray->cy - p_pos->py) * (ray->cy - p_pos->py)));
	// printf("final %f\n", sqrt((double)((ray->cx - p_pos->px) * (ray->cx - p_pos->px) +
	// 		(ray->cy - p_pos->py) * (ray->cy - p_pos->py))));
	if (ray->end == 1)
		ray->dist = (float)sqrt((double)((ray->cx - p_pos->px) * (ray->cx - p_pos->px) +
			(ray->cy - p_pos->py) * (ray->cy - p_pos->py)));
	if (ray->end == 2)
		ray->dist = 1e30;
	return (ray->dist);
}

float	fix_angle(float	angle)
{
	if (angle >= P2)
		return (angle - P2);
	else if (angle < 0)
		return (angle + P2);
	return (angle);
}

float absolute(float in)
{
	if (in < 0)
		return (-in);
	return (in);
}
