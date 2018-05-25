/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:29:30 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/21 11:29:38 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void	read_map(t_filler *par, int i, int a)
{
	if (par->step == 1)
	{
		par->sizey = ft_atoi(&par->line[i]);
		while (ft_isdigit(par->line[i]))
			i++;
		par->sizex = ft_atoi(&par->line[i + 1]);
	}
	if ((par->map = (char**)malloc(sizeof(char*) * par->sizey)))
	{
		i = 0;
		get_next_line(0, &par->line);
		while (i < par->sizey)
		{
			a = 0;
			get_next_line(0, &par->line);
			while (ft_isdigit(par->line[a]))
				a++;
			par->map[i] = ft_strdup(&par->line[a + 1]);
			i++;
		}
	}
}

static void	read_token(t_filler *par, int i)
{
	par->tokeny = ft_atoi(&par->line[i]);
	while (ft_isdigit(par->line[i]))
		i++;
	par->tokenx = ft_atoi(&par->line[i + 1]);
	if ((par->token = (char**)malloc(sizeof(char*) * par->tokeny)))
	{
		i = 0;
		while (i < par->tokeny)
		{
			get_next_line(0, &par->line);
			par->token[i] = ft_strdup(par->line);
			i++;
		}
	}
}

int			main(void)
{
	t_filler	*par;

	init_par((par = (t_filler*)malloc(sizeof(t_filler))));
	if (get_next_line(0, &(par->line)) > 0)
	{
		if (par->line[10] - '0' == 2)
		{
			par->player = 'X';
			par->enemy = 'O';
			par->enemy2 = 'o';
		}
		++par->step;
	}
	while (get_next_line(0, &(par->line)) > 0)
	{
		read_map(par, 8, 0);
		get_next_line(0, &par->line);
		read_token(par, 6);
		solve_filler(par);
		++par->step;
	}
	free(par);
	return (0);
}
