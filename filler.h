/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:27:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/21 11:27:36 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# define ABS(x) (x < 0 ? (x * -1) : x)

typedef struct		s_filler
{
	char			*line;
	char			**map;
	char			**dup;
	char			**token;
	int				sizey;
	int				sizex;
	char			player;
	char			enemy;
	char			enemy2;
	int				curx;
	int				cury;
	int				retx;
	int				rety;
	int				tokenx;
	int				tokeny;
	int				error;
	int				step;
	int				dist;
	int				coord;
	int				e_coord;
	int				p_coord;
	int				items;
	int				space;
	int				temp_space;
}					t_filler;
void				init_par(t_filler *par);
void				reinit_par(t_filler *par);
void				test_space(t_filler *par, int x, int y);
void				check_space_dup(t_filler *par, int x, int y, int i);
void				check_space(t_filler *par, int x, int y, int i);
void				check_distance(t_filler *par, int x, int y, int items);
void				check_e_coord(t_filler *par, int x, int y, int items);
void				solve_filler(t_filler *par);
void				approve_place(t_filler *par);
#endif
