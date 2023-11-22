/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:26 by vzayas-s          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/22 12:21:17 by lagonzal         ###   ########.fr       */
=======
/*   Updated: 2023/11/21 19:49:08 by vzayas-s         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
 
/**
 * @brief Print all data received and parsed
 * 
 * @param all main struct with all structs
 */
// static	void	print_struct(t_all *all)
// {
// 	int	i;
// 	//print raw datta
// 	// i = 0;
// 	// printf("\nRAW DATTA:\n");
// 	// while (all->map.raw[i])
// 	//     printf("%s\n", all->map.raw[i++]);

// 	//print map
// 	i = 0;
// 	printf("\nMAP:\n");
// 	while (all->map.map[i])
// 		printf("%s\n", all->map.map[i++]);
// 	printf("\nHeight: %d\nWidth: %d\n", all->map.height, all->map.width);

// 	//print attributes of map
// 	printf("\nATTRIBUTES:\n");
// 	printf("North: %d\nSouth: %d\nEast: %d\nWest: %d\n",
// 		all->attrb.n, all->attrb.s, all->attrb.e, all->attrb.w);

// 	//print textures
// 	printf("\nTEXTURES:\n");
// 	printf("North: %s\nSouth: %s\nEast: %s\nWest: %s\n",
// 		all->texture.no, all->texture.so, all->texture.ea, all->texture.we);
// 	printf("Ceiling: %d\n", all->texture.c);
// 	printf("Floor: %d\n\n", all->texture.f);
// }

int	main(int argc, char **argv)
{
	t_all		all;
	int			txt_size;

	txt_size = 64;
	if (argc == 2)
	{
		if (pthread_mutex_init(&all.mut, NULL) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		ft_init_struct(&all, argv[1]);
		ft_parse(&all);
		//print_struct(&all);
		get_mlx(&all.mlx);
		ft_get_img(&all, &txt_size);
		search_playerpos(all.map.map, &all.player);
		pthread_create(&all.thread, NULL, (void *)&color_evo, (void * ) &all);
		raycaster(&all);
		mlx_loop_hook(all.mlx.mlx, (void *) &move_manage, &all);
		mlx_loop(all.mlx.mlx);
	}
	else
		printf("Error\nExpected two arguments, have %d\n", argc);
}
