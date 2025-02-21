#include "minitalk.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write (1, &c, 1);
	}
}
void	handle_signal(int signal_type)
{
	static char	str;
	static int	count;

	if (signal_type == SIGUSR1)
		str = str | 1;
	if (++count == 7)
	{
		count = 0;
		if (!str)
			write(1, "\n", 1);
		write(1, &str, 1);
		str = 0;
	}
	else
		str = str << 1;
}
int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
}
