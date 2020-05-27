/******************************************************************************/
/*                                                                            */
/*                         File: standart.c                                   */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 27th May 2020 8:07:26 pm                     */
/*                Last Modified: 27th May 2020 8:37:10 pm                     */
/*                                                                            */
/******************************************************************************/

#include "matrix.h"

void	standart_multiplication(matrix_t *A, matrix_t *B, matrix_t *C)
{
	unsigned long long int	i;
	unsigned long long int	j;
	unsigned long long int	k;

	for (i = 0; i < A->M; i++)
		for (j = 0; j < B->N; j++)
			for (k = 0; k < A->N; k++)
				C->array[i][j] = C->array[i][j] + A->array[i][k] *
																B->array[k][j];
}
