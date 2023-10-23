/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:11:34 by larra             #+#    #+#             */
/*   Updated: 2023/10/23 20:24:07 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/raycast.h"

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

float	dist(float rx, float ry, t_playerpos *p_pos, int end)
{
	if (end == 1)
		return(pow(rx - p_pos->px, 2) + pow(ry - p_pos->py, 2));
	if (end == 2)
		return (4000000000);
}

float	fix_angle(float	angle)
{
	if (angle >= 2 * PI)
		return (angle - 2 * PI);
	else if (angle < 0)
		return (angle + 2 * PI);
}
