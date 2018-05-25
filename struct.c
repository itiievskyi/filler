/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:57:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/22 10:57:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_par(t_filler *par)
{
	par->line = NULL;
	par->map = NULL;
	par->dup = NULL;
	par->token = NULL;
	par->sizey = 0;
	par->sizex = 0;
	par->player = 'O';
	par->enemy = 'X';
	par->enemy2 = 'x';
	par->curx = 0;
	par->cury = 0;
	par->retx = 0;
	par->rety = 0;
	par->tokenx = 0;
	par->tokeny = 0;
	par->error = 0;
	par->step = 0;
	par->dist = 1000000;
	par->coord = 0;
	par->e_coord = 0;
	par->p_coord = 0;
	par->items = 0;
	par->space = 0;
	par->temp_space = 0;
}

void	reinit_par(t_filler *par)
{
	par->curx = 0;
	par->cury = 0;
	par->retx = 0;
	par->rety = 0;
	par->tokenx = 0;
	par->tokeny = 0;
	par->error = 0;
	par->dist = 1000000;
}

void	approve_place(t_filler *par)
{
	if (par->temp_space < par->space)
	{
		par->retx = par->curx;
		par->rety = par->cury;
		par->space = par->temp_space;
	}
	else if (par->temp_space == par->space)
		check_distance(par, 0, 0, 0);
}
