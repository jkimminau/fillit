/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fi_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:33:30 by mmoros            #+#    #+#             */
/*   Updated: 2018/03/21 21:10:05 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			fi_map_pop(char ***map, int size, int pieces)
{
	map[0][0][0] = size;
	map[0][0][1] = 0;
	map[0][0][2] = (size - 2) * (size - 2) - pieces * 4;
	map[0][0][3] = pieces;
	map[0][0][4] = 0;
}

char			***fi_map_build(int pieces)
{
	char	***map;
	char	size;
	int		i;
	int		j;

	size = ft_math_sqrt_f(pieces * 4) + 2;
	if (!(map = (char***)malloc(sizeof(char**) * 2)) ||
		!(map[0] = (char**)malloc(sizeof(char*))) ||
		!(map[0][0] = (char*)malloc(sizeof(char) * 5)) ||
		!(map[1] = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	fi_map_pop(map, size, pieces);
	while (size--)
		if (!(map[1][(int)size] = (char*)malloc(sizeof(char) * map[0][0][0])))
			return (0);
	i = -1;
	while (++i < map[0][0][0] && (j = -1))
		while (++j < map[0][0][0])
			map[1][i][j] = 0;
	map[0][0][0] -= 2;
	return (map);
}

void			fi_map_grow(char ***map)
{
	map[0][0][0]++;
	map[0][0][1] = 0;
	map[0][0][2] = map[0][0][0] * map[0][0][0] - map[0][0][3] * 4;
}

unsigned int	fi_map_mini(char ***map, int x, int y)
{
	unsigned int	mini;
	int				i;
	int				j;

	mini = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			mini = mini << 1;
			if ((x + j) >= map[0][0][0] ||
					(y + i) >= map[0][0][0] ||
					map[1][x + j][y + i])
				mini++;
		}
	}
	return (mini);
}

void			fi_map_print(char ***map)
{
	int i;
	int j;

	i = -1;
	while (++i < map[0][0][0])
	{
		j = -1;
		while (++j < map[0][0][0])
		{
			if (map[1][j][i])
				ft_putchar(map[1][j][i]);
			else
				ft_putchar('.');
		}
		ft_putchar('\n');
	}
}
