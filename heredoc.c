/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:47:57 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/05 18:08:25 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	is_there_any_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\"' || str[i] == '\'')
			return (1);
	return (0);
}

void	herdoc_read(int fd, char *limiter, char should_expand, char should_write, char **env)
{
    char    *line;
    
    while (1)
    {
        line = readline("> ");
        if (!ft_strcmp(limiter, line))
            break ;
		if (should_expand)
			line = expand_var(line, env, 1);
		if (should_write)
        	write(fd, line, ft_strlen(line));
		free(line);
    }
}

void    heredoc(t_command *cmds, char **env)
{
    int			i;
	t_command	*tmp;

	tmp = cmds;
	cmds->tokens->index = -1;
	while (tmp)
	{
		i = -1;
		while (tmp->tokens->tokens[++i])
		{
			if (i > 1 && !ft_strcmp("<<", tmp->tokens->tokens[i - 1]) && !redirect(tmp->tokens->tokens[i]) && !redirect(tmp->tokens->tokens[i - 2]))
			{
				tmp->tokens->should_expand = !is_there_any_quote(tmp->tokens->tokens[i]);
				tmp->tokens->limiters = ft_realloc(tmp->tokens->limiters, remove_quotes(tmp->tokens->tokens[i]));
				tmp->tokens->index = i;
			}
		}
		tmp = tmp->next;
	}
	tmp = cmds;
	while (tmp)
	{
		i = -1;
		while (tmp->tokens->limiters[++i])
		{
			if (!tmp->tokens->limiters[i + 1])
				herdoc_read(1, tmp->tokens->limiters[i], tmp->tokens->should_expand, 1, env);
			else
				herdoc_read(1, tmp->tokens->limiters[i], tmp->tokens->should_expand, 0, env);
		}
		tmp = tmp->next;
	}
}

