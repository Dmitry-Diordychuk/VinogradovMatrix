/******************************************************************************/
/*                                                                            */
/*                         File: vinograd.c                                   */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 27th May 2020 9:40:41 pm                     */
/*                Last Modified: 27th May 2020 9:40:43 pm                     */
/*                                                                            */
/******************************************************************************/

#include "matrix.h"

void	vinograd_multiplication(matrix_t *A, matrix_t *B, matrix_t *C,
									long long int *MulH, long long int *MulV)
{
	unsigned long long int	i;
	unsigned long long int	j;
	unsigned long long int	k;
	long long int			buf;

	for (i = 0; i < A->M; i++)
		for (k = 1; k < A->M; k += 2)
			MulH[i] -= A->array[i][k - 1] * A->array[i][k];

	for (i = 0; i < B->M; i++)
		for (k = 1; k < B->M; k += 2)
			MulV[i] -= B->array[k - 1][i] * B->array[k][i];

	for (i = 0; i < A->M; i++)
		for (j = 0; j < B->N; j++)
		{
			C->array[i][j] = MulH[i] + MulV[j];
			buf = 0;
			for (k = 1; k < A->N; k += 2)
				buf += (A->array[i][k] + B->array[k - 1][j]) *
										(A->array[i][k - 1] + B->array[k][j]);
			C->array[i][j] += buf;
		}

	if (A->N % 2 == 1)
	{
		for (i = 0; i < A->M; i++)
			for (j = 0; j < B->N; j++)
				C->array[i][j] = C->array[i][j] + A->array[i][B->M - 1] *
														B->array[B->M - 1][j];
	}
}
