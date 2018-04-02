/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:49:42 by jkimmina          #+#    #+#             */
/*   Updated: 2018/03/22 12:37:22 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "input.h"

#include <stdio.h>

int				main(int argc, char **argv)
{
	unsigned int	*pieces;
	char			***map;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (1);
	}
	pieces = readtet(argv[1]);
	if (!pieces)
	{
		ft_putendl("error");
		return (0);
	}
	map = fi_solve(pieces);
	fi_map_print(map);
	free(pieces);
	return (0);
}
