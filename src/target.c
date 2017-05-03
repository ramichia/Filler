/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:56:10 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:22:11 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	set_diff(t_filler *data)
{
	int		i;

	i = 0;
	while (0 <= data->possibilities[i].result[0])
	{
		data->possibilities[i].diff = \
			absolute_value(data->possibilities[i].result[0] - data->target[0]) +
			absolute_value(data->possibilities[i].result[1] - data->target[1]);
		i++;
	}
}

void	fill_solutions(int i, int j, t_solutions *possible)
{
	possible->result[0] = (i - 1);
	possible->result[1] = (j - 4);
}

void	find_piece(t_filler *data)
{
	int		i;
	int		j;
	int		result;
	int		tab;

	i = 1;
	tab = 0;
	while (data->map[i + data->piece_row])
	{
		j = 4;
		while (data->map[i][j + data->piece_column])
		{
			result = place_piece(data, i, j);
			if (result == 1)
			{
				fill_solutions(i, j, &data->possibilities[tab]);
				tab++;
			}
			j++;
		}
		i++;
	}
	fill_solutions(0, 0, &data->possibilities[tab]);
}

void	target_average(t_filler *data)
{
	int		i;
	int		j;

	shape_opponent(data);
	j = data->right_opponent[1] - data->back_opponent[1];
	i = data->down_opponent[0] - data->up_opponent[0];
	data->target[1] = data->back_opponent[1] + j;
	data->target[0] = data->up_opponent[0] + i;
}

void	choose_target(t_filler *data)
{
	int		i;
	int		tmp;
	int		index;

	tmp = 1000;
	i = 0;
	while (0 <= data->possibilities[i].result[0])
	{
		if (data->possibilities[i].diff < tmp)
		{
			tmp = data->possibilities[i].diff;
			index = i;
		}
		i++;
	}
	data->to_print[0] = data->possibilities[index].result[0];
	data->to_print[1] = data->possibilities[index].result[1];
}
