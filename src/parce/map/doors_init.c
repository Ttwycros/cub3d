/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:30:21 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:30:22 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	doors_num(char **map)
{
	int	num;
	int	i;
	int	j;

	num = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '3')
				num++;
		}
	}
	return (num);
}

void	init_doors(char **map, t_cub *cub)
{
	int	num;
	int	k;
	int	j;
	int	i;

	num = doors_num(map);
	cub->doors = ft_calloc(num + 1, sizeof(t_door));
	if (!cub->doors)
		err_exit(2);
	i = 0;
	k = -1;
	while (++k < cub->map_y)
	{
		j = -1;
		while (++j < cub->map_x)
		{
			if (map[k][j] == '3')
			{
				cub->doors[i].x = j;
				cub->doors[i].y = k;
				cub->doors[i].close = 0;
				i++;
			}
		}
	}
}
