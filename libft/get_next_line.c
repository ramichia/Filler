/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:14:54 by ramichia          #+#    #+#             */
/*   Updated: 2017/03/21 17:25:45 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ENDL '\n'

int		read_from_fd_into_stock(int const fd, char **stock)
{
	static char	buff[BUFF_SIZE + 1] = { ENDL };
	int			read_bytes;
	char		*nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(*stock, buff);
		if (!nstr)
			return (-1);
		free(*stock);
		*stock = nstr;
	}
	return (read_bytes);
}

int		get_next_line(int const fd, char **line)
{
	static char	*stock = NULL;
	char		*endl_index;
	int			ret;

	if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	endl_index = ft_strchr(stock, ENDL);
	while (endl_index == NULL)
	{
		ret = read_from_fd_into_stock(fd, &stock);
		if (ret == 0 && \
			((endl_index = ft_strchr(stock, '\0')) == stock))
			return (0);
		else if (ret < 0)
			return (-1);
		else
			endl_index = ft_strchr(stock, ENDL);
	}
	*line = ft_strsub(stock, 0, endl_index - stock);
	if (!*line)
		return (-1);
	endl_index = ft_strdup(endl_index + 1);
	free(stock);
	stock = endl_index;
	return (1);
}
