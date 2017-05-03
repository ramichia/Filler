/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:55:06 by ramichia          #+#    #+#             */
/*   Updated: 2017/05/03 13:24:18 by ramichia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct			s_solutions
{
	int					result[2];
	int					diff;
}						t_solutions;

typedef struct			s_filler
{
	char				**map;
	char				**piece;
	int					round;
	int					to_print[2];
	int					target[2];
	int					own_center[2];
	int					back_opponent[2];
	int					up_opponent[2];
	int					right_opponent[2];
	int					down_opponent[2];
	int					center_opponent[2];
	int					**corner;
	int					piece_row;
	int					piece_column;
	int					*tab;
	int					contact;
	int					size_map;
	char				c;
	char				opponent;
	char				*line;
	struct s_solutions	possibilities[10000];
}						t_filler;

char					read_player(t_filler *data);
void					size_map(t_filler *data);
char					**read_map(t_filler *data);
char					**read_piece(t_filler *data);
int						piece_row(t_filler *data, int i);
int						piece_column(t_filler *data, int i, int j);
int						place_piece(t_filler *data, int i, int j);
void					find_piece(t_filler *data);
char					opponent_sign(char c);
void					set_diff(t_filler *data);
void					clean(t_filler *data);
void					choose_target(t_filler *data);
int						check_contact(char	**map, char c, char o);
void					set_target(t_filler *data);
void					first_position(t_filler *data);
void					fill_solutions(int i, int j, t_solutions *possible);
void					compute_back_opponent(t_filler *data);
void					shape_opponent(t_filler *data);
int						same_line(t_filler *data);
void					closest_corner(t_filler *data);
int						absolute_value(int nbr);
void					target_average(t_filler *data);
int						set_priority_target(t_filler *data);
int						max_corner(int *tab);
int						scoring_corner(t_filler *data, int i, int j);

#endif
