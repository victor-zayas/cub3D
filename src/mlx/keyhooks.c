/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:30 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/21 20:29:18 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	movement_activation(char type, char direction)
{
	static char	move_status;
	static char	rot_status;
	static char	active_m;
	static char	active_r;

	if (type == 1)
	{
		if (direction != 5 && (!active_m || direction == 0))
			move_status = direction;
		if (move_status)
			active_m = 1;
		else
			active_m = 0;
		return (move_status);
	}
	else
	{
		if (direction != 3)
			rot_status = direction;
		if (rot_status)
			active_r = 1;
		return (rot_status);
	}
}

void	keyrelease(int keycode, t_all *all)
{
	all = (t_all *)all;
	if (keycode == RA)
		movement_activation(2, 0);
	else if (keycode == LA)
		movement_activation(2, 0);
	else if (keycode == W)
		movement_activation(1, 0);
	else if (keycode == S)
		movement_activation(1, 0);
	else if (keycode == A)
		movement_activation(1, 0);
	else if (keycode == D)
		movement_activation(1, 0);
	else if (keycode == ESC)
		ft_close(all);
}

void	keypress(int keycode, t_all *all)
{
	all = (t_all *)all;
	if (keycode == RA)
		movement_activation(2, 1);
	else if (keycode == LA)
		movement_activation(2, 2);
	else if (keycode == W)
		movement_activation(1, 2);
	else if (keycode == S)
		movement_activation(1, 4);
	else if (keycode == A)
		movement_activation(1, 3);
	else if (keycode == D)
		movement_activation(1, 1);
}

void	move(t_all *all)
{
	if (movement_activation(2, 3) == 1)
		all->player.pa -= RS;
	else if (movement_activation(2, 3) == 2)
		all->player.pa += RS;
	if (movement_activation(1, 5) == 2 && p_m(all, 2))
	{
		all->player.py -= MF * (sin(all->player.pa));
		all->player.px += MF * (cos(all->player.pa));
	}
	else if (movement_activation(1, 5) == 4 && p_m(all, 4))
	{
		all->player.py += MF * (sin(all->player.pa));
		all->player.px -= MF * (cos(all->player.pa));
	}
	else if (movement_activation(1, 5) == 3 && p_m(all, 3))
	{
		all->player.py -= MS * (sin(all->player.pa + P_2));
		all->player.px += MS * (cos(all->player.pa + P_2));
	}
	else if (movement_activation(1, 5) == 1 && p_m(all, 1))
	{
		all->player.py -= MS * (sin(all->player.pa - P_2));
		all->player.px += MS * (cos(all->player.pa - P_2));
	}
}

void	move_manage(t_all *all)
{
	mlx_hook(all->mlx.win, 17, 1L << 17, (void *)ft_close, (void *) all);
	mlx_hook(all->mlx.win, 2, 1L << 0, (void *) &keypress, all);
	move(all);
	mlx_hook(all->mlx.win, 3, 1L << 1, (void *) &keyrelease, all);
	raycaster(all);
}
