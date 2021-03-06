/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:27:46 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/29 11:27:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include <unistd.h>

static void	print_map(char *line, int i)
{
	while (line[i] != ' ')
		i++;
	while (line[++i] != '\0')
	{
		if (line[i] == '.')
			write(1, ".", 1);
		if (line[i] == 'O')
			ft_printf(ANSI_COLOR_GREEN "■" ANSI_COLOR_RESET);
		if (line[i] == 'X')
			ft_printf(ANSI_COLOR_RED "■" ANSI_COLOR_RESET);
		if (line[i] == 'x' || line[i] == 'o')
			ft_printf(ANSI_COLOR_YELLOW "■" ANSI_COLOR_RESET);
	}
	write(1, "\n", 1);
	free(line);
}

static void	check_finish(char *line, int o, int x)
{
	if (ft_strstr(line, "error"))
	{
		free(line);
		get_next_line(0, &line);
	}
	if (ft_strstr(line, "== "))
	{
		o = ft_atoi(&line[10]);
		free(line);
		get_next_line(0, &line);
		x = ft_atoi(&line[10]);
		free(line);
		if (o > x)
			ft_printf(ANSI_COLOR_GREEN "\nPlayer #1 WON %d : %d\n"\
			ANSI_COLOR_RESET, o, x);
		else if (x > 0)
			ft_printf(ANSI_COLOR_RED "\nPlayer #2 WON %d : %d\n"\
			ANSI_COLOR_RESET, x, o);
		else
			ft_printf(ANSI_COLOR_YELLOW "\nDRAW!\n" ANSI_COLOR_RESET);
		exit(1);
	}
	else
		free(line);
}

static void	get_full_header(char *line, char **header)
{
	char	*temp;

	temp = NULL;
	temp = ft_strjoin(*header, "\t\tPlayer #2: ");
	free(*header);
	*header = ft_strjoin(temp, &line[9]);
	free(temp);
}

static void	check_quiet(char *line, char **header)
{
	system("clear");
	while (get_next_line(0, &line) > 0 && !ft_strstr(line, "launched"))
		free(line);
	*header = ft_strjoin("Player #1: ", &line[9]);
	free(line);
	if (get_next_line(0, &line) > 0 && ft_strstr(line, "launched"))
	{
		get_full_header(line, header);
		free(line);
		ft_printf(ANSI_COLOR_MAGENTA "\n%s\n" ANSI_COLOR_RESET, *header);
		if (get_next_line(0, &line) > 0 && ft_strstr(line, "abort"))
		{
			ft_printf("%s\n", line);
			free(line);
			free(*header);
			exit(1);
		}
		else
			check_finish(line, 0, 0);
	}
	else
		free(line);
}

int			main(void)
{
	char	*line;
	char	*header;

	line = NULL;
	check_quiet(line, &header);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "launched"))
			get_full_header(line, &header);
		free(line);
		while (get_next_line(0, &line) > 0 && !ft_strstr(line, "000 "))
			free(line);
		ft_printf(ANSI_COLOR_MAGENTA "\n%s\n" ANSI_COLOR_RESET, header);
		print_map(line, 0);
		while (get_next_line(0, &line) > 0 && !ft_strstr(line, "Piece"))
			print_map(line, 0);
		free(line);
		while (get_next_line(0, &line) > 0 && !ft_strstr(line, "Plateau"))
			check_finish(line, 0, 0);
		if (ft_strstr(line, "Plateau"))
			free(line);
		usleep(200000);
		system("clear");
	}
	return (0);
}
