#include "../../minishell.h"

void	clear(char **paths, int *size, int j)
{
	while (--j >= 0)
		free(paths[j]);
	free(paths);
	if (size)
		free(size);
}
