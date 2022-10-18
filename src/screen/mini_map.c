/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:34:53 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:34:54 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_color(int clr1, int clr2)
{
	int	*c1;
	int	*c2;
	int	clr;

	c1 = int_to_rgb(clr1);
	c2 = int_to_rgb(clr2);
	c1 = clr_add(c1, c2);
	c1[0] /= 2;
	c1[1] /= 2;
	c1[2] /= 2;
	clr = rgb_to_int(c1[0], c1[1], c1[2]);
	return (clr);
}

static void	draw_sqaure(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	step_x;
	int	step_y;

	i = -1;
	step_x = cub->mini_map->step_x;
	step_y = cub->mini_map->step_y;
	while (++i <= cub->mini_map->pix)
	{
		j = -1;
		while (++j <= cub->mini_map->pix)
			cub->screen->data[(i + step_y) * cub->screen->width \
				+ (j + step_x)] = get_color(cub->screen->data[(i + step_y) * \
					cub->screen->width + (j + step_x)], color);
	}
}

static int	set_color(int x, int y, t_map *map, t_cub *cub)
{
	int	color;

	if (y == (int)cub->plr->pos_y && x == (int)cub->plr->pos_x \
			&& map->map[y][x] == 0)
		color = RED;
	else if (map->map[y][x] == 0)
		color = BLACK;
	else if (map->map[y][x] == 1)
		color = WHITE;
	else
		color = BLUE;
	return (color);
}

void	draw_map(t_cub *cub, t_map *map)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	map->step_y = 0;
	while (++y < cub->map_y)
	{
		x = -1;
		map->step_x = 0;
		while (++x < cub->map_x)
		{
			color = set_color(x, y, map, cub);
			draw_sqaure(cub, x, y, color);
			map->step_x += map->pix + 1;
		}
		map->step_y += map->pix + 1;
	}
}
