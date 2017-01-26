/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:09:30 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/26 13:30:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>

int				is_fatal_signal(int signal)
{
	int const	nb_signals = 19;
	int	const	fatal_signals[] = {
		SIGABRT, SIGALRM, SIGBUS, SIGFPE, SIGHUP, SIGILL, SIGINT, SIGKILL,
		SIGPIPE, SIGPROF, SIGQUIT, SIGSEGV, SIGSYS, SIGTERM, SIGTRAP, SIGVTALRM,
		SIGXCPU, SIGXFSZ,
	};
	int			i;

	i = 0;
	while (i < nb_signals)
	{
		if (fatal_signals[i] == signal)
			return (1);
		i += 1;
	}
	return (0);
}

char			*signal_messages(int i)
{
	static char *const msg[] = {
		"Segmentation Fault", "Bus Error", "Abort", "Alarm", "EMT Instruction",
		"Floating Point Exception", "Hangup", "Illegal Instruction",
		"Killed", "Profile Signal", "Quit", "Stopped", "Invalid System Call",
		"Terminated", "Trace Trap", "User Defined Signal 1",
		"User Defined Signal 2", "Virtual Time Alarm", "CPU Limit Exceeded",
	};

	return (msg[i]);
}

char			*get_signal_msg(int signal)
{
	int			i;
	int const	sig[] = { SIGSEGV, SIGBUS, SIGABRT, SIGALRM, SIGEMT, SIGFPE,
		SIGHUP, SIGILL, SIGKILL, SIGPROF, SIGQUIT, SIGSTOP, SIGSYS, SIGTERM,
		SIGTRAP, SIGUSR1, SIGUSR2, SIGVTALRM, SIGXCPU
	};
	int const	nb_sig = 19;

	i = 0;
	while (i < nb_sig)
	{
		if (sig[i] == signal)
			return (signal_messages(i));
		i += 1;
	}
	return (NULL);
}

void			signal_handle(int signal, char *cmd)
{
	char *msg;

	msg = get_signal_msg(signal);
	if (msg)
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putstr_fd(get_signal_msg(signal), 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(cmd, 2);
	}
}

int				check_for_signal(int status, char *cmd)
{
	int		sig;

	sig = 1;
	if (WIFSIGNALED(status))
		while (sig <= MAXSIGNALS)
		{
			if (WTERMSIG(status) == sig)
				signal_handle(sig, cmd);
			sig += 1;
		}
	return (0);
}
