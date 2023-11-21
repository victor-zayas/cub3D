/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posible_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:57:14 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 21:00:19 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	p_m(t_all *all, int direction)
{
	float	new_x;
	float	new_y;

	if (direction == 2)
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa)));
		new_x = all->player.px + (MS * 10 * (cos(all->player.pa)));
	}
	else if (direction == 4)
	{
		new_y = all->player.py + (MF * 10 * (sin(all->player.pa)));
		new_x = all->player.px - (MF * 10 * (cos(all->player.pa)));
	}
	else if (direction == 3)
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa + P_2)));
		new_x = all->player.px + (MS * 10 * (cos(all->player.pa + P_2)));
	}
	else
	{
		new_y = all->player.py - (MS * 10 * (sin(all->player.pa - P_2)));
		new_x = all->player.px + (MS * 10 *(cos(all->player.pa - P_2)));
	}
	if (all->map.map[(int)(new_y) >> 6][(int)(new_x) >> 6] == '1')
		return (0);
	return (1);
}
