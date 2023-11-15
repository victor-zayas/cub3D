/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/15 17:26:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief Print all data received and parsed
 * 
 * @param all main struct with all structs
 */
static	void	print_struct(t_all *all)
{
	int	i;
	//print raw datta
	// i = 0;
	// printf("\nRAW DATTA:\n");
	// while (all->map.raw[i])
	//     printf("%s\n", all->map.raw[i++]);
	
	//print map
	i = 0;
	printf("\nMAP:\n");
	while (all->map.map[i])
		printf("%s\n", all->map.map[i++]);
	printf("\nHeight: %d\nWidth: %d\n", all->map.height, all->map.width);
	
	//print attributes of map
	printf("\nATTRIBUTES:\n");
	printf("North: %d\nSouth: %d\nEast: %d\nWest: %d\n",
		all->attrb.n, all->attrb.s, all->attrb.e, all->attrb.w);
	
	//print textures
	printf("\nTEXTURES:\n");
	printf("North: %s\nSouth: %s\nEast: %s\nWest: %s\n",
	all->texture.NO, all->texture.SO, all->texture.EA, all->texture.WE);
	printf("Ceiling: %d\n", all->texture.C);
	printf("Floor: %d\n\n", all->texture.F);
}

int	main(int argc, char **argv)
{
	t_all		all;

	if (argc == 2)
	{
		ft_init_struct(&all, argv[1]);
		ft_parse(&all);
		print_struct(&all);
		get_mlx(&all.mlx);
		ft_get_img(&all);
		search_playerpos(all.map.map, &all.player);
		raycaster(&all);
		//mlx_hook(&all.mlx.win, 17, 1L << 17, NULL, NULL); //este es para el manejo del cierre y hay que gestionar el liberar la memoria de la mlx aquí
		//move(&all);
		mlx_loop_hook(all.mlx.mlx, (void *) &move_manage, &all); //
		//mlx_loop_hook(all.mlx.mlx, (void *) &raycaster, &all);
		mlx_loop(all.mlx.mlx);
	}
	else
		printf("Error\nExpected two arguments, have %d\n", argc);
}
