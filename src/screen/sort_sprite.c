/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:36:40 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:36:41 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	sprite_value(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->sprites_num)
		cub->sprite_order[i].distance = ((cub->plr->pos_x
					- cub->sprite_order[i].x) * (cub->plr->pos_x
					- cub->sprite_order[i].x)
				+ (cub->plr->pos_y - cub->sprite_order[i].y)
				* (cub->plr->pos_y - cub->sprite_order[i].y));
}

static int	get_i_min(t_sprite *sprites, int num)
{
	int	min;
	int	i;
	int	min_i;

	i = -1;
	min = 2147483647;
	while (++i < num)
	{
		if (min > sprites[i].distance)
		{
			min_i = i;
			min = sprites[i].distance;
		}
	}
	return (min_i);
}

t_sprite	*sort_sprites(t_sprite *sprites, t_cub *cub)
{
	t_sprite	*new;
	int			i;
	int			j;

	i = -1;
	new = ft_calloc(cub->sprites_num + 1, sizeof(t_sprite));
	if (!new)
		return (NULL);
	while (++i < cub->sprites_num)
	{
		j = get_i_min(sprites, cub->sprites_num);
		new[i].x = sprites[j].x;
		new[i].y = sprites[j].y;
		new[i].distance = sprites[j].distance;
		sprites[j].distance = 2147483647;
	}
	return (new);
}
