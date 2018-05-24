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
		par->sizeY = ft_atoi(&par->line[i]);
		while(ft_isdigit(par->line[i]))
			i++;
		par->sizeX = ft_atoi(&par->line[i + 1]);
	}
	if ((par->map = (char**)malloc(sizeof(char*) * par->sizeY)))
	{
		i = 0;
		get_next_line(0, &par->line);
		while(i < par->sizeY)
		{
			a = 0;
			get_next_line(0, &par->line);
//												ft_putstr_fd("\nline = ", 2);
//												ft_putstr_fd(par->line, 2);
//												ft_putstr_fd("\n", 2);
			while(ft_isdigit(par->line[a]))
				a++;
			par->map[i] = ft_strdup(&par->line[a + 1]);
			i++;
		}
	}
}

static void	read_token(t_filler *par, int i)
{
	par->tokenY = ft_atoi(&par->line[i]);
	while(ft_isdigit(par->line[i]))
		i++;
	par->tokenX = ft_atoi(&par->line[i + 1]);
	if ((par->token = (char**)malloc(sizeof(char*) * par->tokenY)))
	{
		i = 0;
		while(i < par->tokenY)
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
	return (0);
}

/*
int a = 0;
int b = 0;
while (b < par->sizeY)
{
	a = 0;
	while (a < par->sizeX)
	{
		ft_putchar_fd(par->map[b][a], 2);
		a++;
	}
	ft_putstr_fd("\n", 2);
	b++;
}*/
