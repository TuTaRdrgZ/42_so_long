/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:35:40 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:22:02 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C'
				&& game->map[i][j] != 'E')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_first_and_last(t_game *game)
{
	int	j;

	j = 0;
	while (game->map[0][j] != '\0' && game->map[0][j] != '\n')
	{
		if (game->map[0][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (game->map[game->map_rows][j] != '\0'
		&& game->map[game->map_rows][j] != '\n')
	{
		if (game->map[game->map_rows][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

static int	check_surroundings(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_col - 2] != '1')
			return (-1);
		i++;
	}
	if (check_first_and_last(game) == -1)
		return (-1);
	return (0);
}

int	more_checks(t_game *game, char *map)
{
	if (check_filetype(map) == -1)
		print_error(game, 2);
	check_repeated(game, 0, 0);
	if (same_length(game) == -1)
		print_error(game, 8);
	if (check_chars(game) == -1)
		print_error(game, 6);
	if (check_surroundings(game) == -1)
		print_error(game, 7);
	return (0);
}

int	check_map(t_game *game, char *map)
{
	int	lines;
	int	col;

	lines = 0;
	col = 0;
	while (game->map[lines])
		lines++;
	while (game->map[0][col])
		col++;
	if (col > 81 || lines > 43)
		print_error(game, 11);
	game->map_col = col;
	game->map_rows = lines - 1;
	if (more_checks(game, map) == -1)
	{
		free_map(game);
		return (-1);
	}
	return (0);
}
