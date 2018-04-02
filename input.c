/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:43:24 by jkimmina          #+#    #+#             */
/*   Updated: 2018/03/29 21:07:39 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int					getsize(char *filename)
{
	int		file;
	int		ret;
	int		num;
	char	buf[21];

	if ((file = open(filename, O_RDONLY)) == -1)
		return (0);
	num = 0;
	while ((ret = read(file, buf, 21)))
	{
		if (num > 26)
			return (-1);
		buf[ret] = '\0';
		num++;
	}
	return (num);
}

unsigned int		cleantet(int tet)
{
	while ((tet & 0xF000) == 0)
		tet = tet << 4;
	while ((tet & 0x8888) == 0)
		tet = tet << 1;
	return (tet);
}

/*char	*cleantet(char *tet)
{
	int i;
	int j;

	while (tet[0] == '.' && tet[5] == '.' &&
			tet[10] == '.' &&  tet[15] == '.')
	{
		j = 0;
		while (j < 3)
		{
			i = -1;
			while (++i < 4)
				tet[j + (i * 5)] = tet[(j + 1) + (i * 5)]
			i++;
		}
		i = 0;
		while (i < 4)
			tet[3 + (i * 5)] = '.';
	}
	while (tet[0] == '.' && tet[1] == '.' &&
			tet[2] == '.' &&  tet[3] == '.')
	{
		i = 0;
		while (i < 3)
		{
			j = -1;
			while (++j < 4)
				tet[(i * 5) + j] = tet[((i + 1) * 5) + j]
			i++;
		}
		j = 0;
		while (j < 4)
			tet[15 + j++] = '.';
	}
	
}*/

int					isvalid(unsigned int num)
{
	if (num == 0xCC00 ||
		num == 0xF000 || num == 0x8888 ||
		num == 0xC600 || num == 0x4C80 ||
		num == 0x6C00 || num == 0x8C40 ||
		num == 0x8C80 || num == 0xE400 || num == 0x4C40 || num == 0x4E00 ||
		num == 0xC880 || num == 0x8E00 || num == 0x44C0 || num == 0xE200 ||
		num == 0x88C0 || num == 0xE800 || num == 0xC440 || num == 0x2E00)
		return (1);
	return (0);
}

/*int					isvalid(char *num)
{
	if (num == "##..\n##..\n....\n...." || 
		num == "####\n....\n....\n...." || 
		num == "#...\n#...\n#...\n#..." ||
		num == "##..\n.##.\n....\n...." || 
		num == ".#..\n##..\n#...\n...." || 
		num == ".##.\n##..\n....\n...." || 
		num == "#...\n##..\n.#..\n...." || 
		num == "#...\n##..\n#...\n...." || 
		num == "###.\n.#..\n....\n...." || 
		num == ".#..\n##..\n.#..\n...." || 
		num == ".#..\n###.\n....\n...." || 
		
		num == 0xC880 || num == 0x8E00 || num == 0x44C0 || num == 0xE200 ||
		num == 0x88C0 || num == 0xE800 || num == 0xC440 || num == 0x2E00)
		return (1);
	return (0);
}*/

unsigned int		newtet(char *tet)
{
	int					i;
	unsigned int		num;

	i = 0;
	num = 0;
	while (tet[i] != '\0')
	{
		if ((i + 1) % 5 != 0 && (tet[i] == '.' || (tet[i] == '#')))
		{
			if (tet[i] == '#')
				num += ft_math_pow(2, (3 - (i % 5)));
		}
		else if ((i + 1) % 5 == 0 && (tet[i] == '\n'))
			num = num << 4;
		else
			return (0);
		i++;
	}
	if (i < 19 || num == 0)
		return (0);
	num = cleantet(num);
	return (isvalid(num) ? num : 0);
}

unsigned int		*readtet(char *filename)
{
	int				file;
	int				ret;
	int				num;
	unsigned int	*pieces;
	char			buf[21];

	if ((num = getsize(filename)) == -1)
		return (0);
	pieces = (unsigned int *)malloc(sizeof(unsigned int) * (num + 1));
	pieces[num] = 0;
	file = open(filename, O_RDONLY);
	num = 0;
	while ((ret = read(file, buf, 20)))
	{
		buf[ret - 1] = '\0';
		if ((pieces[num++] = newtet(buf)) == 0 || buf[0] == '\n')
		{
			close(file);
			free(pieces);
			return (0);
		}
		read(file, buf, 1);
	}
	close(file);
	return (num == 0 || buf[0] == '\n') ? 0 : pieces;
}
