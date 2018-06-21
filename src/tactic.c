/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:15:55 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:27:18 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	direction_2(t_game *data)
{
	if ((data->opcol < data->mecol) && (data->oprow < data->merow))
	{
		data->direction = 1;
		if (data->merow > (data->rows / 2) && data->mecol > (data->cols / 2))
			data->direction = 6;
	}
	else if ((data->opcol > data->mecol) && (data->oprow == data->merow))
	{
		data->direction = 1;
		if (data->merow < (data->rows / 2))
			data->direction = 4;
	}
	else if ((data->opcol < data->mecol) && (data->oprow == data->merow))
	{
		data->direction = 1;
		if (data->merow < (data->rows / 2))
			data->direction = 3;
	}
	else
		data->direction = 6;
}

void	direction(t_game *data)
{
	if (data->opcol == -1 && data->oprow == -1)
		data->direction = 5;
	else if ((data->opcol < data->mecol) && (data->oprow > data->merow))
		data->direction = 3;
	else if ((data->opcol > data->mecol) && (data->oprow < data->merow))
		data->direction = 2;
	else if ((data->opcol > data->mecol) && (data->oprow > data->merow))
	{
		data->direction = 4;
		if (data->merow >= (data->rows / 2))
			data->direction = 2;
	}
	else if ((data->opcol == data->mecol) && (data->oprow > data->merow))
		data->direction = 5;
	else if ((data->opcol == data->mecol) && (data->oprow < data->merow))
		data->direction = 6;
	else
		return (direction_2(data));
}

int		putrightdwn(t_game *data, t_piece *piece)
{
	int x;
	int y;

	y = data->cols;
	while (y-- > 0)
	{
		x = data->rows;
		while (x-- > 0)
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

int		putrightup(t_game *data, t_piece *piece)
{
	int x;
	int y;

	y = data->cols;
	while (y-- > 0)
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

int		putleftdown(t_game *data, t_piece *piece)
{
	int x;
	int y;

	y = -1;
	while (++y < data->cols)
	{
		x = data->rows;
		while (x-- > 0)
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
