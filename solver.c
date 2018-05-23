/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:33:54 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/22 12:33:56 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_distance(t_filler *par)
{
//	if ((ABS(par->curX - (par->sizeX / 2)) + ABS(par->curY - (par->sizeY / 2))) < par->dist)
//	{
		par->retX = par->curX;
		par->retY = par->curY;
//		par->dist = (ABS(par->curX - (par->sizeX / 2)) + ABS(par->curY - (par->sizeY / 2)));
//	}
}

static void	check_place(t_filler *par, int x, int y, int overlap)
{
	par->error = 0;
	while (y < par->tokenY && !par->error)
	{
		x = 0;
		while (x < par->tokenX && !par->error)
		{
			if (par->token[y][x] == '.' || (par->token[y][x] == '*'
				&& par->map[par->curY + y][par->curX + x] == '.'))
				x++;
			else if ((par->token[y][x] == '*') &&
				(par->map[par->curY + y][par->curX + x] == par->player ||
				par->map[par->curY + y][par->curX + x] == par->player + 32))
				{
					overlap++;
					x++;
				}
			else
				par->error += 1;
		}
		y++;
	}
	if (overlap == 1 && !par->error)
		check_distance(par);
}

void		solve_filler(t_filler *par)
{
	while ((par->curY) + (par->tokenY) <= (par->sizeY))
	{
		par->curX = 0;
		while (par->curX + par->tokenX <= par->sizeX)
		{
			check_place(par, 0, 0, 0);
			(par->curX) += 1;
		}
		(par->curY) += 1;
	}
	ft_printf("%d %d\n", par->retY, par->retX);
	reinit_par(par);
}
