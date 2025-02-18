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

void send_bits(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while(str[i] != '\0')
	{
		j = 7;
		c = str[i];
		while(j--)
		{
			if (c >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(111);
		}
		i++;
	}
	j = 7;
	while(j--)
	{
		kill(pid, SIGUSR2);
		usleep(111);
	}
}
int main(int count, char **str)
{
	if (count < 3)
	{
    	write(1, "Something wrong!", 16);
    	return (1);
	}
	send_bits(ft_atoi(str[1]), str[2]);
}
