/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgonnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:46:18 by vgonnot           #+#    #+#             */
/*   Updated: 2022/07/17 17:52:36 by vgonnot          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void write_full_line (int tab[4][4][4], int nbr, int way, int position)
{
	int i;
	int j;

	i = 0;
	if (way % 2 == 0)
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (tab[position][i][j] != nbr)
					tab[position][i][j] = 0;
				j++;
			}
			i++;
			nbr--;
		}
	}
	else
	{
		while (i < 4)
		{
			j = 3;
			while (j >= 0)
			{
				if (tab[position][i][j] != i + 1)
					tab[position][i][j] = 0;
				j--;
			}
			i++;
		}
	}
}

void write_full_col(int tab[4][4][4],int nbr, int way, int position)
{
	int i;
	int j;

	i = 0;
	if (way % 2 == 0)
	{
		while (i < 4)
		{
			//printf("%d", i);
			j = 0;
			while (j < 4)
			{
				if (tab[i][position][j] != nbr)
				{
					tab[i][position][j] = 0;
				}
				j++;
			}
			i++;
			nbr--;
		}
	}
	else
	{
		while (i < 4)
		{
			j = 3;
			while (j >= 0)
			{
				if (tab[i][position][j] != i + 1)
					tab[i][position][j] = 0;
				j--;
			}
			i++;
		}
	}
}

void number_four (int tab[4][4][4], int i, int position)
{
	if ( i < 2)
	{
		write_full_col(tab, 4, i, position);
	}
	if (i >= 2)
	{
		write_full_line(tab, 4, i, position);
	}
}
