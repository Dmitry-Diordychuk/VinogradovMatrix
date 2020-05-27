/******************************************************************************/
/*                                                                            */
/*                         File: matrix.h                                     */
/*                   Created By: Dmitry Diordichuk                            */
/*                        Email: cort@mail.ru                                 */
/*                                                                            */
/*                 File Created: 27th May 2020 8:28:56 pm                     */
/*                Last Modified: 27th May 2020 8:29:03 pm                     */
/*                                                                            */
/******************************************************************************/

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct		matrix_s
{
	long long int	**array;
	long long int	N;
	long long int	M;
}					matrix_t;

matrix_t	*create_sq_matrix(long long int size);
void		free_matrix(matrix_t *mtx);
void		init_random();
void		fill_array_random(matrix_t *mtx);
void		print_matrix(matrix_t *mtx);

void		standart_multiplication(matrix_t *A, matrix_t *B, matrix_t *C);
void		vinograd_multiplication(matrix_t *A, matrix_t *B, matrix_t *C,
									long long int *MulH, long long int *MulV);

#endif
