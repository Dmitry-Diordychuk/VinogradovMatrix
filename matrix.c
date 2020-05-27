/******************************************************************************/
/*                                                                            */
/*                         File: matrix.c                                     */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 27th May 2020 8:38:03 pm                     */
/*                Last Modified: 27th May 2020 8:38:06 pm                     */
/*                                                                            */
/******************************************************************************/

#include "matrix.h"

static time_t	t;

matrix_t	*create_sq_matrix(long long int size)
{
	unsigned long long int	i;
	matrix_t				*mtx;

	if (!(mtx = (matrix_t*)malloc(sizeof(matrix_t))))
		return (NULL);
	mtx->M = size;
	mtx->N = size;
	if (!(mtx->array = (long long int**)calloc(size, sizeof(long long int*))))
	{
		free(mtx);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		if (!(mtx->array[i] =
						(long long int*)calloc(size, sizeof(long long int))))
		{
			while (--i > 0)
			{
				free(mtx->array[i]);
			}
			free(mtx->array[i]);
			free(mtx->array);
			free(mtx);
			return (NULL);
		}
		i++;
	}
	return (mtx);
}

void		free_matrix(matrix_t *mtx)
{
	unsigned long long int	i;

	i = 0;
	while (i < mtx->M)
	{
		free(mtx->array[i]);
		i++;
	}
	free(mtx->array);
	free(mtx);
}

void		init_random()
{
	srand((unsigned)time(&t));
}

void		fill_array_random(matrix_t *mtx)
{
	unsigned long long int	i;
	unsigned long long int	j;

	i = 0;
	while (i < mtx->M)
	{
		j = 0;
		while (j < mtx->N)
		{
			mtx->array[i][j] = rand() % 10;
			j++;
		}
		i++;
	}
}

void		print_matrix(matrix_t *mtx)
{
	unsigned long long int	i;
	unsigned long long int	j;

	i = 0;
	while (i < mtx->M)
	{
		j = 0;
		while (j < mtx->N)
		{
			printf("%d	", mtx->array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
