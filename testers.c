/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:04:15 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/25 16:04:18 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_e_coord(t_filler *par, int x, int y, int items)
{
	int coord;

	coord = 0;
	while (y < par->sizey)
	{
		x = 0;
		while (x < par->sizex)
		{
			if ((par->map[y][x] == par->enemy ||
				par->map[y][x] == par->enemy2) && items++)
				coord += y + x;
			x++;
		}
		y++;
	}
	if ((items - par->items) && par->step > 1)
		par->e_coord = ((int)coord - (int)(par->coord)) / (items - par->items);
	par->coord = coord;
	par->items = items;
}

void	check_distance(t_filler *par, int x, int y, int items)
{
	while (y < par->tokeny)
	{
		x = 0;
		while (x < par->tokenx)
		{
			if (par->token[y][x] == '*'
				&& par->map[par->cury + y][par->curx + x] == '.' && items++)
				par->p_coord += par->cury + y + par->curx + x;
			x++;
		}
		y++;
	}
	par->p_coord /= items;
	if ((ABS(par->e_coord - par->p_coord)) < par->dist)
	{
		par->retx = par->curx;
		par->rety = par->cury;
		par->dist = ABS(par->e_coord - par->p_coord);
	}
	par->p_coord = 0;
}

void	check_space(t_filler *par, int x, int y, int i)
{
	par->space = 0;
	while (++y < par->sizey)
	{
		x = 0;
		while (++x < par->sizex)
		{
			if (par->map[y][x] == par->enemy ||
				par->map[y][x] == par->enemy2)
			{
				i = 0;
				while (y - ++i >= 0 && par->map[y - i][x] == '.')
					par->space++;
				i = 0;
				while (y + ++i < par->sizey && par->map[y + i][x] == '.')
					par->space++;
				i = 0;
				while (x + ++i < par->sizex && par->map[y][x + i] == '.')
					par->space++;
				i = 0;
				while (x - ++i >= 0 && par->map[y][x - i] == '.')
					par->space++;
			}
		}
	}
}

void	check_space_dup(t_filler *par, int x, int y, int i)
{
	par->temp_space = 0;
	while (++y < par->sizey)
	{
		x = 0;
		while (++x < par->sizex)
		{
			if (par->dup[y][x] == par->enemy || par->dup[y][x] == par->enemy2)
			{
				i = 0;
				while (y - ++i >= 0 && par->dup[y - i][x] == '.')
					par->temp_space++;
				i = 0;
				while (y + ++i < par->sizey && par->dup[y + i][x] == '.')
					par->temp_space++;
				i = 0;
				while (x + ++i < par->sizex && par->dup[y][x + i] == '.')
					par->temp_space++;
				i = 0;
				while (x - ++i >= 0 && par->dup[y][x - i] == '.')
					par->temp_space++;
			}
		}
	}
	approve_place(par);
}

void	test_space(t_filler *par, int x, int y)
{
	par->dup = (char**)malloc(sizeof(char*) * par->sizey);
	while (y < par->sizey)
	{
		par->dup[y] = ft_strdup(par->map[y]);
		y++;
	}
	y = 0;
	while (y < par->tokeny)
	{
		x = 0;
		while (x < par->tokenx)
		{
			if (par->token[y][x] == '*')
				par->dup[par->cury + y][par->curx + x] = '*';
			x++;
		}
		y++;
	}
	check_space_dup(par, -1, -1, 0);
}
