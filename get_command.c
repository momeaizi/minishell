/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:07:05 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 20:58:34 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect(char *token)
{
	if (ft_strcmp("<", token))
		if (ft_strcmp(">", token))
			if (ft_strcmp(">>", token))
				if (ft_strcmp("<<", token))
					return (0);
	return (1);
}

void	get_command(t_command *commands, char **env)
{
	int			i;

	while (commands)
	{
		i = -1;
		while (commands->tokens->tokens[++i])
		{
			if (!redirect(commands->tokens->tokens[i]) && ((i && !redirect(commands->tokens->tokens[i - 1])) || !i))
			{
				if (!commands->command_name)
					commands->command_name = expand_var(commands->tokens->tokens[i], env, 0);
				else
					commands->command_args = ft_realloc(commands->command_args, expand_var(commands->tokens->tokens[i], env, 0));
			}
		}
		commands = commands->next;
	}
}
