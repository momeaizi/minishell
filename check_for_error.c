/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:05:19 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/02 16:37:56 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quotes(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (!str[i])
			{
				write(2, "missing quotes!\n", 17);
				return (0);
			}
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (!str[i])
			{
				write(2, "missing quotes!\n", 17);
				return (0);
			}
		}
	}
	return (1);
}


void	check_redirect(t_command *commands)
{
    int	i;

	while (commands)
	{
		i = -1;
		while (commands->tokens->tokens[++i])
		{
			if (i && redirect(commands->tokens->tokens[i]) && redirect(commands->tokens->tokens[i - 1]))
			{
				write(2, "syntax error!\n", 15);
                free(commands->command_name);
				commands->command_name = NULL;
			}
		}
		commands = commands->next;
	}
}