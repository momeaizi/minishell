/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:39:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/05 21:42:33 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_command *commands, char **env)
{
	int	i;
	t_command	*tmp;

	heredoc(commands, env);
	get_infiles(commands);
	get_outfiles(commands);
	get_cmds(commands, env);
	tmp = commands;
	while (tmp)
	{
		i = -1;
		printf("%s\n", tmp->command_path);
		while (tmp->command_args[++i])
			printf(" %s\n", tmp->command_args[i]);
		tmp = tmp->next;
	}
}