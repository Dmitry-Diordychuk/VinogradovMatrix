/******************************************************************************/
/*                                                                            */
/*                         File: main.c                                       */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 27th May 2020 8:06:49 pm                     */
/*                Last Modified: 27th May 2020 9:00:09 pm                     */
/*                                                                            */
/******************************************************************************/

#include "matrix.h"

int	main(void)
{
	clock_t			start_t, end_t;
	matrix_t		*A;
	matrix_t		*B;
	matrix_t		*C;
	long long int	*MulH;
	long long int	*MulV;

	init_random();
	for (int k = 0; k <= 1; k++)
	{
		for (int i = 100; i <= 600; i += 100)
		{
			for (int j = 0; j <= 1; j++)
			{
				A = create_sq_matrix(i + j);
				fill_array_random(A);
				B = create_sq_matrix(i + j);
				fill_array_random(B);
				C = create_sq_matrix(i + j);
				start_t = clock();
				standart_multiplication(A, B, C);
				end_t = clock();
				printf("Standart %d time taken by CPU: %f\n", i + j,
									(double)(end_t - start_t) / CLOCKS_PER_SEC);
				MulH = (long long int*)calloc(A->M, sizeof(long long int));
				MulV = (long long int*)calloc(B->N, sizeof(long long int));
				start_t = clock();
				vinograd_multiplication(A, B, C, MulH, MulV);
				end_t = clock();
				printf("Vinograd %d time taken by CPU: %f\n", i + j,
									(double)(end_t - start_t) / CLOCKS_PER_SEC);
				free_matrix(A);
				free_matrix(B);
				free_matrix(C);
				free(MulH);
				free(MulV);
				printf("\n");
			}
		}
	}
	return (0);
}
