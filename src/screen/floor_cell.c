/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:13:28 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 18:13:37 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	tex_floor(t_cub *cub, t_ray *ray, t_line *line)
{
	double	weight;
	double	current_floor_x;
	double	current_floor_y;

	weight = cub->height / (2.0 * line->y - cub->height) / ray->perp_wall_dist;
	current_floor_x = \
		weight * ray->floor_x_wall + (1.0 - weight) * cub->plr->pos_x;
	current_floor_y = \
		weight * ray->floor_y_wall + (1.0 - weight) * cub->plr->pos_y;
	line->tex_x = (int)(current_floor_x * cub->texture[5]->width)
		% cub->texture[5]->width;
	line->tex_y = (int)(current_floor_y * cub->texture[5]->height)
		% cub->texture[5]->height;
	cub->screen->data[line->y * cub->screen->width + line->x] = \
		cub->texture[5]->data[cub->texture[5]->width * line->tex_y
		+ line->tex_x];
}

static void	tex_cell(t_cub *cub, t_ray *ray, t_line *line)
{
	double	weight;
	double	current_floor_x;
	double	current_floor_y;

	weight = cub->height / (2.0 * line->y - cub->height) / ray->perp_wall_dist;
	current_floor_x = \
		weight * ray->floor_x_wall + (1.0 - weight) * cub->plr->pos_x;
	current_floor_y = \
		weight * ray->floor_y_wall + (1.0 - weight) * cub->plr->pos_y;
	line->tex_x = (int)(current_floor_x * cub->texture[6]->width)
		% cub->texture[6]->width;
	line->tex_y = (int)(current_floor_y * cub->texture[6]->height)
		% cub->texture[6]->height;
	cub->screen->data[(cub->height - line->y) * cub->screen->width + line->x]
		= cub->texture[6]->data[cub->texture[6]->width * line->tex_y
		+ line->tex_x];
}

void	ver_floor_and_cell(t_line *line, t_cub *cub, t_ray *ray)
{
	line->y = ray->draw_end + 1;
	while (line->y < cub->height)
	{
		tex_floor(cub, ray, line);
		tex_cell(cub, ray, line);
		line->y++;
	}
}
