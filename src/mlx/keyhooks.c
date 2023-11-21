/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:30 by lagonzal          #+#    #+#             */
/*   Updated: 2023/11/21 15:10:39 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_close(void *all)
{
	t_all	*aux;

	aux = (t_all *)all;
	mlx_destroy_window(aux->mlx.mlx, aux->mlx.win);
	mlx_destroy_image(aux->mlx.mlx, aux->mlx.img);
	ft_free_img(aux);
	ft_doublefree(aux->map.map);
	exit(0);
}

char	movement_activation(char type, char direction)
{
	static char	move_status;
	static char	rot_status;
	static char active_m;
	static char active_r;
	// char c;
	// printf("enters in movement\n"); 
	// scanf("%c\n", &c);
	// char aux;

	if (type == 1)
	{
		if (direction != 5 && (!active_m || direction == 0))
		{
			move_status = direction;
			printf("move status changed %d\n", direction);
		//scanf("%c\n", &aux);
		}
		if (move_status)
		{
			active_m = 1;
			printf("move status set to active\n");
//			scanf("%c\n", &aux);
		}
		else
			active_m = 0;
		return (move_status);
	}
	else
	{
		if (direction != 3)
		{
			rot_status = direction;
			printf("rot status changed\n");
		//	scanf("%c\n", &active_r);
		}
		if (rot_status)
		{
			active_r = 1;
			printf("rot set as active\n");
		//	scanf("%c\n", &aux);
		}
		return (rot_status);
	}
}

void	keyrelease(int keycode, t_all *all)
{
	// char c;
	// printf("enters in keyrelease\n"); 
	// scanf("%c\n", &c);
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
	// char c;
	// printf("enters in keypress\n"); 
	// scanf("%c\n", &c);
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
	if (movement_activation(1, 5) == 2)
	{
		all->player.py -= MF * (sin(all->player.pa));
		all->player.px += MF * (cos(all->player.pa));
	}
	else if (movement_activation(1, 5) == 4)
	{
		all->player.py += MF * (sin(all->player.pa));
		all->player.px -= MF * (cos(all->player.pa));
	}
	else if (movement_activation(1, 5) == 3)
	{
		all->player.py -= MS * (sin(all->player.pa + P_2));
		all->player.px += MS * (cos(all->player.pa + P_2));
	}
	else if (movement_activation(1, 5) == 1)
	{
		all->player.py -= MS * (sin(all->player.pa - P_2));
		all->player.px += MS * (cos(all->player.pa - P_2));
	}
}

void move_manage(t_all *all)
{
	mlx_hook(all->mlx.win, 17, 1L << 17, (void *)ft_close, (void *) all);
	mlx_hook(all->mlx.win, 2, 1L << 0, (void *) &keypress, all);
	move(all);
	mlx_hook(all->mlx.win, 3, 1L << 1, (void *) &keyrelease, all);
	raycaster(all);
}

