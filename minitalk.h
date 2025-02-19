#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

void send_bits(int pid, char *str);
void	handle_signal(int signal_type);

#endif