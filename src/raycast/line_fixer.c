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

#include "../../includes/cub3D.h"

void	fix_fisheye(t_ray *ray)
{
	if ((ray->ra > P_4 && ray->ra < P3_4) || (ray->ra > P5_4 && ray->ra < P7_4))
		ray->dist = sin(ray->ra) * ray->dist;
	else
	ray->dist = cos(ray->ra) * ray->dist;
	ray->dist = absolute(ray->dist);
}
