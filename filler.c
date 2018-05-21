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

static void	init_par(t_filler *par)
{
	par->line = NULL;
	par->map = NULL;
	par->token = NULL;
	par->sizeY = 0;
	par->sizeX = 0;
	par->player = 0;
	par->curX = 0;
	par->curY = 0;
	par->retX = 0;
	par->retY = 0;
	par->tokenX = 0;
	par->tokenY = 0;
	par->error = 56;
	par->step = 0;
}

int			main(void)
{
	t_filler	*par;
	char		*line;
	int i;
	int a = 0;

	init_par((par = (t_filler*)malloc(sizeof(t_filler))));
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("$$$", line, 3) == 0)
			par->player = line[10] - '0';
		if (ft_strncmp("Plateau", line, 7) == 0)
		{
			i = 8;
			par->sizeY = ft_atoi(&line[i]);
			while(ft_isdigit(line[i]))
				i++;
			par->sizeX = ft_atoi(&line[i + 1]);
			i = 0;
			while(i++ < par->sizeY)
				get_next_line(0, &line);
		}
		if (ft_strncmp("Piece", line, 5) == 0)
		{
			i = 6;
			par->tokenY = ft_atoi(&line[i]);
			while(ft_isdigit(line[i]))
				i++;
			par->tokenX = ft_atoi(&line[i + 1]);
			i = 0;
			while(i++ < par->tokenY)
				get_next_line(0, &line);
		}
		ft_printf("%d %d\n", a, a);
		a += 1;
	}
//	ft_printf("%d\t%d\t%d\t%d\n", par->sizeY, par->sizeX, par->tokenY, par->tokenX);
	return (0);
}
