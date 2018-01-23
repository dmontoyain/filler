/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:31:28 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:53:30 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		solver_top(t_game *d, t_piece *piece, int x, int y)
{
	int xp;
	int yp;

	xp = -1;
	while (++xp < piece->rpiece)
	{
		yp = -1;
		while (++yp < piece->cpiece)
		{
			if (d->board[x][y] == '\0')
				break ;
			if (piece->piece[xp][yp] == '*' && (d->board[x][y] == d->op
				|| d->board[x][y] == d->opstart
				|| (d->board[x][y] == d->mestart && d->my != d->mestart)))
				return (0);
			if (piece->piece[xp][yp] == '*' && d->board[x][y] == d->my)
				if (++d->count > 1)
					return (0);
			y++;
		}
		if (++x == d->rows)
			return (1);
		y -= yp;
	}
	return (1);
}

int		fitpiece_top(t_piece *piece, t_game *data, int x, int y)
{
	data->count = 0;
	piece->check = 2;
	if (bordercheck(data, piece, x, y) == 1)
		return (0);
	if (solver_top(data, piece, x, y) == 0)
		return (0);
	if (data->count == 1)
	{
		data->x = x;
		data->y = y;
		return (1);
	}
	return (0);
}

int		solver_bot(t_game *d, t_piece *piece, int x, int y)
{
	int yp;
	int xp;

	xp = piece->rpiece;
	while (xp-- > 0)
	{
		yp = piece->cpiece;
		while (yp-- > 0)
		{
			if (piece->piece[xp][yp] == '*' && (d->board[x][y] == d->op
				|| d->board[x][y] == d->opstart
				|| (d->board[x][y] == d->mestart && d->my != d->mestart)))
				return (0);
			if (piece->piece[xp][yp] == '*' && d->board[x][y] == d->my)
				d->count++;
			if (d->count > 1)
				return (0);
			if (y-- == 0 || yp == 0)
				break ;
		}
		if (x-- == 0)
			return (1);
		y += (piece->cpiece - yp);
	}
	return (1);
}

int		fitpiece_bot(t_piece *piece, t_game *data, int x, int y)
{
	data->count = 0;
	piece->check = 1;
	if (bordercheck(data, piece, x, y) == 1)
		return (0);
	if (solver_bot(data, piece, x, y) == 0)
		return (0);
	if (data->count == 1)
	{
		data->x = x - (piece->rpiece - 1);
		data->y = y - (piece->cpiece - 1);
		return (1);
	}
	return (0);
}
