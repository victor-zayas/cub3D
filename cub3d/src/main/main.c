/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/09/29 13:25:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

int main(int argc, char **argv)
{
    int         i;
    t_all       all;
    // t_map       map;
    // t_attrb     attrb;
    // t_texture   texture;

    if (argc == 2)
    {
        ft_init_struct(&all, argv[1]);
        ft_start(&all.map, &all.texture);
        i = -1;
        while (all.map.raw[++i])
            printf("%s\n", all.map.raw[i]);
    }
    else
        printf("TA MAL COÑO!\n");
}
