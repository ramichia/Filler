/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:24:37 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:21:40 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		check_contact(char **map, char c, char o)
{
	int		i;
	int		j;

	i = 1;
	while (map[i + 1])
	{
		j = 4;
		while (map[i][j + 1])
		{
			if (map[i][j] == c)
			{
				if (map[i + 1][j] == o || map[i][j + 1] == o || \
					map[i - 1][j] == o || map[i][j - 1] == o || \
					map[i - 1][j - 1] == o || map[i + 1][j - 1] == o || \
					map[i - 1][j + 1] == o || map[i + 1][j + 1] == o)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	set_target(t_filler *data)
{
	if ((data->contact == 0 || data->round < 10) && data->size_map < 16 && \
		data->c == 'X')
	{
		data->target[0] = 0;
		data->target[1] = 12;
	}
	else if (data->contact == 0)
	{
		if (data->c == 'X' && data->size_map < 25)
		{
			data->target[0] = 16;
			data->target[1] = 0;
		}
		else if (data->c == 'O' && 80 < data->size_map)
		{
			data->target[0] = 65;
			data->target[1] = 0;
		}
		else
			target_average(data);
	}
	else
		closest_corner(data);
}
