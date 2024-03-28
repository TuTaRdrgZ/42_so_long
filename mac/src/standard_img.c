/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:10:25 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:14:02 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_img(t_game *game)
{
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->width, &game->height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/grass.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx,
			"textures/coin_bg.xpm", &game->width, &game->height);
	game->textures.closed_door = mlx_xpm_file_to_image(game->mlx,
			"textures/closed_door_bg.xpm", &game->width, &game->height);
	game->textures.opened_door = mlx_xpm_file_to_image(game->mlx,
			"textures/opened_door_bg.xpm", &game->width, &game->height);
	game->player.player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/looking_up_bg.xpm", &game->width, &game->height);
	game->player.player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/looking_down_bg.xpm", &game->width, &game->height);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/looking_left_bg.xpm", &game->width, &game->height);
	game->player.player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/looking_right_bg.xpm", &game->width, &game->height);
}
