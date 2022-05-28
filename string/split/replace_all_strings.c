#include "../../minishell.h"

void	replace_all_strings(char **strs, char new, char old)
{
	int	i;

	i = -1;
	while (strs[++i])
		replace_inside_quotes(strs[i], new, old);
}
