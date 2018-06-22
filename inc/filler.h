/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 22:50:01 by dmontoya          #+#    #+#             */
/*   Updated: 2018/01/22 21:25:37 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# define RED 0xFF4040
# define YELLOW 0xFFBA00
# define GRAY 0xCCCCCC
# define GREEN 0x5CD38C
# define BLUE 0x316989
# define WHITE 0xFFFFFF

typedef struct	s_game
{
	int			x;
	int			y;
	int			player;
	int			rows;
	int			cols;
	int			me;
	int			start;
	int			mestart;
	int			opstart;
	int			op;
	int			my;
	int			count;
	int			mecol;
	int			merow;
	int			opcol;
	int			oprow;
	int			direction;
	char		**board;
	char		**oldboard;
}				t_game;

typedef struct	s_piece
{
	int			lf_star;
	int			r_star;
	int			lo_star;
	int			hi_star;
	int			rpiece;
	int			cpiece;
	int			check;
	char		**piece;
}				t_piece;

typedef	struct	s_map
{
	void		*mlx;
	void		*win;
	void		*image;
	int			w;
	int			winh;
	int			winw;
	int			image_h;
	int			image_w;
	int			bpp;
	int			endian;
	int			lsize;
	char		*str;
}				t_map;

int				puttop(t_game *data, t_piece *piece);
int				putbot(t_game *data, t_piece *piece);
int				fitpiece_bot(t_piece *piece, t_game *data, int x, int y);
int				fitpiece_top(t_piece *piece, t_game *data, int x, int y);
void			player_number(t_game *data);
void			gameboard(t_game *data);
void			gamepiece(t_piece *piece);
int				verifymychar(t_game *data);
void			borderparameters(t_piece *piece);
int				bordercheck(t_game *data, t_piece *piece, int x, int y);
void			initialize(t_game *data, t_piece *piece, t_map *map);
void			myposition(t_game *data);
void			direction(t_game *data);
void			opponentposition(t_game *data);
void			opponentstart(t_game *data);
int				putrightup(t_game *data, t_piece *piece);
int				putleftdown(t_game *data, t_piece *piece);
int				putrightdwn(t_game *data, t_piece *piece);
int				putleftup(t_game *data, t_piece *piece);
void			filler_map(t_game *data, t_map *map);
int				keyhandler(int keycode, t_map *map);
void			window(t_game *data, t_map *map);
void			end(t_game *data, t_piece *piece);
void			mapcolor(t_map *map);

#endif
