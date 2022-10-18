/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 23:31:17 by sherbert          #+#    #+#             */
/*   Updated: 2022/10/18 18:07:05 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_char(t_list *lst, void (*del)(char**))
{
	if (lst)
	{
		if (del && lst->content)
			del((void *)&(lst->content));
		free(lst);
	}
}
