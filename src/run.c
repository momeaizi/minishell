/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:00:18 by acouliba          #+#    #+#             */
/*   Updated: 2022/06/23 17:40:10 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static int	exe(char *path, t_command *temp, int start, char **env)
{
	dup2(temp->input, 0);
	dup2(temp->output, 1);
	if (temp->input != 0)
		close(temp->input);
	if (temp->output != 1)
		close(temp->output);
	if (!temp->error)
	{
		if (execve(path, temp->args + start, env) == -1)
			puterror(temp->cmd, strerror(errno));
		exit(errno);
	}
	exit(temp->error);
}

void	run(t_var *v, t_command *temp, int *i, char **env)
{
	char	**args;

	v->tr = NULL;
	v->out = temp->output;
	v->head = temp;
	args = check_cmd(v, temp);
	if (args)
	{
		v->pids[*i] = fork();
		if (!v->pids[*i])
			exe(temp->path, temp, 0, env);
	}
	if (temp->input != 0)
		close(temp->input);
	if (temp->output != 1)
		close(temp->output);
}

static void	run_all_part(t_var *v, sig_t *sig, int i, char **env)
{
	wait(&v->err);
	while (i >= 1)
		waitpid(v->pids[i-- - 1], NULL, 0);
	v->err = WEXITSTATUS(v->err);
	normal_echo(v);
	signal(SIGINT, sig[0]);
	signal(SIGQUIT, sig[1]);
	my_clear(&env);
	correct_echo(v);
	free(v->pids);
}

void	run_all(t_var *v)
{
	t_command	*temp;
	char		**env;
	int			i;
	sig_t		sig[2];

	v->pids = malloc((size_t_command(v->head)) * sizeof(pid_t));
	if (v->pids == NULL)
		return ;
	temp = v->head;
	v->previous = NULL;
	env = to_env(v->env, false);
	i = 0;
	sig[0] = signal(SIGINT, sigint_handler_in_process);
	sig[1] = signal(SIGQUIT, sigquit_handler_in_process);
	normal_echo(v);
	while (temp)
	{
		run(v, temp, &i, env);
		i++;
		v->previous = temp;
		temp = temp->next;
	}
	run_all_part(v, sig, i, env);
}
