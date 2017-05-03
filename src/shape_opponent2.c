/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_opponent2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:08:28 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:22:07 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		scoring_corner_bis(t_filler *data, int i, int j)
{
	int		count;
	int		tmpi;
	int		tmpj;

	i = i + 1;
	j = j + 4;
	tmpi = i;
	tmpj = j;
	count = 0;
	i--;
	while (data->map[i][j] == '.' && 1 < i)
	{
		count++;
		i--;
	}
	i = tmpi + 1;
	while (data->map[i] && data->map[i][j] == '.')
	{
		count++;
		i++;
	}
	return (count);
}

int		scoring_corner(t_filler *data, int i, int j)
{
	int		count;
	int		tmpi;
	int		tmpj;

	tmpi = i;
	tmpj = j;
	count = scoring_corner_bis(data, i, j);
	i = i + 1;
	j = j + 4;
	j++;
	while (data->map[i][j] == '.' && j < (int)ft_strlen(data->map[1] - 1))
	{
		count++;
		j++;
	}
	j = tmpj - 1;
	while (data->map[i][j] == '.')
	{
		count++;
		j--;
	}
	return (count);
}

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		max_corner(int *tab)
{
	int		i;
	int		tmp;
	int		index;

	tmp = 0;
	i = 0;
	while (i < 8)
	{
		if (tmp < tab[i])
		{
			tmp = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	closest_corner(t_filler *data)
{
	int		max;
	int		*corner;

	corner = (int*)malloc(sizeof(int) * 8);
	shape_opponent(data);
	corner[0] = scoring_corner(data, data->corner[0][0], data->corner[0][1]);
	corner[1] = scoring_corner(data, data->corner[1][0], data->corner[1][1]);
	corner[2] = scoring_corner(data, data->corner[2][0], data->corner[2][1]);
	corner[3] = scoring_corner(data, data->corner[3][0], data->corner[3][1]);
	corner[4] = scoring_corner(data, data->corner[4][0], data->corner[4][1]);
	corner[5] = scoring_corner(data, data->corner[5][0], data->corner[5][1]);
	corner[6] = scoring_corner(data, data->corner[6][0], data->corner[6][1]);
	corner[7] = scoring_corner(data, data->corner[7][0], data->corner[7][1]);
	max = max_corner(corner);
	data->target[0] = data->corner[max][0];
	data->target[1] = data->corner[max][1];
}
