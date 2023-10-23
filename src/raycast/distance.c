/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larra <larra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:11:34 by larra             #+#    #+#             */
/*   Updated: 2023/10/21 20:43:10 by larra            ###   ########.fr       */
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
