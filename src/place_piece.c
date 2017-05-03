/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:06:58 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:21:56 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		piece_row(t_filler *data, int i)
{
	int		j;
	int		count;

	count = 0;
	while (data->piece[i])
	{
		j = 0;
		while (data->piece[i][j])
		{
			if (data->piece[i][j] == '*')
			{
				j = ft_strlen(data->piece[0]);
				count = i;
			}
			else
				j++;
		}
		i++;
	}
	return (count);
}

int		piece_column(t_filler *data, int i, int j)
{
	int		count;

	while (data->piece[i][j] && data->piece[i][j] != '\n')
	{
		i = 0;
		while (data->piece[i] && data->piece[i][j] && data->piece[i][j] != '\n')
		{
			if (data->piece[i][j] == '*')
			{
				count = j;
				i = 0;
				j++;
			}
			else
				i++;
		}
		i = 0;
		j++;
		if (j > (int)ft_strlen(data->piece[0]))
			break ;
	}
	return (count);
}

int		place_piece(t_filler *data, int i, int j)
{
	int		cr;
	int		cc;
	int		count;

	count = 0;
	cr = 0;
	cc = 0;
	while (cr <= data->piece_row && data->map[i])
	{
		j = j - cc;
		cc = 0;
		while (cc <= data->piece_column && data->map[i][j])
		{
			if (data->piece[cr][cc] == '*' && \
				data->map[i][j] == data->opponent)
				return (0);
			if (data->map[i][j] == data->c && data->piece[cr][cc] == '*')
				count++;
			cc++;
			j++;
		}
		cr++;
		i++;
	}
	return (count);
}
