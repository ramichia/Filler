/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:14:35 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:21:49 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	clean_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void	clean(t_filler *data)
{
	int		i;

	data->contact = check_contact(data->map, data->c, data->opponent);
	i = 0;
	while (i < 10000)
	{
		data->possibilities[i].result[0] = -10;
		data->possibilities[i].result[1] = -10;
		i++;
	}
	data->round++;
	clean_tab(data->piece);
	clean_tab(data->map);
}
