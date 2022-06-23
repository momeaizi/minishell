/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:00:18 by acouliba          #+#    #+#             */
/*   Updated: 2022/06/23 13:57:48 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	check_builtin(t_command *head, t_var *var)
{
	char	*name;
	int		len;

	name = head->cmd;
	len = ft_strlen(name) + 1;
	if (!ft_strncmp(name, "exit", len))
		exit_builtin(head->args, var);
	else if (!ft_strncmp(name, "unset", ft_strlen(name)))
		unset_builtin(head->args, var);
	else if (!ft_strncmp(name, "export", len))
		export_builtin(head->args, var);
	else if (!ft_strncmp(name, "cd", len))
		cd_builtin(head->args, var);
	else if (!ft_strncmp(name, "pwd", len))
		pwd_builtin(head->args, var);
	else if (!ft_strncmp(name, "env", len))
		env_builtin(head->args, var);
	else if (!ft_strncmp(name, "echo", len))
		echo_builtin(head->args, var);
	else
		return (0);
	return (1);
}

char	**check_cmd(t_var *v, t_command *head)
{
	char	**sp;

	if (head == NULL || head->cmd == NULL)
		return (NULL);
	sp = head->args;
	if (head->error)
		return (head->args);
	if (check_builtin(head, v))
		return (NULL);
	if (head->path)
		return (head->args);
	puterror(head->cmd, "command not found");
	head->error = 127;
	return (head->args);
}
