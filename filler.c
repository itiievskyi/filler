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
/*
static void	first_init(t_filler *par, int x, int y)
{
	if (x == y && par->line)
		ft_printf("0 0\n");
}
*//*
static void	write_str(t_filler *par)
{
	char	ch;
	int		i;

	i = 0;
	par->line = (char*)malloc(sizeof(char) * 2);
	while (read(0, &ch, 1) > 0)
	{
		par->line[i] = (char)malloc(sizeof(char) * 1);
		par->line[i] = ch;
		i++;
	}
	par->line[i] = '\0';
}
*/

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
/*
static void	first_parse(t_filler *par, char *line)
{
	int	i;
	int x;

	i = 8;
	x = 0;
	if (get_next_line(0, &line) > 0 && ft_strncmp("$$$", line, 3) == 0)
		par->player = line[10] - '0';
	else if (ft_strncmp("Plateau", line, 7) == 0)
	{
		par->sizeY = ft_atoi(&line[i]);
		while(ft_isdigit(line[i]))
			i++;
		par->sizeX = ft_atoi(&line[i + 1]);
	}
}
*/
int			main(void)
{
	t_filler	*par;
	char		*line;
	int i;

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
			while(par->sizeY-- >= 0)
				get_next_line(0, &line);
		}
		if (ft_strncmp("Piece", line, 5) == 0)
		{
			i = 6;
			par->tokenY = ft_atoi(&line[i]);
			while(ft_isdigit(line[i]))
				i++;
			par->tokenX = ft_atoi(&line[i + 1]);
			while(par->tokenY-- > 0)
				get_next_line(0, &line);
		}
		ft_printf("0 0\n");
	}
	return (0);
}
