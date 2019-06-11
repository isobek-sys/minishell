/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:40:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/11 13:32:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//may be delete 
int		check_builtins(t_minishell *s)
{
	if (!ft_strcmp(*(s->argv), "echo") && !echo(s))
		return (1);
	if (!ft_strcmp(*(s->argv), "cd") && !cd(s))
		return (1);
	if (!ft_strcmp(*(s->argv), "setenv"))
		return (1);
	if (!ft_strcmp(*(s->argv), "unsetenv"))
		return (1);
	if (!ft_strcmp(*(s->argv), "env") && !env(s))
		return (1);
	return (0);
}
