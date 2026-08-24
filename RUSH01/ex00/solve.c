/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   solve.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alpaz-pr <alpaz-pr@student.42madrid.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/22 17:25:18 by alpaz-pr         #+#    #+#              */
/*   Updated: 2026/08/23 15:34:25 by alpaz-pr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
/*

"

arriba1 arriba2 arriba3 arriba4 -> 0 - 3
abajo1 abajo2 abajo3 abajo4 -> 4 - 7
izquierda1 izquierda2 izquierda3 izquierda4 -> 8 - 11
derecha1 derecha2 derecha3 derecha4 -> 12 - 15

"

*/

int	ft_up(int **b, int c, int view, int size)
{
	int	i;
	int	max;
	int	av;

	i = 0;
	av = 0;
	max = 0;
	while (i < size)
	{
		if (b[i][c] > max)
		{
			max = b[i][c];
			av++;
		}
		i++;
	}
	return (av == view);
}

int	ft_down(int **b, int c, int view, int size)
{
	int	i;
	int	max;
	int	av;

	i = size - 1;
	av = 0;
	max = 0;
	while (i >= 0)
	{
		if (b[i][c] > max)
		{
			max = b[i][c];
			av++;
		}
		i--;
	}
	return (av == view);
}

int	ft_left(int **b, int r, int view, int size)
{
	int	i;
	int	max;
	int	av;

	i = 0;
	av = 0;
	max = 0;
	while (i < size)
	{
		if (b[r][i] > max)
		{
			max = b[r][i];
			av++;
		}
		i++;
	}
	return (av == view);
}

int	ft_right(int **b, int r, int view, int size)
{
	int	i;
	int	max;
	int	av;

	i = size - 1;
	av = 0;
	max = 0;
	while (i >= 0)
	{
		if (b[r][i] > max)
		{
			max = b[r][i];
			av++;
		}
		i--;
	}
	return (av == view);
}
