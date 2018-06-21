/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:48:40 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:02:34 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		playfiller(t_game *data, t_piece *piece)
{
	direction(data);
	data->oldboard = data->board;
	if (data->direction == 1)
		return (putleftup(data, piece));
	else if (data->direction == 2)
		return (putrightup(data, piece));
	else if (data->direction == 3)
		return (putleftdown(data, piece));
	else if (data->direction == 4)
		return (putrightdwn(data, piece));
	else if (data->direction == 5)
		return (putbot(data, piece));
	return (puttop(data, piece));
}

int		main(void)
{
	t_game		*data;
	t_piece		*piece;
	t_map		*map;

	data = (t_game *)malloc(sizeof(t_game));
	piece = (t_piece *)malloc(sizeof(t_piece));
	map = (t_map *)malloc(sizeof(t_map));
	initialize(data, piece, map);
	player_number(data);
	while (1)
	{
		gameboard(data);
		gamepiece(piece);
		filler_map(data, map);
		if (playfiller(data, piece) != 1)
			break ;
		doublearray_del(piece->piece);
		mlx_do_sync(map->mlx);
	}
	end(data, piece);
	mlx_loop(map->mlx);
	return (0);
}
