/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:19:06 by acornia           #+#    #+#             */
/*   Updated: 2026/08/13 17:43:00 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	answer;

	if (n < 0)
	{
		answer = 'N';
		write(1, &answer, 1);
	}
	else
	{
		answer = 'P';
		write(1, &answer, 1);
	}
}
/*
int main(void)
{
	ft_is_negative(-5);
	ft_is_negative(0);
	ft_is_negative(5);
	return(0);
}
*/
