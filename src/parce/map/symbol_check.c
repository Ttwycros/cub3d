/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:31:20 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:31:21 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	check_square_three(char **tmp, int k, int j, t_cub *cub)
{
	int	ok;

	ok = 1;
	while (--j > 0 && ok)
		if (!(tmp[j][k - 1] == '1' || \
		(tmp[j][k - 1] == ' ' && ft_strchr(" 1", tmp[j][k - 2]))))
			ok = 0;
	if (!(tmp[j][k - 1] == '1' || \
		(tmp[j][k - 1] == ' ' && ft_strchr(" 1", tmp[j][k - 2]))))
		ok = 0;
	while (--k > 0 && ok)
		if (!(tmp[j][k] == '1' || \
			(tmp[j][k] == ' ' && ft_strchr(" 1", tmp[j + 1][k]))))
			ok = 0;
	if (!(tmp[j][k] == '1' || \
		(tmp[j][k] == ' ' && ft_strchr(" 1", tmp[j + 1][k]))))
		ok = 0;
	return (ok);
}

static int	check_square_two(char **tmp, int k, int j, t_cub *cub)
{
	int	ok;

	ok = 1;
	while (++j < cub->map_y && ok)
		if (!(tmp[j][0] == '1' || \
			(tmp[j][0] == ' ' && ft_strchr(" 1", tmp[j][1]))))
			ok = 0;
	while (++k < cub->map_x && ok)
		if (!(tmp[j - 1][k] == '1' || \
		(tmp[j - 1][k] == ' ' && ft_strchr(" 1", tmp[j - 2][k]))))
		ok = 0;
	if (ok)
		ok = check_square_three(tmp, k, j, cub);
	return (ok);
}

void	check_square(char **tmp, t_cub *cub)
{
	int	k;
	int	j;
	int	ok;

	j = -1;
	k = -1;
	ok = check_square_two(tmp, k, j, cub);
	if (!ok)
		err_exit(9);
}

void	check_symbol(char **tmp, int j, int k, t_cub *cub)
{
	if (tmp[j][k] == ' ')
	{
		if (!(ft_strchr(" 1", tmp[j + 1][k])) ||
			!(ft_strchr(" 1", tmp[j - 1][k])) ||
			!(ft_strchr(" 1", tmp[j][k + 1])) ||
			!(ft_strchr(" 1", tmp[j][k - 1])))
			err_exit(9);
	}
	else if (!(ft_strchr("0123NSWE", tmp[j][k])))
		err_exit(10);
}
