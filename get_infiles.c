/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:49:58 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/14 15:34:19 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_infiles(t_command *cmds, char **env)
{
	char	*infile;
	int		i;
	int		fd;

	fd = -1;
	while (cmds)
	{
		i = -1;
		while (cmds->tokens->tokens[++i])
		{
			if (i && !ft_strcmp("<", cmds->tokens->tokens[i - 1]))
			{
				infile = remove_quotes(\
				expand_var(ft_strdup(cmds->tokens->tokens[i]), env, 0));
				fd = open(infile, O_RDONLY);
				if (fd == -1 || access(cmds->tokens->tokens[i], F_OK))
				{
					cmds->should_execute = 0;
					puterror(cmds->tokens->tokens[i], strerror(errno));
				}
				if (i > cmds->tokens->index && fd != -1)
				{
					if (cmds->input != 0)
						close(cmds->input);
					cmds->input = fd;
				}
				if (fd != -1)
					close(fd);
				free(infile);
			}
		}
		cmds = cmds->next;
	}
}
