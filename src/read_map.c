/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:51:49 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:22:00 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	size_map(t_filler *data)
{
	get_next_line(0, &data->line);
	if (data->round == 0)
	{
		data->size_map = ft_atoi(data->line);
		ft_strdel(&data->line);
	}
}

char	**read_map(t_filler *data)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char*) * (data->size_map + 2));
	i = 0;
	while (i <= data->size_map)
	{
		get_next_line(0, &data->line);
		map[i] = ft_strdup(data->line);
		ft_strdel(&data->line);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**read_piece(t_filler *data)
{
	char	**piece;
	int		row;
	int		i;

	get_next_line(0, &data->line);
	if (data->line)
		row = ft_atoi(data->line);
	else
		return (NULL);
	ft_strdel(&data->line);
	piece = (char**)malloc(sizeof(char*) * (row + 1));
	i = 0;
	while (i < row)
	{
		get_next_line(0, &data->line);
		piece[i] = ft_strdup(data->line);
		ft_strdel(&data->line);
		i++;
	}
	piece[i] = NULL;
	if (piece[0] == NULL)
		return (NULL);
	return (piece);
}

char	read_player(t_filler *data)
{
	int		i;

	get_next_line(0, &data->line);
	i = 0;
	while (data->line[i] && data->line[i] != '1' && data->line[i] != '2')
		i++;
	if (data->line[i] == '1' && data->line[i + 2] == ':')
	{
		ft_strdel(&data->line);
		return ('O');
	}
	if (data->line[i] == '2' && data->line[i + 2] == ':')
	{
		ft_strdel(&data->line);
		return ('X');
	}
	if (1 < ft_strlen(data->line))
		ft_strdel(&data->line);
	return ('A');
}

char	opponent_sign(char c)
{
	if (c == 'X')
		return ('O');
	else
		return ('X');
}
