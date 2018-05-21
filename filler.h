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

typedef struct		s_filler
{
	char			*line;
	char			**map;
	char			**token;
	int				sizeY;
	int				sizeX;
	int				player;
	int				curX;
	int				curY;
	int				retX;
	int				retY;
	int				tokenX;
	int				tokenY;
	int				error;
	int				step;
}					t_filler;

#endif
