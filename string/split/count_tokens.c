#include "../../minishell.h"

int	count_tokens(char *str, char c)
{
	int	i;
	int	count;

	replace_inside_quotes(str, -1, c);
	i = -1;
	count = 1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (i == 0 && str[i] != c)
			count++;
		else if (str[i] != c && str[i - 1] == c)
			count++;
	}
	return (count);
}
