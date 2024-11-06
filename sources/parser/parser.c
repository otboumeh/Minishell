/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:37:07 by dangonz3          #+#    #+#             */
/*   Updated: 2024/11/04 19:48:13 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parser(t_mini *m)
{
	int	i;

	i = 0;
	while (m->tokens[i])
	{
		if (!expand_var(i, m))
			return (0);
		i++;
	}
	if (!token_check(m))
		return (0);
	if (!t_commands(m))
		return (0);
	if (!open_files(m))
		return (0);
	if (!pre_check_commands(m))
		return (0);
	if (!check_commands(m))
		return (0);
	if (!delete_quotes(m))
		return (0);
	return (1);
}
