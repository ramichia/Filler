/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:29:29 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:22:14 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char	*copy_line(char *str)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strrev(str);
	tmp2 = ft_strdup(&tmp[1]);
	tmp3 = ft_strrev(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (tmp3);
}

void	print_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'X' || line[i] == 'x')
			ft_printf("\033[31m%c\033[0m", line[i]);
		else if (line[i] == 'O')
			ft_printf("\033[32m%c\033[0m", line[i]);
		else
			ft_printf("%c", line[i]);
		i++;
	}
	ft_printf("\n");
}

char	**player_name(char *line)
{
	char	**tab;
	int		i;

	tab = (char**)malloc(sizeof(char*) * 3);
	i = ft_strlen(line) - 1;
	while (line[i] != '/')
		i--;
	tab[0] = copy_line(&line[i + 1]);
	get_next_line(0, &line);
	print_line(line);
	ft_strdel(&line);
	get_next_line(0, &line);
	print_line(line);
	i = ft_strlen(line) - 1;
	while (line[i] != '/')
		i--;
	tab[1] = copy_line(&line[i + 1]);
	tab[2] = NULL;
	ft_strdel(&line);
	return (tab);
}

int		compute_winner(char *line)
{
	int		score1;
	int		score2;

	score1 = ft_atoi(&line[10]);
	get_next_line(0, &line);
	print_line(line);
	score2 = ft_atoi(&line[10]);
	if (score1 > score2)
		return (0);
	else
		return (1);
}

int		main(void)
{
	char	*line;
	int		r;
	int		winner;
	char	**player;

	r = get_next_line(0, &line);
	if (r == -1)
		return (0);
	while (0 < r)
	{
		print_line(line);
		if (line[0] == '=' && line[1] == '=')
			winner = compute_winner(line);
		if (line[0] == '$' && line[1] == '$' && line[2] == '$')
			player = player_name(line);
		ft_strdel(&line);
		r = get_next_line(0, &line);
	}
	ft_printf("\033[44;33;1m%s WIN\033[0m\n", player[winner]);
	return (0);
}
