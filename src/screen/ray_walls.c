/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:35:11 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:35:12 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	perp_and_height(t_ray *ray, t_player *plr, t_cub *cub)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->map_x - plr->pos_x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - plr->pos_y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	ray->line_height = (int)(cub->height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + (cub->height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + (cub->height / 2);
	if (ray->draw_end >= cub->height)
		ray->draw_end = cub->height - 1;
}

static void	predict_wall_face(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == 1)
			ray->side = 0;
		else if (ray->step_x == -1)
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == 1)
			ray->side = 2;
		else if (ray->step_y == -1)
			ray->side = 3;
	}
}

void	hit(t_ray *ray, t_cub *cub)
{
	while (ray->hit == 0)
	{
		predict_wall_face(ray);
		if (cub->map[ray->map_y][ray->map_x] == 1)
			ray->hit = 1;
	}
}
