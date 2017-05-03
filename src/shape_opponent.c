/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_opponent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:42:47 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:22:04 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	compute_back_opponent(t_filler *data)
{
	int		i;
	int		j;

	j = 4;
	i = 1;
	while (data->map[i][j])
	{
		while (data->map[i])
		{
			if (data->map[i][j] == data->opponent)
			{
				data->back_opponent[0] = i - 1;
				data->back_opponent[1] = j - 4;
				return ;
			}
			i++;
		}
		i = 1;
		j++;
	}
}

void	compute_up_opponent(t_filler *data)
{
	int		i;
	int		j;

	i = 1;
	while (data->map[i])
	{
		j = 4;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->opponent)
			{
				data->up_opponent[0] = i - 1;
				data->up_opponent[1] = j - 4;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	compute_down_opponent(t_filler *data)
{
	int		i;
	int		j;

	i = data->size_map - 1;
	while (0 <= i)
	{
		j = ft_strlen(data->map[1]) - 1;
		while (0 <= j)
		{
			if (data->map[i][j] == data->opponent)
			{
				data->down_opponent[0] = i - 1;
				data->down_opponent[1] = j - 4;
				return ;
			}
			j--;
		}
		i--;
	}
}

void	compute_right_opponent(t_filler *data)
{
	int		i;
	int		j;

	j = ft_strlen(data->map[1]) - 1;
	i = 1;
	while (0 <= j)
	{
		while (data->map[i])
		{
			if (data->map[i][j] == data->opponent)
			{
				data->right_opponent[0] = i - 1;
				data->right_opponent[1] = j - 4;
				return ;
			}
			i++;
		}
		i = 1;
		j--;
	}
}

void	shape_opponent(t_filler *data)
{
	compute_back_opponent(data);
	compute_right_opponent(data);
	compute_up_opponent(data);
	compute_down_opponent(data);
	data->corner[0][0] = data->up_opponent[0];
	data->corner[0][1] = data->back_opponent[1];
	data->corner[1][0] = data->up_opponent[0];
	data->corner[1][1] = data->right_opponent[1];
	data->corner[2][0] = data->down_opponent[0];
	data->corner[2][1] = data->right_opponent[1];
	data->corner[3][0] = data->down_opponent[0];
	data->corner[3][1] = data->back_opponent[1];
	data->corner[4][0] = data->back_opponent[0];
	data->corner[4][1] = data->back_opponent[1];
	data->corner[5][0] = data->up_opponent[0];
	data->corner[5][1] = data->up_opponent[1];
	data->corner[6][0] = data->right_opponent[0];
	data->corner[6][1] = data->right_opponent[1];
	data->corner[7][0] = data->down_opponent[0];
	data->corner[7][1] = data->down_opponent[1];
}
