/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:09:30 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 13:47:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>

void			signal_handle(int signal)
{
	void (*const handles[])(int) = {
		sighup, sigint, sigquit, sigill, sigtrap, sigabrt, sigemt, sigfpe,
		sigkill, sigbus, sigsegv, sigsys, sigpipe, sigalrm, sigterm, sigurg,
		sigstop, sigtstp, sigcont, sigchld, sigttin, sigttou, sigio, sigxcpu,
		sigxfsz, sigvtalrm, sigprof, sigwinch, siginfo, sigusr1, sigusr2
	};

	(handles[signal - 1])(signal);
}

int				check_for_signal(int status)
{
	int		sig;

	sig = 1;
	if (WIFSIGNALED(status))
		while (sig <= MAXSIGNALS)
		{
			if (WTERMSIG(status) == sig)
				signal_handle(sig);
			sig += 1;
		}
	return (0);
}
