/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/22 14:53:26 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/**
 * @brief load all functions of program
 * 
 * @param map 
 * @param texture 
 */
void	ft_parse(t_all *all)
{
	ft_check_extension(all->map.name);
	ft_read_map(&all->map);
	ft_get_data(&all->map);
	ft_check_order(&all->map);
	ft_get_map(&all->map, &all->attrb);
	ft_get_texture(&all->map, &all->texture);
	ft_get_color(&all->map, &all->texture);
	ft_doublefree(all->map.raw);
}

int	main(int argc, char **argv)
{
	t_all		all;
	int			txt_size;

	txt_size = 64;
	if (argc == 2)
	{
		ft_init_struct(&all, argv[1]);
		ft_parse(&all);
		get_mlx(&all.mlx);
		ft_get_img(&all, &txt_size);
		search_playerpos(all.map.map, &all.player);
		raycaster(&all);
		mlx_loop_hook(all.mlx.mlx, (void *) &move_manage, &all);
		mlx_loop(all.mlx.mlx);
	}
	else
		printf("Error\nExpected two arguments, have %d\n", argc);
}
