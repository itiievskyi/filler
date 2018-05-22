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
	if (par->step == 2)
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
	if (get_next_line(0, &par->line) > 0)
		{
//		ft_putstr_fd("HELLO #-1\n", 2);
		if (par->step++ == 0 && ft_strncmp("$$$", par->line, 3) == 0)
		{
			if (par->line[10] - '0' == '2')
				par->player = 'X';
		}
	while (get_next_line(0, &par->line) > 0)
/*	{
		ft_putstr_fd("HELLO #-1\n", 2);
		if (par->step++ == 0 && ft_strncmp("$$$", par->line, 3) == 0)
		{
			if (par->line[10] - '0' == '2')
				par->player = 'X';
		}
*/		if (ft_strncmp("Plateau", par->line, 7) == 0)
		{
			ft_putstr_fd("HELLO #2\n", 2);
			read_map(par, 8, 0);
		}
//		get_next_line(0, &par->line);
		if (ft_strncmp("Piece", par->line, 5) == 0)
		{
			ft_putstr_fd("HELLO #3\n", 2);
			read_token(par, 6);
			solve_filler(par);
		}
		ft_printf("%d %d\n", par->retY, par->retX);
	}
	return (0);
}



/*	ft_printf("%d %d\n", a, a);
	a += 1;
	ft_printf("%d\t%d\t%d\t%d\n", par->sizeY, par->sizeX, par->tokenY, par->tokenX);
	i = 0;
	while(i < par->sizeY)
	{
		ft_printf("%s\n", par->map[i]);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while(i < par->tokenY)
	{
		ft_printf("%s\n", par->token[i]);
		i++;
	}*/
