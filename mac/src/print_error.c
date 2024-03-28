/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:57:28 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:03:33 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(t_game *game, int n)
{
	if (n == 1)
		ft_putendl_fd("Error!\nMap does not exist!", 2);
	else if (n == 2)
		ft_putendl_fd("Error! This program only accepts .ber files!!", 2);
	else if (n == 3)
		ft_putendl_fd("The map should have at least 1 object", 2);
	else if (n == 4)
		ft_putendl_fd("Invalid Map!", 2);
	else if (n == 5)
		ft_putendl_fd("Invalid Path!", 2);
	else if (n == 6)
		ft_putendl_fd("Invalid Char!", 2);
	else if (n == 7)
		ft_putendl_fd("The map is not surrounded!", 2);
	else if (n == 8)
		ft_putendl_fd("Unmatch lines length", 2);
	else if (n == 9)
		ft_putendl_fd("The map must have 1 EXIT!", 2);
	else if (n == 10)
		ft_putendl_fd("The map must have 1 starting point", 2);
	else if (n == 11)
		ft_putendl_fd("Map too big", 2);
	destroy_program(game);
}
