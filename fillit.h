/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:51:13 by jkimmina          #+#    #+#             */
/*   Updated: 2018/03/21 17:14:31 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFSIZE 4096

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

void			fi_map_pop(char ***map, int size, int pieces);
char			***fi_map_build(int pieces);
void			fi_map_grow(char ***map);
char			***fi_solve(unsigned int *list);
unsigned int	fi_map_mini(char ***map, int x, int y);
void			fi_map_print(char ***map);

#endif
