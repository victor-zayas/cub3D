/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:49:02 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/10/12 10:10:24 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3D.h"

/**
 * @brief check if the path in textures is correct
 * 
 * @param texture 
 */
void	ft_check_texture(t_texture *texture)
{
	if (ft_strrchr(texture->NO, ' ') || ft_strrchr(texture->SO, ' ')
		|| ft_strrchr(texture->EA, ' ') || ft_strrchr(texture->WE, ' '))
	{
		printf("Error: invalid texture path\n");
		exit(1);
	}
}

/**
 * @brief check of the characters in the string are digits
 * 
 * @param str string received
 */
static	void	ft_digit(char *str)
{
	int	i;

	i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ','))
        {
            printf("Error: invalid char in RGB\n");
            exit(1);
        }
        i++;
    }
}

/**
 * @brief check if the colors of map are valid and don't exceed RGB values
 * 
 * @param str string received with rgb content
 */
void	ft_check_color(char *str)
{
	char	**rgb;
	int		num;
    int		i;
	
	ft_digit(str);
    rgb = ft_split(str, ',');
	i = -1;
    while (rgb[++i])
    {
        num = ft_atoi(rgb[i]);
        if (num < 0 || num > 255)
        {
            printf("Error: rgb value exceed\n");
            exit(1);
        }
    }
    if (i != 3)
    {
        printf("Error: missing value in RGB code\n");
        exit(1);
    }
    free(rgb);
}
