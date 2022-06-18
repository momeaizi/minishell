/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:16 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/18 15:35:33 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleaning(t_command **cmds, int ***pipes, char close_pipe)
{
	t_command	*tmp;

	tmp = *cmds;
	if (close_pipe)
		close_all(ft_lstsize(*cmds), pipes);
	clear_tokens(&tmp);
	ft_lstclear(cmds);
}

void	exe(t_command *tmp, char **env)
{
	int	id;

	while (tmp)
	{
		id = fork();
		if (!id)
		{
			dup2(tmp->input, 0);
			dup2(tmp->output, 1);
			if (tmp->input != 0)
				close(tmp->input);
			if (tmp->output != 1)
				close(tmp->output);
			if (tmp->should_execute)
				if (execve(tmp->command_path, tmp->command_args, env) == -1)
					exit (1/*puterror(tmp->command_name, strerror(errno))*/);
			exit (2);
		}
		wait(NULL);
		if (tmp->input != 0)
			close(tmp->input);
		if (tmp->output != 1)
			close(tmp->output);
		tmp = tmp->next;
	}
}

int main(int ac, char **av, char **env)
{
	char		*line;
	int			**pipes;
	t_command	*head;

	if (ac > 1 || av[1])
		return (1);
	while (1)
	{
		head  = NULL;
		line = readline("Bash1.0>-$");
		printf("\033[0;37m");
		if (check_quotes(line) && ft_strlen(line))
		{
			head = tokenizer(line);
			if (check_redirect(head))
			{
				parser(head, &pipes,env);
				exe(head, env);
				cleaning(&head, &pipes, 1);
			}
			else
				cleaning(&head, &pipes, 0);
		}
		free(line);
		system("leaks minishell");
	}
	return (0);
}

