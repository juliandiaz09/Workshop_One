#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMatrix(int matrix[][3], int rows, int columns) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 10; // Genera valores aleatorios entre 0 y 9
        }
    }
}

void showMatrix(int matrix[][3], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int productPoint(int array1[], int array2[], int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += array1[i] * array2[i];
    }

    return result;
}

void multiplyMatrix(int matrix1[][3], int matrix2[][3], int result[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int option;

    printf("Seleccione el ejercicio a realizar:\n");
    printf("1. Producto Punto\n");
    printf("2. Multiplicación de Matrices\n");
    printf("Ingrese el número de la opción: ");
    scanf("%d", &option);

    if (option == 1) {
        int array1[3];
        int array2[3];

        printf("\nIngrese los elementos del primer arreglo:\n");
        for (int i = 0; i < 3; i++) {
            scanf("%d", &array1[i]);
        }

        printf("Ingrese los elementos del segundo arreglo:\n");
        for (int i = 0; i < 3; i++) {
            scanf("%d", &array2[i]);
        }

        int result = productPoint(array1, array2, 3);
        printf("\nEl producto punto de los arreglos es: %d\n", result);
    } else if (option == 2) {
        int matrix1[3][3];
        int matrix2[3][3];
        int result[3][3];

        printf("\nGenerando matriz 1:\n");
        generateMatrix(matrix1, 3, 3);
        showMatrix(matrix1, 3, 3);

        printf("\nGenerando matriz 2:\n");
        generateMatrix(matrix2, 3, 3);
        showMatrix(matrix2, 3, 3);

        multiplyMatrix(matrix1, matrix2, result);

        printf("\nResultado de la multiplicación:\n");
        showMatrix(result, 3, 3);
    } else {
        printf("\nOpción inválida. Por favor, seleccione una opción válida.\n");
    }

    return 0;
}