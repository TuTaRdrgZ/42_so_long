/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:26:59 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:27:20 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_player(t_game *game, int width, int height)
{
	if (game->player_pos == RIGHT || game->moves == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_right, 0 + width * 32, 0 + (height * 32));
	else if (game->player_pos == LEFT)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_left, 0 + width * 32, 0 + (height * 32));
	else if (game->player_pos == UP)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_up, 0 + width * 32, 0 + (height * 32));
	else if (game->player_pos == DOWN)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_down, 0 + width * 32, 0 + (height * 32));
	game->x = width;
	game->y = height;
}
