/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:09:26 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/04 13:35:42 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief Print all data received and parsed
 * 
 * @param all main struct with all structs
 */
static  void    print_struct(t_all *all)
{
    int i = 0;
    //print raw datta
    printf("\nRAW DATTA:\n");
    while (all->map.raw[i])
        printf("%s\n", all->map.raw[i++]);
    //print map
    i = 0;
    // while (all->map.map[i])
    //     printf("MAP:\n%s\n", all->map.map[i]);
    //print attributes of map
    printf("\nATTRIBUTES:\n");
    printf("North: %d\nSouth: %d\nEast: %d\nWest: %d\n",
        all->attrb.n, all->attrb.s, all->attrb.e, all->attrb.w);
    //print textures
    printf("\nTEXTURES:\n");
    printf("North: %s\nSouth: %s\nEast: %s\nWest: %s\nFloor: %s\n Ceiling: %s\n",
    all->texture.NO, all->texture.SO, all->texture.EA, all->texture.WE, all->texture.F, all->texture.C);
}

int main(int argc, char **argv)
{
    t_all       all;

    if (argc == 2)
    {
        ft_init_struct(&all, argv[1]);
        ft_start(&all.map, &all.texture);
        print_struct(&all);
    }
    else
        printf("TA MAL COÑO!\n");
}
