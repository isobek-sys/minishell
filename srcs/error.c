/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:51:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/03 13:39:27 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		error_command_not_found(t_minishell *s)
{
	if (s->argv && *(s->argv))
		ft_printf("minishell: %s: command not found\n", *(s->argv));
	return (0);
}

int		error_is_dir(t_minishell *s)
{
	ft_printf("minishell: %s: is directory\n", s->bin_path);
	return (0);
}

int		error_no_such_file_or_directory(t_minishell *s)
{
	ft_printf("minishell: %s: no such file of directory\n", s->bin_path);
	return (0);
}
