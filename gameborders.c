/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameborders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:05:20 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/20 20:00:15 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		bordercheck(t_game *data, t_piece *piece, int x, int y)
{
	if ((y + piece->r_star) >= data->cols && piece->check == 2)
		return (1);
	if ((y - piece->lf_star) < 0 && piece->check == 1)
		return (1);
	if ((x + piece->lo_star) >= data->rows && piece->check == 2)
		return (1);
	if ((x - piece->hi_star) < 0 && piece->check == 1)
		return (1);
	return (0);
}
