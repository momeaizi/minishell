/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:45:00 by acouliba          #+#    #+#             */
/*   Updated: 2022/06/21 18:01:23 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	echo_builtin(char **cmd, t_var *v)
{
	int		i;
	t_bool	arg;

	i = 1;
	arg = false;
	if (cmd[i] && ft_strncmp("-n", cmd[i], 2) == 0)
	{
		arg = true;
		i++;
	}
	while (cmd[i])
	{
		if (cmd[i + 1] == 0)
		{
			ft_putstr_fd(cmd[i], v->out);
		}
		else
		{
			ft_putstr_fd(cmd[i], v->out);
			ft_putstr_fd(" ", v->out);
		}
		i++;
	}
	if (arg == false)
		ft_putstr_fd("\n", v->out);
}
