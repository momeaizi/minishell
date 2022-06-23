/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:33:45 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/23 16:29:08 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	open_outfile(t_command *cmd, char *outfile, int i)
{
	int	fd;

	if (!p_ft_strcmp(">", cmd->tokens->tokens[i - 1]))
		fd = open(outfile, O_RDWR | O_CREAT, 0644);
	else
		fd = open(outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd != -1)
	{
		if (cmd->output != 1)
			close(cmd->output);
		cmd->output = fd;
	}
	else
	{
		puterror(outfile, strerror(errno));
		cmd->error = 1;
	}
}

void	get_outfile(t_command *cmds, char *file, int i)
{
	if (i && (!p_ft_strcmp(">", cmds->tokens->tokens[i - 1]) \
	|| !p_ft_strcmp(">>", cmds->tokens->tokens[i - 1])))
	{
		if (!p_ft_strlen(file))
		{
			puterror(cmds->tokens->tokens[i], "ambiguous redirect");
			cmds->error = 1;
		}
		else
			open_outfile(cmds, file, i);
	}
}
