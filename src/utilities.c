/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:25:35 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/22 19:35:18 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	end(t_game *data, t_piece *piece)
{
	ft_putnbr(0);
	write(1, " ", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	doublearray_del(data->board);
	doublearray_del(piece->piece);
	free(data);
	free(piece);
}

void	initialize(t_game *data, t_piece *piece, t_map *map)
{
	data->me = 0;
	data->op = 0;
	data->rows = 0;
	data->cols = 0;
	data->player = 0;
	data->mestart = 0;
	data->opstart = 0;
	data->direction = 0;
	piece->cpiece = 0;
	piece->rpiece = 0;
	data->oprow = 0;
	data->opcol = 0;
	data->merow = 0;
	data->mecol = 0;
	data->start = 0;
	data->x = 0;
	data->y = 0;
	map->w = 0;
}

void	window(t_game *data, t_map *m)
{
	int	b;
	int i;

	i = 0;
	m->w = 1;
	b = data->cols * 4;
	while ((b * i) < 1000)
		i++;
	m->winw = b * i;
	i = 0;
	while ((data->rows * i) < 800)
		i++;
	m->winh = data->rows * i;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->winw, m->winh, "FILLER");
	m->image = mlx_new_image(m, m->winw, m->winh);
	m->str = mlx_get_data_addr(m->image, &(m->bpp), &(m->lsize), &(m->endian));
	mlx_hook(m->win, 2, 0, keyhandler, m);
	m->image_h = m->winh / data->rows;
	m->image_w = m->lsize / data->cols;
	mapcolor(m);
}

int		keyhandler(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_image(map->mlx, map->image);
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	return (0);
}
