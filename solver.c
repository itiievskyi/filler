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

static void	check_e_coord(t_filler *par, int x, int y)
{
	int coord = 0;
	int items = 0;

	while (y < par->sizeY)
	{
		x = 0;
		while (x < par->sizeX)
		{
			if (par->map[y][x] == 'x' || par->map[y][x] == 'X')
			{
				items++;
				coord += y + x;
			}
			x++;
		}
		y++;
	}
	if ((items - par->items) && par->step > 1)
		par->e_coord = ((int)coord - (int)(par->coord)) / (items - par->items);
	par->coord = coord;
	par->items = items;
}

static void	check_distance(t_filler *par, int x, int y)
{
	int items = 0;
	while (y < par->tokenY)
	{
		x = 0;
		while (x < par->tokenX)
		{
			if (par->token[y][x] == '*' && par->map[par->curY + y][par->curX + x] == '.')
			{
				items++;
				par->p_coord +=	par->curY + y + par->curX + x;
			}
			x++;
		}
		y++;
	}
	par->p_coord /= items;
	if ((ABS(par->e_coord - par->p_coord)) < par->dist)
	{
		par->retX = par->curX;
		par->retY = par->curY;
		par->dist = ABS(par->e_coord - par->p_coord);
	}
	par->p_coord = 0;
}

static void	check_space(t_filler *par, int x, int y, int index)
{
	int space = 0;
	while (y < par->sizeY)
	{
		x = 0;
		while (x < par->sizeX)
		{
			if (par->map[y][x] == 'x' || par->map[y][x] == 'X')
			{
				index = 0;
				while(y - ++index >= 0 && par->map[y - index][x] == '.')
					space++;
				index = 0;
				while(y + ++index < par->sizeY && par->map[y + index][x] == '.')
					space++;
				index = 0;
				while(x + ++index < par->sizeX && par->map[y][x + index] == '.')
					space++;
				index = 0;
				while(x - ++index >= 0 && par->map[y][x - index] == '.')
					space++;
			}
			x++;
		}
		y++;
	}
//	if ((items - par->items) && par->step > 1)
//		par->e_coord = ((int)coord - (int)(par->coord)) / (items - par->items);
	par->space = space;
//	ft_putstr_fd("\npar->space = ", 2);
//	ft_putnbr_fd(par->space, 2);
//	ft_putstr_fd("\n", 2);
}

static void	check_space_dup(t_filler *par, int x, int y, int index)
{
	int space = 0;
	while (y < par->sizeY)
	{
		x = 0;
		while (x < par->sizeX)
		{
			if (par->dup[y][x] == 'x' || par->dup[y][x] == 'X')
			{
				index = 0;
				while(y - ++index >= 0 && par->dup[y - index][x] == '.')
					space++;
				index = 0;
				while(y + ++index < par->sizeY && par->dup[y + index][x] == '.')
					space++;
				index = 0;
				while(x + ++index < par->sizeX && par->dup[y][x + index] == '.')
					space++;
				index = 0;
				while(x - ++index >= 0 && par->dup[y][x - index] == '.')
					space++;
			}
			x++;
		}
		y++;
	}
	if (space < par->space)
	{
		par->retX = par->curX;
		par->retY = par->curY;
		par->space = space;
	}
	else if (space == par->space)
		check_distance(par, 0, 0);
//	if ((items - par->items) && par->step > 1)
//		par->e_coord = ((int)coord - (int)(par->coord)) / (items - par->items);
//	ft_putstr_fd("\npar->space = ", 2);
//	ft_putnbr_fd(par->space, 2);
//	ft_putstr_fd("\n", 2);
}

static void	test_space(t_filler *par, int x, int y)
{
	par->dup = (char**)malloc(sizeof(char*) * par->sizeY);
	while (y < par->sizeY)
	{
		par->dup[y] = ft_strdup(par->map[y]);
		y++;
	}
	y = 0;
	while (y < par->tokenY)
	{
		x = 0;
		while (x < par->tokenX)
		{
			if (par->token[y][x] == '*')
				par->dup[par->curY + y][par->curX + x] = '*';
			x++;
		}
		y++;
	}
	check_space_dup(par, 0, 0, 0);
/*
	int a = 0;
	int b = 0;
	while (b < par->sizeY)
	{
		a = 0;
		while (a < par->sizeX)
		{
			ft_putchar_fd(par->dup[b][a], 2);
			a++;
		}
		ft_putstr_fd("\n", 2);
		b++;
	}
*/
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
		test_space(par, 0, 0);
}

void		solve_filler(t_filler *par)
{
	check_space(par, 0, 0, 0);
	check_e_coord(par, 0, 0);
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





/*
	ft_putstr_fd("\nSTEP = ", 2);
	ft_putnbr_fd(par->step, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\npar->coord = ", 2);
	ft_putnbr_fd(par->coord, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\ncoord = ", 2);
	ft_putnbr_fd(coord, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\ne_coord = ", 2);
	ft_putnbr_fd(par->e_coord, 2);
	ft_putstr_fd("\n", 2);
*/


/*
		ft_putstr_fd("\np_coord = ", 2);
		ft_putnbr_fd(par->p_coord, 2);
		ft_putstr_fd("\ndist = ", 2);
		ft_putnbr_fd(par->dist, 2);
		ft_putstr_fd("\n", 2);
*/
