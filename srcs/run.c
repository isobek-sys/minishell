/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:01:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/07 16:33:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			run_minishell(t_minishell *s)
{
	char	**bin_paths;
	int		status;
	pid_t	pid;

	bin_paths = s->bin_paths;
	if ((pid = fork()) == -1)
		put_error("ERROR", "fork");
	if (pid == 0 && execve(*bin_paths, s->argv, s->env))
		return (put_error("ERROR", "execve"));
	else
		wait(&status);
	return (1);
}
