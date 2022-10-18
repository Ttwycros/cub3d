/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:28:46 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:28:47 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	print_ident(char *ident, int i)
{
	if (ident[i] == 'S' && ident[i + 1] == 'O')
		ft_putstr_fd("\t\t\t\tSouth texture:", 1);
	else if (ident[i] == 'N' && ident[i + 1] == 'O')
		ft_putstr_fd("\t\t\t\tNorth texture:", 1);
	else if (ident[i] == 'W' && ident[i + 1] == 'E')
		ft_putstr_fd("\t\t\t\tWest texture:", 1);
	else if (ident[i] == 'E' && ident[i + 1] == 'A')
		ft_putstr_fd("\t\t\t\tEast texture:", 1);
	else if (ident[i] == 'F' && ident[i + 1] == ' ')
		ft_putstr_fd("\t\t\t\tFloor texture:", 1);
	else if (ident[i] == 'C' && ident[i + 1] == ' ')
		ft_putstr_fd("\t\t\t\tCell texture:", 1);
	else if (ident[i] == 'D' && ident[i + 1] == ' ')
		ft_putstr_fd("\t\t\t\tDoor texture:", 1);
	else
		ft_putstr_fd("\t\t\t\tSprite texture:", 1);
}
