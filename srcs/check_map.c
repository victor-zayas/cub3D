
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
	while ((rd = read(fd, &c, 1)) >= 0)
    {
        if (rd == 0)
        {
            i = 1;
            break;
        }
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

static void ft_check_attrb(t_map *map, t_attrb *attrb)
{
	int		x;
	int		y;

	x = -1;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == 'N')
				attrb->n++;
			if (map->map[x][y] == 'S')
				attrb->s++;
			if (map->map[x][y] == 'E')
				attrb->e++;
			if (map->map[x][y] == 'W')
				attrb->w++;
		}
	}
}

void	ft_check_init_poss(t_map *map, t_attrb *attrb)
{
	ft_check_attrb(map, attrb);
	if (!(attrb->n || attrb->s || attrb->e || attrb->w))
	{
		printf("no starting position\n");
		exit(1);
	}
	else
	{
		if (attrb->n && (attrb->s || attrb->e || attrb->w))
			printf("there is more than one starting possition\n");
		if (attrb->s && (attrb->n || attrb->e || attrb->w))
			printf("there is more than one starting possition\n");
		if (attrb->e && (attrb->s || attrb->n || attrb->w))
			printf("there is more than one starting possition\n");
		if (attrb->w && (attrb->s || attrb->e || attrb->n))
			printf("there is more than one starting possition\n");
	}
}