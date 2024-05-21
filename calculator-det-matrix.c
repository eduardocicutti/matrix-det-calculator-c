#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

// Implementar função básica para calcular o det de uma matriz

int determinant(int matrix[][10], int n) 
{
    int i, j, k, sinal, det = 0;
    int submatrix[10][10]; // Submatriz temporária

    // Calcular matrizes 1x1 e 2x2
    if (n == 1)
        return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    // Laplace para matrizes maiores, usando for loop
    for (k = 0; k < n; k++) 
    {
        // Removendo a linha 0 e a coluna k 
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (j < k)
                    submatrix[i - 1][j] = matrix[i][j];
                else if (j > k)
                    submatrix[i - 1][j - 1] = matrix[i][j];
            }
        }

        // Determinar a mudança de sinal para o termo corrente da expansão de Laplace
        sinal = (k % 2 == 0) ? 1 : -1;

        // Calcula o determinante da submatriz
        det += sinal * matrix[0][k] * determinant(submatrix, n - 1);
    }

    return det;
}

int main ()
{
    int n, i, j, temp;
    bool matriz_valida = false;

    // Loop para garantir que a ordem da matriz seja válida
    while (!matriz_valida) {
        printf("Digite a ordem da matriz: ");
        temp = scanf("%d", &n);
        if (temp != 1 || n <= 0 || n > 10) {
            printf("Erro: Insira um número inteiro positivo entre 1 e 10 como a ordem da matriz.\n");
        } else {
            matriz_valida = true;
        }
    }

    int matrix[10][10];

    // Loop para solicitar a entrada de cada elemento da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            bool elemento_valido = false;
            while (!elemento_valido) {
                printf("Digite o elemento da posição (%d, %d): ", i + 1, j + 1);
                temp = scanf("%d", &matrix[i][j]);
                if (temp != 1) {
                    printf("Erro: Insira apenas números inteiros como elementos da matriz.\n");
                    // Limpa o buffer de entrada para evitar loops infinitos
                    while ((temp = getchar()) != '\n' && temp != EOF);
                } else {
                    elemento_valido = true;
                }
            }
        }
    }

    // Calcular e imprimir o determinante da matriz
    printf("Determinante = %d\n", determinant(matrix, n));

    return 0;
}
