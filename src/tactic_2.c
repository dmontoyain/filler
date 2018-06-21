/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:18:54 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:19:12 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		puttop(t_game *data, t_piece *piece)
{
	int x;
	int y;

	x = -1;
	while (data->board[++x] != 0)
	{
		y = -1;
		while (data->board[x][++y] != '\0')
			if (fitpiece_top(piece, data, x, y) == 1)
			{
				ft_putnbr(data->x);
				write(1, " ", 1);
				ft_putnbr(data->y);
				write(1, "\n", 1);
				return (1);
			}
	}
	return (0);
}

int		putbot(t_game *data, t_piece *piece)
{
	int x;
	int y;

	x = data->rows;
	while (x-- > 0)
	{
		y = data->cols;
		while (y-- > 0)
			if (fitpiece_bot(piece, data, x, y) == 1)
			{
				ft_putnbr(data->x);
				write(1, " ", 1);
				ft_putnbr(data->y);
				write(1, "\n", 1);
				return (1);
			}
	}
	return (puttop(data, piece));
}

int		putleftup(t_game *data, t_piece *piece)
{
	int x;
	int y;

	y = -1;
	while (++y < data->cols)
	{
		x = -1;
		while (++x < data->rows)
			if (fitpiece_top(piece, data, x, y) == 1)
			{
				ft_putnbr(data->x);
				write(1, " ", 1);
				ft_putnbr(data->y);
				write(1, "\n", 1);
				return (1);
			}
	}
	return (putbot(data, piece));
}
