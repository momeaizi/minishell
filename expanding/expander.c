/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <momeaizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:03:52 by momeaizi          #+#    #+#             */
/*   Updated: 2022/05/31 19:28:12 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	clear_env(t_env_var *env_var)
{
	int	i;

	i = -1;
	while (env_var[++i].end)
	{
		if (!ft_strcmp("?", env_var[i].var))
			free(env_var[i].val);
		free(env_var[i].var);
	}
	free(env_var);
}

int	ignore_quotes(char *str, char expand_all, char double_qoute)
{
	int	i;

	i = 0;
	if (expand_all)
		return (0);
	if (str[i] == '\'' && !double_qoute)
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		if (str[i] == '\'')
			return (i);
		return (1);
	}
	return (0);
}



int	dollar_counter(char *str, char	expand_all)
{
	int		i;
	int		count;
	char	double_qoute;

	i = -1;
	count = 0;
	double_qoute = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
			double_qoute = !double_qoute;
		i += ignore_quotes(str + i, expand_all, double_qoute);
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '_' || str[i + 1] == '?'))
			count++;
		else if (str[i] == '$' && str[i] == str[i + 1])
			i++;
	}
	return (count);
}

void	get_variable(t_env_var	*env_var, char **env)
{
	char	*var;

	env_var->end =  1;
	if (!env_var->var_len)
		env_var->var_len = 1;
	var = env_var->var;
	env_var->var = (char *)malloc((env_var->var_len + 1) * sizeof(char));
	if (!env_var->var)
		return ;
	ft_strlcpy(env_var->var, var, env_var->var_len + 1);
	if (!ft_strcmp("?", env_var->var))
		env_var->val = ft_itoa(errno);
	else
		env_var->val = getenv(env_var->var);
	env_var->val_len = ft_strlen(env_var->val);
}



char	*replace_var_by_val(char *str, t_env_var *env_var, char expand_all)
{
	int		i;
	int		j;
	int		index;
	int		length;
	char	double_qoute;
	char	expnd;
	char	*new_str;

	i = -1;
	length = ft_strlen(str) + 1;
	double_qoute = 0;
	expnd = 1;
	while (env_var[++i].end)
		length = length + (env_var[i].val_len - env_var[i].var_len - 1);
	new_str = (char *)malloc(length * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	j = 0;
	index = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
			double_qoute = !double_qoute;
		if (str[i] == '\'' && !double_qoute && !expand_all)
			expnd = 0;
		if (expnd && str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '_' || str[i + 1] == '?'))
		{
			ft_strlcpy(new_str + j, env_var[index].val, env_var[index].val_len + 1);
			i += env_var[index].var_len;
			j += env_var[index].val_len;
			index++;
		}
		else
			new_str[j++] = str[i];
	}
	new_str[j] = 0;
	// free(str);
	return (new_str);
}


char	*expand(char *str, char **env, char expand_all)
{
	int			i;
	int			index;
	int			count;
	t_env_var	*env_var;
	char		double_qoute;
	i = -1;
	index = 0;
	count = dollar_counter(str, expand_all);
	if (!count)
		return (str);
	env_var = (t_env_var *)malloc((count + 1) * sizeof(t_env_var ));
	double_qoute = 0;
	while (str[++i])
	{
		if (str[i] == '\"')
			double_qoute = !double_qoute;
		i += ignore_quotes(str + i, expand_all, double_qoute);
		if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '_' || str[i + 1] == '?'))
		{
			env_var[index].var_len = 0;
			env_var[index].var = &str[i] + 1;
			while (ft_isalpha(str[++i])|| str[i] == '_')
				env_var[index].var_len++;
			get_variable(&env_var[index], env);
			index++;
		}
		else if (str[i] == '$' && str[i] == str[i + 1])
			i++;
	}
	env_var[index].end = 0;
	char *new = replace_var_by_val(str, env_var, expand_all);
	clear_env(env_var);
	return (new);
}

int	main(int ac, char **av, char **env)
{
	char	*str = expand("map \'\"\'$USER\'\"\' taha,|", env, 0);
	printf("%s\n", str);
	// printf("%s\n", getenv("1"));
	// system("leaks a.out");
	
}