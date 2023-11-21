/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:49:02 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 13:54:33 by lagonzal         ###   ########.fr       */
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
	printf("check %s\n", texture->NO);
	if (ft_strrchr(texture->NO, ' ') || ft_strrchr(texture->SO, ' ')
		|| ft_strrchr(texture->EA, ' ') || ft_strrchr(texture->WE, ' '))
	{
		printf("Error\nInvalid texture path\n");
		exit(1);
	}
	ft_check_ext_texture(texture->NO);
	ft_check_ext_texture(texture->SO);
	ft_check_ext_texture(texture->EA);
	ft_check_ext_texture(texture->WE);
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
	printf("check %s\n", str);
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ','))
		{
			printf("Error\nInvalid char in RGB: %c\n", str[i]);
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
int	*ft_check_color(char *str)
{
	char	**rgb;
	int		*num;
	int		i;
	int		j;

	ft_digit(str);
	rgb = ft_split(str, ',');
	num = malloc(sizeof(int) * 3);
	i = -1;
	j = 0;
	while (rgb[++i] && j < 3)
	{
		num[j] = ft_atoi(rgb[i]);
		if (num[j] < 0 || num[j] > 255)
		{
			printf("Error\nRGB value exceed: %d\n", num[j]);
			exit(1);
		}
		j++;
	}
	if (i != 3)
		ft_exit("Missing value in RGB code");
	free(str);
	ft_doublefree(rgb);
	return (num);
}
