/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   parce_map.c                              cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/08/01 15:03:59  /  2021/08/01 15:04:22 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	get_map_sizes(char *str, uint *x, uint *y)
{
	uint cx;

	while (*str)
	{
		cx = 0;
		while (*str != '\n')
		{
			str++;
			cx++;
		}
		if (cx > *x)
			*x = cx;
		*y = *y + 1;
		str++;
	}
	return (OK);
}

char	**alloc_map(uint x, uint y)
{
	char	**map;
	uint	tmp;

	map = (char **)malloc(sizeof(char *) * y);
	if (!map)
		return (NULL);
	*map = (char *)malloc(sizeof(char *) * y * x);
	if (!*map)
		return (NULL);
	tmp = 1;
	while (tmp < y)
		map[tmp] = *map + x * tmp++;
	tmp = 0;
	while (tmp < y * x)
		map[0][tmp++] = ' ';
	return (map);
}

void	writetomap(char **map, char *str, uint x, uint y)
{
	char	*ptr;
	uint	i;
	uint	d;

	ptr = *map;
	d = 0;
	while (d < y)
	{
		i = 0;
		while (i < x)
		{
			if (*str != '\n')
			{
				*ptr = *str;
				*str++;
			}
			i++;
			*ptr++;
		}
		d++;
		if (*str != '\0')
			str++;
	}
}

int	parce_map(t_cub *cub)
{
	get_map_sizes(cub->ptr, &cub->map_x, &cub->map_y);
	cub->map = alloc_map(cub->map_x, cub->map_y);
	if (!cub->map)
		return (ERROR);
	writetomap(cub->map, cub->ptr, cub->map_x, cub->map_y);
	//if (is_not_valid_map(cub, cub->map, cub->map_x, cub->map_y))
	//	return (ERROR);
	return (OK);
}
