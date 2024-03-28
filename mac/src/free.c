/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:47:58 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:21:35 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_visited(int **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	destroy_program(t_game *game)
{
	if (game->coins == game->score && game->score > 0)
		ft_putendl_fd("congrats u won", 1);
	if (game->map)
		free_map(game);
	if (game->mlx)
		free(game->mlx);
	exit(0);
}
