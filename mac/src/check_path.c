/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:37:54 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/19 17:02:58 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_move(t_game *game, int **visited, int row, int col)
{
	return (game->map[row][col] != '1' && !visited[row][col]);
}

void	flood_fill(t_game *game, int row, int col, int **visited)
{
	if (!valid_move(game, visited, row, col) || visited[row][col])
		return ;
	if (game->map[row][col] == 'C')
		game->flood_fill_coins += 1;
	visited[row][col] = 1;
	flood_fill(game, row - 1, col, visited);
	flood_fill(game, row + 1, col, visited);
	flood_fill(game, row, col - 1, visited);
	flood_fill(game, row, col + 1, visited);
}

void	player_position(t_game *game, int i, int *player_col, int *player_row)
{
	int	j;

	j = 0;
	game->flood_fill_coins = 0;
	game->coins = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'P')
		{
			*player_row = i;
			*player_col = j;
			break ;
		}
		j++;
	}
}

void	exit_position(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_y = i;
				game->exit_x = j;
			}
			if (game->map[i][j] == 'C')
				game->coins += 1;
			j++;
		}
		i++;
	}
}

int	valid_path(t_game *game, int i, int p_row, int p_col)
{
	int	**visited;

	visited = ft_calloc(game->map_rows, sizeof(int *));
	while (i < game->map_rows)
	{
		visited[i] = ft_calloc(game->map_col, sizeof(int *));
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		player_position(game, i, &p_col, &p_row);
		i++;
	}
	exit_position(game);
	flood_fill(game, p_row, p_col, visited);
	i = visited[p_row][p_col] && visited[game->exit_y][game->exit_x];
	free_visited(visited, game);
	if (game->flood_fill_coins != game->coins || !i)
		print_error(game, 5);
	if (game->flood_fill_coins == 0)
		print_error(game, 3);
	return (0);
}
