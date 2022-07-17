/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 08:41:00 by vgonnot           #+#    #+#             */
/*   Updated: 2022/07/17 20:14:27 by vgonnot          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

void ft_convert(int argc, char **argv, int *error, int tab[4][4])
{
	int	i;
	int	j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	if (argc != 2)
	{
		*error = 1;
		return;
	}
	while (argv[1][i])
	{
		if (((argv[1][i] < '1' || argv[1][i] > '4') && argv[1][i] != ' ')
				|| (argv[1][i] == ' ' && argv[1][i - 1] == ' ') || i > 31) 
		{
			*error = 1;
			return;
		}
		if (j == 4)
		{
			k++;
			j = 0;	
		}
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			tab[k][j] = argv[1][i] - '0';
			j++;
		}
		i++;
	}
	if (i != 31)
		*error = 1;
}

void set_array(int tab[4][4][4])
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 1;
	while (i < 4)
	{
		while (j < 4)
		{
			while (k < 5)
			{
				tab[i][j][k -1] = k;
				k++;
			}
			k = 1;
			j++;
		}
		j = 0;
		i++;
	}
}

void number_one (int tab[4][4][4], int position, int place)
{
	int	i;

	i = 0;
	if (place == 3 || place == 0 || position == 3 || position == 0)
		while (i < 4)
		{
			if (tab[place][position][i] != 4)
				tab[place][position][i] = 0;
			i++;
		}

}

void check_value (int tab[4][4][4], int value_beginning[4][4])
{
	int i;
	int position;

	set_array(tab);
	i = 0;
	position = 0;
	while (i < 4)
	{
		while (position < 4)
		{
			if (value_beginning[i][position] == 4)
				number_four(tab, i, position);
			if (value_beginning[i][position] == 1)
				number_one(tab, i, position);
			position++;
		}
		position = 0;
		i++;
	}
}
