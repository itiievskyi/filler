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
	char			**token;
	int				sizeY;
	int				sizeX;
	char			player;
	char			enemy;
	int				curX;
	int				curY;
	int				retX;
	int				retY;
	int				tokenX;
	int				tokenY;
	int				error;
	int				step;
	int				dist;
	int				coord;
	int				e_coord;
	int				p_coord;
	int				items;
	int				space;
}					t_filler;
void				init_par(t_filler *par);
void				reinit_par(t_filler *par);
void				solve_filler(t_filler *par);
#endif
