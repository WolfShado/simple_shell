#include "shell.h"

/**
 * free_grid - free array
 *
 * @grid:  array
 */
void free_grid(char **grid)
{
size_t i;
if (grid)
{
for (i = 0; grid[i]; i++)
{
free(grid[i]);
}
free(grid);
}
}
/**
 * free_all - free all
 * @buff: str to be freed
 * @grid: array to be freed
 */
void free_all(char *buff, char **grid)
{
free(buff);
free_grid(grid);
}
