/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:35:52 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:29:19 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_game *game, int lines, char *map)
{
	int	file;
	int	i;

	i = 1;
	file = open(map, O_RDWR);
	game->map = ft_calloc(sizeof(char *), (lines + 1));
	if (!game->map)
		return ;
	game->map[0] = get_next_line(file);
	while (i < lines)
	{
		game->map[i] = get_next_line(file);
		i++;
	}
	if (check_map(game, map) == -1)
		print_error(game, 4);
	valid_path(game, 0, 0, 0);
	close(file);
}

static void	open_or_closed(t_game *game, int i, int index)
{
	if (game->coins == game->score)
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.opened_door, i * 32, (index * 32));
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->textures.closed_door, i * 32, (index * 32));
}

void	print_map(char *line, t_game *game, int index)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.wall, i * 32, (index * 32));
		else if (line[i] == '0')
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.floor, i * 32, (index * 32));
		else if (line[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->window,
				game->textures.coin, i * 32, (index * 32));
		else if (line[i] == 'E')
			open_or_closed(game, i, index);
		else if (line[i] == 'P')
			print_player(game, i, index);
		i++;
	}
}

void	add_graphics(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		print_map(game->map[i], game, i);
		i++;
	}
}

int	init_map(char *map, t_game *game, int linecount)
{
	int		file;
	char	*line;

	line = NULL;
	file = open(map, O_RDWR);
	if (file == -1)
		print_error(game, 1);
	line = get_next_line(file);
	if (line == NULL)
		exit(EXIT_FAILURE);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		linecount++;
	}
	close(file);
	fill_map(game, linecount, map);
	free(line);
	return (0);
}
