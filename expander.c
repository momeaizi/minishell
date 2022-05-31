/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:03:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/30 22:52:34 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dollar_counter(char *str, char	expand_all)
{
	int		i;
	int		count;
	char	should_expand;
	char	double_qoute;

	i = -1;
	count = 0;
	should_expand = 1;
	double_qoute = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && !expand_all)
			double_qoute = !double_qoute;
		if (str[i] == '\'' && !double_qoute)
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		if (str[i] == '$' && ft_isalnum(str[i + 1]))
			count++;
		else if (str[i] == '$' && str[i] == str[i + 1])
			i++;
	}
	return (count);
}

int	compare(char *s1, char *s2, int s2_size)
{
	int	i;

	i = -1;
	while (++i < s2_size)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	if (s1[i] == '=')
		return (0);
	return (1);
}

t_env_var	*get_variable(char **env, char *var, int var_len)
{
	int			i;
	int			length;
	t_env_var	*env_var;

	i = -1;
	env_var = (t_env_var *)malloc(sizeof(t_env_var));
	if (!env_var)
		return (NULL);
	env_var->var = var;
	env_var->var_len = var_len;
	env_var->val = NULL;
	while (env[++i])
	{
		if (!compare(env[i], var, env_var->var_len))
		{
			env_var->val = &env[i][var_len + 1];
			break ;
		}
	}
	env_var->val_len = ft_strlen(env_var->val);
	return (env_var);
}

char	*expand(char *str, char **env, char expand_all)
{
	int			i;
	int			index;
	t_env_var	*env_var;
	int			len;
	int			count;
	char		double_qoute;

	i = -1;
	index = 0;
	count = dollar_counter(str, expand_all);
	if (!count)
		return (str);
	env_var = (t_env_var *)malloc((count + 1) * sizeof(t_env_var ));
	while (str[++i])
	{
		len = 0;
		if (str[i] == '\"' && !expand_all)
			double_qoute = !double_qoute;
		if (str[i] == '\'' && !double_qoute)
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		if (str[i] == '$' && ft_isalnum(str[i + 1]))
		{
			while (ft_isalpha(str[++i]))
				len++;
			env_var[index].var = &str[i] - len;
			env_var[index].var_len = len;
			printf("%d\n", env_var[index].var_len);
			index++;
		}
		else if (str[i] == '$' && str[i] == str[i + 1])
			i++;
	}
}

int	main(int ac, char **av, char **env)
{
	expand("taha $USER $HOME taha", env, 0);
}