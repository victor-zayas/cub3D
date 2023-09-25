
#include"../includes/cub3D.h"

int ft_get_map(char *path)
{
	int		rd;
	int		fd;
	int		i;
	char	c;

    i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0 || fd == 2)
		return (0);
	rd = 1;
	while ((rd = read(fd, &c, 1)))
	{
		if (rd < 0)
			return (0);
        i++;
	}
	close(fd);
    return (i);
}

char	**ft_split_map(t_map *map)
{
	char	*aux;
	int		i;

	i = 0;
	aux = malloc(sizeof(char) * ft_get_map(map->name));
	read(map->fd, aux, ft_get_map(map->name));
	aux[ft_get_map(map->name) - 1] = '\0';
	while (aux[i])
	{
		if (aux[i] == '\n')
		{
			if (aux[i + 1] && aux[i + 1] == '\n')
			{
				printf("Error: emptyline in map\n");
				exit(1);
			}
		}
		i++;
	}
	map->map = ft_split(aux, '\n');
	close(map->fd);
	return (free(aux), map->map);
}

/* int ft_check_format(char **argv)
{} */
