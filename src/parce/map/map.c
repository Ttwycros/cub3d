/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:30:40 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:30:41 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	symbol_int_map(char ch, int x, int y, t_cub *cub)
{
	if (ch >= '0' && ch <= '3')
	{
		cub->mini_map->map[y][x] = ch - '0';
		if (ch == '2')
			cub->sprites_num++;
	}
	else if (ch == ' ')
		cub->mini_map->map[y][x] = 0;
	else if (ft_strchr("NSWE", ch))
		cub->mini_map->map[y][x] = 0;
}

static void	symbol_int(char ch, int x, int y, t_cub *cub)
{
	if (ch >= '0' && ch <= '3')
		cub->map[y][x] = ch - '0';
	else if (ch == ' ')
		cub->map[y][x] = 1;
	else if (ft_strchr("NSWE", ch))
		cub->map[y][x] = 0;
}

static void	fill_mini_map(char **map, t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	cub->mini_map->map = ft_calloc(cub->map_y + 1, sizeof(int *));
	if (!cub->mini_map->map)
		err_exit(2);
	while (map[++y])
	{
		x = -1;
		cub->mini_map->map[y] = ft_calloc(cub->map_x + 1, sizeof(int));
		if (!cub->mini_map->map[y])
			err_exit(2);
		while (map[y][++x])
			symbol_int_map(map[y][x], x, y, cub);
	}
}

static void	char_to_int_map(char **map, t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	fill_mini_map(map, cub);
	init_game_sprite(cub);
	init_doors(map, cub);
	cub->map = ft_calloc(cub->map_y + 1, sizeof(int *));
	if (!cub->map)
		err_exit(2);
	while (map[++y])
	{
		x = -1;
		cub->map[y] = ft_calloc(cub->map_x + 1, sizeof(int));
		if (!cub->map[y])
			err_exit(2);
		while (map[y][++x])
			symbol_int(map[y][x], x, y, cub);
		save_free(&map[y]);
	}
}

void	parce_map(t_list **file, t_cub *cub)
{
	char	**tmp_map;
	int		k;
	int		j;
	int		plr;

	j = 0;
	plr = -1;
	tmp_map = file_into_map(*file, cub);
	check_square(tmp_map, cub);
	while (++j < cub->map_y - 1)
	{
		k = 0;
		while (++k < cub->map_x - 1)
		{
			check_symbol(tmp_map, j, k, cub);
			if (ft_strchr("NSWE", tmp_map[j][k]))
			{
				set_dir(tmp_map[j][k], k, j, cub);
				plr++;
			}
		}
	}
	if (plr != 0)
		err_exit(11);
	char_to_int_map(tmp_map, cub);
}
