#include "../minishell.h"

int space_counter(char *str)
{
    int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if ((str[i + 1] == '<' || str[i + 1] == '>') && str[i] != ' ' && str[i] != str[i + 1])
			count++;
		else if ((str[i] == '<' || str[i] == '>') && str[i + 1] != ' ' && str[i] != str[i + 1])
			count++;
	}
    return (count);
}

char	*add_space_around_redirection(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*new_str;

	i = -1;
    j = 0;
	count = space_counter(str);
	if (!count)
		return (str);
	new_str = (char *)malloc((ft_strlen(str) + count) * sizeof(char));
	while (str[++i])
	{
		new_str[j] = str[i];
		j++;
		if ((str[i + 1] == '<' || str[i + 1] == '>') && str[i] != ' ' && str[i] != str[i + 1])
			new_str[j++] = ' ';
		else if ((str[i] == '<' || str[i] == '>') && str[i + 1] != ' ' && str[i] != str[i + 1])
			new_str[j++] = ' ';
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}