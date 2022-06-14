/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:49:58 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/14 21:55:45 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_file(t_command *cmd, char *infile, int fd, int i)
{
	if (fd == -1 || access(cmd->tokens->tokens[i], F_OK))
	{
		cmd->should_execute = 0;
		puterror(cmd->tokens->tokens[i], strerror(errno));
	}
	if (i > cmd->tokens->index && fd != -1)
	{
		if (cmd->input != 0)
			close(cmd->input);
		cmd->input = fd;
	}
	if (fd != -1 && fd != cmd->input)
		close(fd);
	free(infile);
}

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
				open_file(cmds, infile, fd, i);
			}
		}
		cmds = cmds->next;
	}
}
