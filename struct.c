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
	par->token = NULL;
	par->sizeY = 0;
	par->sizeX = 0;
	par->player = 'O';
	par->enemy = 'X';
	par->curX = 0;
	par->curY = 0;
	par->retX = 0;
	par->retY = 0;
	par->tokenX = 0;
	par->tokenY = 0;
	par->error = 0;
	par->step = 0;
	par->dist = 100000;
}

void	reinit_par(t_filler *par)
{
//	free(par->line);
//	free(par->map);
//	free(par->token);
	par->curX = 0;
	par->curY = 0;
	par->retX = 0;
	par->retY = 0;
	par->tokenX = 0;
	par->tokenY = 0;
	par->error = 0;
	par->dist = 100000;
}
