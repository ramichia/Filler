/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:28:26 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:21:53 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		**malloc_corner(int **tab)
{
	int		i;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * 8);
	while (i < 8)
	{
		tab[i] = (int*)malloc(sizeof(int) * 2);
		i++;
	}
	return (tab);
}

int		fill_data(t_filler *data)
{
	data->c = read_player(data);
	if (data->c == 'A')
		return (0);
	data->opponent = opponent_sign(data->c);
	data->round = 0;
	data->corner = malloc_corner(data->corner);
	return (1);
}

int		main(void)
{
	t_filler	data;

	if (fill_data(&data) == 0)
		return (0);
	while (1)
	{
		size_map(&data);
		if (data.size_map == 0)
			return (0);
		data.map = read_map(&data);
		data.piece = read_piece(&data);
		if (data.piece == NULL)
			return (0);
		data.piece_row = piece_row(&data, 0);
		data.piece_column = piece_column(&data, 0, 0);
		find_piece(&data);
		set_target(&data);
		set_diff(&data);
		choose_target(&data);
		if (data.to_print[0] < -5 || data.to_print[1] < -5)
			break ;
		ft_printf("%d %d\n", data.to_print[0], data.to_print[1]);
		clean(&data);
	}
	return (0);
}
