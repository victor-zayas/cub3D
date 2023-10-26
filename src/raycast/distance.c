/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:11:34 by larra             #+#    #+#             */
/*   Updated: 2023/10/26 14:39:04 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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
	if (ray->end == 1)
		ray->dist = sqrt(pow(ray->cx - p_pos->px, 2)
		+ pow(ray->cy - p_pos->py, 2));
	if (ray->end == 2)
		ray->dist = 1e30;
	return (ray->dist);
}

float	fix_angle(float	angle)
{
	if (angle >= 2 * PI)
		return (angle - 2 * PI);
	else if (angle < 0)
		return (angle + 2 * PI);
	return (angle);
}
