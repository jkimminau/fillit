/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:57:12 by jkimmina          #+#    #+#             */
/*   Updated: 2018/03/21 21:12:34 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "fillit.h"

int					getsize(char *filename);
int					isvalid(unsigned int num);
unsigned int		cleantet(int tet);
unsigned int		newtet(char *tet);
unsigned int		*readtet(char *filename);

#endif
