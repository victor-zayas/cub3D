/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_fixer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:45:40 by lagonzal          #+#    #+#             */
/*   Updated: 2023/10/25 18:45:40 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"

void	fix_fisheye(t_ray *ray, t_playerpos *p_pos)
{
	float	cos_a;

	cos_a = p_pos->pa - ray->ra;
	cos_a = fix_angle(cos_a);
	ray->dist = cos(cos_a) * ray->dist;
}