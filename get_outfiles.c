/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:33:45 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/12 20:05:35 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    get_outfiles(t_command *cmds, char **env)
{
    int		i;
    int		fd;
	char	*file_name;

	fd = -1;
	while (cmds)
	{
		i = -1;
		while (cmds->tokens->tokens[++i] && cmds->should_execute)
		{
			if (i && (!ft_strcmp(">", cmds->tokens->tokens[i - 1]) || !ft_strcmp(">>", cmds->tokens->tokens[i - 1])))
			{
				file_name = expand_var(remove_quotes(ft_strdup(cmds->tokens->tokens[i])), env, 0);
				if (!ft_strlen(file_name))
				{
					puterror(cmds->tokens->tokens[i], "ambiguous redirect");
					cmds->should_execute = 0;
				}
				else
				{
					if (cmds->output != 1)
						close(cmds->output);
					if (!ft_strcmp(">", cmds->tokens->tokens[i - 1]))
						fd = open(file_name, O_RDWR | O_CREAT, 0644);
					else
						fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, 0644);
					if (fd == -1)
					{
						puterror(cmds->tokens->tokens[i], strerror(errno));
						cmds->should_execute = 0;
					}
					cmds->output = fd;
				}
			}
		}
		cmds = cmds->next;
	}
}