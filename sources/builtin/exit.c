/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:22:07 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/05 15:52:13 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	exit_builtin(t_command *cmd, t_mini *mini)
{
	int	exit_code;

	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd->full_cmd[1] && !is_numeric(cmd->full_cmd[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
		mini->g_status = 255;
		return (1);
	}
	else if (cmd->full_cmd[1])
	{
		exit_code = ft_atoi(cmd->full_cmd[1]);
		if (exit_code < 0 || exit_code > 255)
			exit_code = exit_code % 256;
		mini->g_status = (int)exit_code;
	}
	else
		mini->g_status = 0;
	m_exit_modified("", mini);
	exit(mini->g_status);
}
