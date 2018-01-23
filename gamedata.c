/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:20:27 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:06:45 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		verifymychar(t_game *data)
{
	int x;
	int y;

	x = -1;
	while (data->board[++x] != 0)
	{
		y = -1;
		while (data->board[x][++y] != '\0')
			if (data->board[x][y] == data->me)
				return (1);
	}
	return (0);
}

void	gamepiece(t_piece *piece)
{
	char	*line;
	int		pos;

	pos = -1;
	piece->hi_star = 0;
	piece->lo_star = 0;
	piece->lf_star = 0;
	piece->r_star = 0;
	get_next_line(0, &line);
	piece->rpiece = ft_atoi(&line[6]);
	piece->cpiece = ft_atoi(&line[7 + ft_intlen(piece->rpiece)]);
	piece->piece = (char **)malloc(sizeof(char*) * (piece->rpiece + 1));
	piece->piece[piece->rpiece] = 0;
	while (++pos < piece->rpiece)
		get_next_line(0, &piece->piece[pos]);
	borderparameters(piece);
	ft_strdel(&line);
}

void	board_measurements(t_game *data)
{
	char *line;

	get_next_line(0, &line);
	if (!data->rows)
	{
		data->rows = ft_atoi(&line[8]);
		data->cols = ft_atoi(&line[9 + ft_intlen(data->rows)]);
	}
	ft_strdel(&line);
}

void	gameboard(t_game *data)
{
	int		pos;
	char	*line;

	board_measurements(data);
	pos = 0;
	data->board = (char **)malloc(sizeof(char *) * (data->rows + 1));
	data->board[data->rows] = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		data->board[pos] = ft_strsub(line, 4, data->cols);
		ft_strdel(&line);
		if (++pos == data->rows)
			break ;
	}
	myposition(data);
	if (data->start == 0)
		opponentstart(data);
	else
		opponentposition(data);
}

void	player_number(t_game *data)
{
	char	*line;

	get_next_line(0, &line);
	data->player = ft_atoi(&line[10]);
	if (data->player == 1)
	{
		data->mestart = 'O';
		data->opstart = 'X';
		data->me = 'o';
		data->op = 'x';
	}
	else
	{
		data->mestart = 'X';
		data->opstart = 'O';
		data->me = 'x';
		data->op = 'o';
	}
	ft_strdel(&line);
}
