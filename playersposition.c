/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playersposition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 01:11:07 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 19:51:25 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	myposition(t_game *data)
{
	int x;
	int y;

	x = -1;
	data->my = data->me;
	if (verifymychar(data) == 0)
		data->my = data->mestart;
	while (data->board[++x] != 0)
	{
		y = -1;
		while (data->board[x][++y] != '\0')
			if (data->board[x][y] == data->my)
			{
				data->mecol = y;
				data->merow = x;
				return ;
			}
	}
}

void	opponentstart(t_game *data)
{
	int x;
	int y;

	x = -1;
	data->start++;
	while (data->board[++x] != 0)
	{
		y = -1;
		while (data->board[x][++y] != '\0')
			if (data->board[x][y] == data->opstart)
			{
				data->opcol = y;
				data->oprow = x;
				return ;
			}
	}
}

void	opponentposition(t_game *data)
{
	int x;
	int y;

	x = -1;
	if (data->opcol < 0 && data->oprow < 0)
	{
		doublearray_del(data->oldboard);
		return ;
	}
	while (data->board[++x] != 0)
	{
		y = -1;
		while (data->board[x][++y] != '\0')
			if (data->board[x][y] != data->oldboard[x][y]
				&& data->board[x][y] == data->opstart)
			{
				data->opcol = y;
				data->oprow = x;
				doublearray_del(data->oldboard);
				return ;
			}
	}
	data->opcol = -1;
	data->oprow = -1;
	doublearray_del(data->oldboard);
}
