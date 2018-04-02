/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 20:42:21 by mmoros            #+#    #+#             */
/*   Updated: 2018/03/21 21:04:03 by mmoros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			fi_place_tet(char ***map, unsigned int *tt, int y, char a)
{
	int	i;
	int j;
	int x;
	int tet;

	x = y % map[0][0][0];
	y = y / map[0][0][0];
	i = 4;
	tet = *tt;
	while (--i >= 0)
	{
		j = 4;
		while (--j >= 0)
		{
			if (tet % 2)
				map[1][x + j][y + i] = a;
			tet = tet >> 1;
		}
	}
	*tt += 0x10000;
}

void			fi_remove_tet(char ***map, unsigned int *tt, int x, int y)
{
	int	i;
	int j;
	int tet;

	i = 4;
	*tt -= 0x10000;
	tet = *tt;
	while (--i >= 0)
	{
		j = 4;
		while (--j >= 0)
		{
			if (tet % 2)
				map[1][x + j][y + i] = 0;
			tet = tet >> 1;
		}
	}
}

int				fi_is_solved(unsigned int *list)
{
	while (*list)
		if (!(*list++ & 0x10000))
			return (0);
	return (1);
}

void			fi_42(char ***map, unsigned int *list, int i)
{
	unsigned int	stamp;
	int				x;
	int				y;

	if (!list[i])
		return ;
	y = -1;
	while (++y < map[0][0][0] && !map[0][0][4])
	{
		x = -1;
		while (++x < map[0][0][0] && !map[0][0][4])
		{
			stamp = fi_map_mini(map, x, y);
			if (!(stamp & list[i]))
			{
				fi_place_tet(map, &list[i], x + y * map[0][0][0], 'A' + i);
				fi_42(map, list, i + 1);
				if (fi_is_solved(list))
					map[0][0][4] = 1;
				else
					fi_remove_tet(map, &list[i], x, y);
			}
		}
	}
}

char			***fi_solve(unsigned int *list)
{
	char	***map;
	int		i;

	i = 0;
	while (list[i])
		i++;
	map = fi_map_build(i);
	fi_42(map, list, 0);
	while (!map[0][0][4])
	{
		fi_map_grow(map);
		fi_42(map, list, 0);
	}
	return (map);
}
