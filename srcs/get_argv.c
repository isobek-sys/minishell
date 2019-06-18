/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:07:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/06/17 19:14:13 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**get_argv(char **env)
{
	char	*tmp;
	char	*input;
	char	**argv;

	tmp = read_line();
	input = manage_expansions(tmp, env);
	argv = ft_strsplit(input, ' ');
	if (tmp)
		ft_memdel((void **)&tmp);
	if (input)
		ft_memdel((void **)&input);
	return (argv);
}
