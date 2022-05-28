#include "../../minishell.h"

void	replace_inside_quotes(char *str, char new, char old)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			j = i;
			i++;
			while (str[i] && str[i] != str[j])
			{
				if (str[i] == old)
					str[i] = new;
				i++;
			}
		}
	}
}
