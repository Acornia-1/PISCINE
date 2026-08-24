/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 11:31:39 by acornia           #+#    #+#             */
/*   Updated: 2026/08/16 12:55:20 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int w);

static void	print_char(int i, int j, int x, int y)
{
	if (j == 0)
	{
		if (i == 0)
			ft_write('A');
		else if (i == x - 1)
			ft_write('C');
		else
			ft_write('B');
	}
	else if (j < y -1)
	{
		if (i == 0 || i == x - 1)
			ft_write('B');
		else
			ft_write(' ');
	}
	else
	{
		if (i == 0)
			ft_write('C');
		else if (i == x - 1)
			ft_write('A');
		else
			ft_write('B');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			print_char(i, j, x, y);
			i++;
		}
		ft_write('\n');
		j++;
	}
}
