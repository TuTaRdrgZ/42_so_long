/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:03:01 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 10:34:58 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 53)
		destroy_program(game);
	if (keycode == 119 || keycode == 13)
		update_player_pos(game, keycode);
	if (keycode == 115 || keycode == 1)
		update_player_pos(game, keycode);
	if (keycode == 97 || keycode == 0)
		update_player_pos(game, keycode);
	if (keycode == 100 || keycode == 2)
		update_player_pos(game, keycode);
	return (0);
}
