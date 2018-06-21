/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspectgameboardborders.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:04:56 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:04:03 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	leftborder(t_piece *piece)
{
	int x;
	int y;

	y = -1;
	while (++y < piece->cpiece)
	{
		x = -1;
		while (++x < piece->rpiece)
			if (piece->piece[x][y] == '*')
			{
				piece->lf_star = piece->cpiece - (y + 1);
				return ;
			}
	}
}

void	rightborder(t_piece *piece)
{
	int	y;
	int	x;

	y = piece->cpiece;
	while (y-- > 0)
	{
		x = -1;
		while (++x < piece->rpiece)
			if (piece->piece[x][y] == '*')
			{
				piece->r_star = y;
				return ;
			}
	}
}

void	botborder(t_piece *piece)
{
	int x;
	int y;

	x = piece->rpiece;
	while (x-- > 0)
	{
		y = -1;
		while (++y < piece->cpiece)
			if (piece->piece[x][y] == '*')
			{
				piece->lo_star = x;
				return ;
			}
	}
}

void	topborder(t_piece *piece)
{
	int	x;
	int	y;

	x = -1;
	while (++x < piece->rpiece)
	{
		y = -1;
		while (++y < piece->cpiece)
			if (piece->piece[x][y] == '*')
			{
				piece->hi_star = piece->rpiece - (x + 1);
				return ;
			}
	}
}

void	borderparameters(t_piece *piece)
{
	leftborder(piece);
	topborder(piece);
	rightborder(piece);
	botborder(piece);
}
