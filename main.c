/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:36:16 by momeaizi          #+#    #+#             */
/*   Updated: 2022/06/05 21:46:53 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	int 		i;
	t_command	*head;
	t_command	*tmp;
	char		**tokens;
	char	*new;

	head = NULL;
	tokens = NULL;
	// char *str = readline("bash$ ");
	char	*str = malloc(48);
	ft_strlcpy(str, "cat < main.c > outfile1> outfile >> outfile1337", 48);
	if (check_quotes(str))
	{
		head = tokenizer(str);
		parser(head, env);
	}
	dup2(head->input, 0);
	dup2(head->output, 1);
	close(head->input);
	close(head->output);
	execve(head->command_path, head->command_args, env);
	return (0);
}
