/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:32:39 by ameteori          #+#    #+#             */
/*   Updated: 2022/10/18 17:32:40 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	file_parce(int argc, char **argv, t_cub *cub)
{
	t_list	*file;
	char	*line;
	int		fd;

	ft_putstr_fd("\tChecking input...", 1);
	valid_input(argc, argv, cub);
	line = NULL;
	file = NULL;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		err_exit(1);
	ft_putendl_fd("\t\t\t\t\tOK", 1);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&file, ft_lstnew(line));
	ft_lstadd_back(&file, ft_lstnew(line));
	ft_putendl_fd("\tChecking file...", 1);
	ft_putendl_fd("\tIdentifiers:", 1);
	parce_ident(&file, cub);
	ft_putstr_fd("Map:", 1);
	parce_map(&file, cub);
	ft_putendl_fd("\t\t\t\t\t\t\tOK", 1);
}
