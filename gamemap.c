/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 14:43:10 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/22 21:22:39 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_pixel(t_map *map, int i, unsigned int color)
{
	map->str[i] = color;
	map->str[++i] = color >> 8;
	map->str[++i] = color >> 16;
}

void	mapcolor(t_map *map)
{
	int	i;
	int	limit;

	i = 0;
	limit = map->lsize * map->winh;
	while (i < limit)
	{
		put_pixel(map, i, GRAY);
		i += 4;
	}
}

int		squarecolor(t_game *data, t_map *map, int i)
{
	if (data->board[data->x][data->y] == data->mestart)
		put_pixel(map, i, 0);
	else if (data->board[data->x][data->y] == data->opstart)
		put_pixel(map, i, WHITE);
	else if (data->board[data->x][data->y] == data->me)
		put_pixel(map, i, GREEN);
	return (4);
}

void	updateimage(t_game *data, t_map *map)
{
	int	i;
	int	h;
	int	limit;
	int	limit2;

	data->x = -1;
	while (++data->x < data->rows)
	{
		data->y = -1;
		while (++data->y < data->cols)
		{
			if (data->board[data->x][data->y] != '.')
			{
				h = data->x * map->image_h - 1;
				limit2 = h + map->image_h;
				while (++h < limit2)
				{
					i = (data->y * map->image_w) + (h * map->lsize);
					limit = i + map->image_w;
					while (i < limit)
						i += squarecolor(data, map, i);
				}
			}
		}
	}
}

void	filler_map(t_game *data, t_map *map)
{
	if (map->w == 0)
		window(data, map);
	updateimage(data, map);
	mlx_put_image_to_window(map->mlx, map->win, map->image, 0, 0);
}
