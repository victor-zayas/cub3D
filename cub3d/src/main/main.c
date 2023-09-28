/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/28 20:02:43 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

int main(int argc, char **argv)
{
    int         i;
    t_map       map;
    t_texture   texture;

    if (argc == 2)
    {
        ft_init_map(&map, argv[1]);
        ft_split_args(&map, &texture);
        // printf("HOLA!\n");
        i = -1;
        while (map.map[++i])
            printf("%s\n", map.map[i]);
    }
    else
        printf("TA MAL COÑO!\n");
}
