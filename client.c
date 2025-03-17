/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakdil <sakdil@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:25:46 by sakdil            #+#    #+#             */
/*   Updated: 2025/03/17 21:18:10 by sakdil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	send_bits(int pid, char *str)
{
	int		i;
	int		count;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		count = 7;
		c = str[i];
		while (count--)
		{
			if (c >> count & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			pause ();
		}
		i++;
	}
}

void	handle_ack(int signum)
{
	(void)signum;
}

int	main(int count, char **str)
{
	if (count < 3)
	{
		write(1, "Something wrong!", 16);
		return (1);
	}
	signal(SIGUSR2, handle_ack);
	send_bits(ft_atoi(str[1]), str[2]);
}
