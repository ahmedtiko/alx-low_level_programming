#include "main.h"

/**
 * alloc_grid - Create a 2D array of integers
 * @width: The width of the grid
 * @height: The height of the grid
 *
 * Return: A pointer to the newly allocated 2D array.
 * NULL if width or height is 0 or if memory allocation fails.
 */

int **alloc_grid(int width, int height)
{
	int i, j, **grid;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **)malloc(sizeof(int *) * height);

	if (grid == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (j = 0; j < width; j++)
			{
				free(grid[j]);
			}
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid);
}
