/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:52:30 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/12/05 11:51:15 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lenstr(const char *str, char c)
{
	int	count;

	count = -1;
	while (str[++count] != '\0')
	{
		if (str[count] == c)
			return (count);
	}
	return (count);
}

char	*ft_substr_gnl(char *str, int start, int len)
{
	char	*s;
	int		i;
	int		j;

	if (!ft_strchr(str, '\n'))
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc((len - start + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (i < len)
		s[j++] = str[i++];
	s[j] = '\0';
	free (str);
	return (s);
}

char	*ft_strjoin_gnl(char *str, char *tmp)
{
	char	*s;
	int		i;
	int		j;

	if (!str)
	{
		str = malloc(1);
		*str = '\0';
	}
	s = (char *)malloc(ft_lenstr(str, 0) + ft_lenstr(tmp, 0) + 1);
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	while (tmp[j])
		s[i++] = tmp[j++];
	free (str);
	s[i] = '\0';
	return (s);
}

char	*ft_joinline(char *str)
{
	char	*s;
	int		i;
	int		j;

	j = ft_lenstr(str, '\n');
	if (!str)
		return (NULL);
	s = (char *)malloc(j + 2);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < j + 1)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}
