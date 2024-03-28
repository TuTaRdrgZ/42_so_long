/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:44:01 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:16:58 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	same_length(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (game->map[i][j])
	{
		j++;
		len++;
	}
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j != len)
			return (-1);
		i++;
	}
	return (0);
}

int	check_filetype(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if ((str[i + 1] == 'b') && str[i + 2] == 'e' && str[i + 3] == 'r'
				&& !str[i + 4])
				return (0);
		}
		i++;
	}
	return (-1);
}

void	check_repeated(t_game *game, int i, int j)
{
	while (i < game->map_rows)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->p_counter++;
			if (game->map[i][j] == 'E')
			{
				game->exit_x = i;
				game->exit_y = j;
				game->e_counter++;
			}
			j++;
		}
		i++;
	}
	if (game->p_counter != 1)
		print_error(game, 10);
	if (game->e_counter != 1)
		print_error(game, 9);
}
