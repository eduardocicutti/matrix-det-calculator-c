#include <stdio.h> 
#include <stdlib.h>

// Implementar função básica para calcular o det de uma matrix

int determinant(int matrix [][10], int n) 
{

    int i, j, k, sinal, det = 0;

    // Calcular matrizes 1x1 e 2x2
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * [1][1] - [0][1] * [1][0];

    // Laplace para matrizes maiores, usando for loop
    for (k = 0; k < n; k++) 
    {

        int submatrix[10][10]; // Submatrix temporária

        // Removendo a linha 0 e a coluna k 
        for (i = 1; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (j < k)
                    submatrix[i-1][j] = matrix[i][j];
                else if (j > k)
                    submatrix[i-1][j-1] = matrix[i][j];
            }
        }
    
    // Determinar a mudança de sinal para o termo corrente da expansão de laplace
    sinal = ((k % 2 ) == 0) ? : -1;

    // Calcula o determinante da submatriz
    det += sinal * matrix[0][k] * determinant(submatrix, n-1);
    }

    return det;
}

int main ()
{

    int n, i, j;

    // Obter a ordem da matriz do usuário
    printf("Digite a ordem da matriz: ");
    scanf("%d", &n);

    int matrix [10][10];

    // Obter os elementos da matriz do usuário
    printf("Digite os elementos da matriz:\n ");
    for (i = 0; i < n; i++);
    {
        for (j = 0; j < n; j++);
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calcular e imprimir o determinante da matriz
    printf("Determinante = %d\n ", determinant(matrix, n));

return 0;

}
