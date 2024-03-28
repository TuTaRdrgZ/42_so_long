/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:47:58 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:29:54 by bautrodr         ###   ########.fr       */
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

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.closed_door);
	mlx_destroy_image(game->mlx, game->textures.opened_door);
	mlx_destroy_image(game->mlx, game->textures.floor);
	mlx_destroy_image(game->mlx, game->textures.wall);
	mlx_destroy_image(game->mlx, game->player.player_up);
	mlx_destroy_image(game->mlx, game->player.player_down);
	mlx_destroy_image(game->mlx, game->player.player_right);
	mlx_destroy_image(game->mlx, game->player.player_left);
}

int	destroy_program(t_game *game)
{
	if (game->coins == game->score && game->score > 0)
		ft_putendl_fd("congrats u won", 1);
	mlx_clear_window(game->mlx, game->window);
	if (game->map)
	{
		free_map(game);
		free_textures(game);
	}
	if (game->mlx && game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		free(game->mlx);
	free(game);
	exit(0);
}
