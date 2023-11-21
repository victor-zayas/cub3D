/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:49:02 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/11/21 16:21:52 by vzayas-s         ###   ########.fr       */
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
	printf("check %s\n", texture->no);
	if (ft_strrchr(texture->no, ' ') || ft_strrchr(texture->so, ' ')
		|| ft_strrchr(texture->ea, ' ') || ft_strrchr(texture->we, ' '))
	{
		printf("Error\nInvalid texture path\n");
		exit(1);
	}
	ft_check_ext_texture(texture->no);
	ft_check_ext_texture(texture->so);
	ft_check_ext_texture(texture->ea);
	ft_check_ext_texture(texture->we);
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
