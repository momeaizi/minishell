/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:39:02 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/30 15:44:09 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid(char *str)
{
	if (ft_strcmp("<", str))
		if (ft_strcmp(">", str))
			if (ft_strcmp("<<", str))
				if (ft_strcmp(">>", str))
					return (1);
	printf("minishell: syntax error near unexpected token `%s\'\n", str);
	return (0);
}

void	parser(t_command *commands)
{
	int	i;
	t_command	*tmp;

	tmp = commands;
	while (tmp)
	{
		i = -1;
		while (tmp->tokens->tokens[++i])
		{
			if (!ft_strcmp("<", tmp->tokens->tokens[i]))
				if (is_valid(tmp->tokens->tokens[i + 1]))
					tmp->tokens->infiles = ft_realloc(tmp->tokens->infiles, tmp->tokens->tokens[++i]);
			else if (!ft_strcmp(">", tmp->tokens->tokens[i]))
			{
				if (is_valid(tmp->tokens->tokens[i + 1]))
					tmp->tokens->outfiles = ft_realloc(tmp->tokens->outfiles, tmp->tokens->tokens[++i]);
					tmp->tokens->open_flag = 0;
			}
			else if (!ft_strcmp(">>", tmp->tokens->tokens[i]))
			{
				if (is_valid(tmp->tokens->tokens[i + 1]))
					tmp->tokens->outfiles = ft_realloc(tmp->tokens->outfiles, tmp->tokens->tokens[++i]);
				tmp->tokens->open_flag = 1;
			}
			else if (!ft_strcmp("<<", tmp->tokens->tokens[i]))
				if (is_valid(tmp->tokens->tokens[i + 1]))
					tmp->tokens->heredocs = ft_realloc(tmp->tokens->heredocs, tmp->tokens->tokens[++i]);
			else if (tmp->tokens->command)
				tmp->tokens->arguments = ft_realloc(tmp->tokens->arguments, tmp->tokens->tokens[i]);
			else
				tmp->tokens->command = tmp->tokens->tokens[i];
		}
		tmp = tmp->next;
	}
	tmp = commands;
	while (tmp)
	{
		printf("command : %s\n", tmp->tokens->command);
		i = -1;
		printf("arguments\n");
		while (tmp->tokens->arguments[++i])
			printf("	%s\n", tmp->tokens->arguments[i]);
		i = -1;
		printf("infiles\n");
		while (tmp->tokens->infiles[++i])
			printf("	%s\n", tmp->tokens->infiles[i]);
		i = -1;
		printf("outfiles\n");
		while (tmp->tokens->outfiles[++i])
			printf("	%s\n", tmp->tokens->outfiles[i]);
		i = -1;
		printf("herdocs\n");
		while (tmp->tokens->heredocs[++i])
			printf("	%s\n", tmp->tokens->heredocs[i]);
		printf("//////\n");
		tmp = tmp->next;
	}
}