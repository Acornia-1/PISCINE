/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   logic.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: alpaz-pr <alpaz-pr@student.42madrid.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/23 16:00:23 by alpaz-pr         #+#    #+#              */
/*   Updated: 2026/08/23 18:07:49 by alpaz-pr        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_left_partial(int **b, int r, int c, int view)
{
	int	i;
	int	max;
	int	av;

	i = 0;
	av = 0;
	max = 0;
	while (i <= c)
	{
		if (b[r][i] > max)
		{
			max = b[r][i];
			av++;
		}
		i++;
	}
	return (av <= view);
}

int	ft_up_partial(int **b, int r, int c, int view)
{
	int	i;
	int	max;
	int	av;

	i = 0;
	av = 0;
	max = 0;
	while (i <= r)
	{
		if (b[i][c] > max)
		{
			max = b[i][c];
			av++;
		}
		i++;
	}
	return (av <= view);
}

void	ft_6n(int **b, int *view, int size)
{
	int	i;
	int	pos;
	int	stab;

	stab = size * 4;
	i = 0;
	while (i < stab)
	{
		if (view[i] == size)
		{
			pos = i % size;
			if ((i / size) == 0)
				b[0][pos] = 1;
			if ((i / size) == 1)
				b[size - 1][pos] = 1;
			if ((i / size) == 2)
				b[pos][0] = 1;
			if ((i / size) == 3)
				b[pos][size - 1] = 1;
		}
		i++;
	}
}

void	ft_1n(int **b, int *view, int size)
{
	int	i;
	int	pos;
	int	stab;

	stab = size * 4;
	i = 0;
	while (i < stab)
	{
		if (view[i] == 1)
		{
			pos = i % size;
			if ((i / size) == 0)
				b[0][pos] = size;
			if ((i / size) == 1)
				b[size - 1][pos] = size;
			if ((i / size) == 2)
				b[pos][0] = size;
			if ((i / size) == 3)
				b[pos][size - 1] = size;
		}
		i++;
	}
}

void	ft_n(int **b, int *view, int size)
{
	ft_1n(b, view, size);
	ft_6n(b, view, size);
}
