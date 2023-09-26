
#include"../includes/cub3D.h"

void    ft_init_map(t_map **map)
{
    *map = malloc(sizeof(t_map));
    if (*map == NULL)
        return ;
    (*map)->name = NULL;
    (*map)->fd = -1;
}

void	ft_init_attrb(t_attrb *attrb)
{
	attrb->n = 0;
	attrb->s = 0;
	attrb->e = 0;
	attrb->w = 0;
}
