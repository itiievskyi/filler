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

static void	check_place(t_filler *par, int x, int y, int overlap)
{
	par->error = 0;
	while (y < par->tokeny && !par->error)
	{
		x = 0;
		while (x < par->tokenx && !par->error)
		{
			if (par->token[y][x] == '.' || (par->token[y][x] == '*'
				&& par->map[par->cury + y][par->curx + x] == '.'))
				x++;
			else if ((par->token[y][x] == '*') &&
					(par->map[par->cury + y][par->curx + x] == par->player ||
					par->map[par->cury + y][par->curx + x] == par->player + 32))
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
		test_space(par, 0, 0);
}

void		solve_filler(t_filler *par)
{
	check_space(par, -1, -1, 0);
	check_e_coord(par, 0, 0, 0);
	while ((par->cury) + (par->tokeny) <= (par->sizey))
	{
		par->curx = 0;
		while (par->curx + par->tokenx <= par->sizex)
		{
			check_place(par, 0, 0, 0);
			(par->curx) += 1;
		}
		(par->cury) += 1;
	}
	ft_printf("%d %d\n", par->rety, par->retx);
	reinit_par(par);
}
