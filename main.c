#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

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

//3.Punto: Función que convierte un valor numérico entero en su equivalente a número romano

//funcion para validar si el numero esta en el rango establecido
bool validNumber(int number) {
    return number >= 1 && number <= 3000;
}

void numberToRoman(int number) {
    int number2 = number;
    if (!validNumber(number)) {
        printf("NO valido.\n");
        return;
    }

    // Arrays para los símbolos romanos y sus valores correspondientes
    const char* roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int romanValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Construir el número romano
    char romanNumber[20];
    int i = 0;

    while (number > 0) {
        for (int j = 0; j < 13; j++) {
            if (number >= romanValues[j]) {
                while (number >= romanValues[j]) {
                    // Agregar el símbolo romano correspondiente al número
                    strcat(romanNumber, roman[j]);
                    number -= romanValues[j];
                }
            }
        }
    }

    // Imprimir el número romano
    printf("Numero romano de %d es %s\n",number2,romanNumber);
}



// Punto 4:Dado un número de entrada, hallar su factores
//primos y expresarlo en formato de potencias.

void primeFactors(int number) {
    int factor = 2; // Inicializamos el factor en 2 (el primer número primo).
    int exponent = 0;

    printf("%d = ", number);

    while (number > 1) {
        if (number % factor == 0) { // Vemos si el factor actual divide al número.
            exponent++;
            number /= factor;
        } else {
            if (exponent > 0) { // Si había un exponente mayor que 0, significa que encontramos un factor primo.
                printf("%d^%d", factor, exponent); // Imprimimos el factor primo y su exponente.
                if (number > 1) {
                    printf(" * "); // Si hay más factores por venir, imprimimos un asterisco y un espacio.
                }
                exponent = 0; // Reiniciamos el exponente para el siguiente factor.
            }
            factor++; // Pasamos al siguiente número como posible factor primo.
        }
    }

    if (exponent > 0) { // Al final, si todavía tenemos un exponente mayor que 0, significa que el último factor era primo.
        printf("%d^%d", factor, exponent); // Imprimimos el último factor primo y su exponente.
    }

    printf("\n");
}

//Punto 5: Nombre Propio

void properName(char *string) {
    // Comprobamos si la cadena está vacía o nula
    if (string == NULL || strlen(string) == 0) {
        return;
    }

    int length = strlen(string);
    int isFirstLetter = 1;
    int resultIndex = 0; // Índice para la cadena resultante

    for (int i = 0; i < length; i++) {
        string[i] = tolower(string[i]);

        if (isspace(string[i])) {
            isFirstLetter = 1; //Si estamos en un espacio vacio, indicamos que la siguiente es la primera letra
        } else if (isFirstLetter) {
            string[i] = toupper(string[i]);
            isFirstLetter = 0;
        }

        // Si no es un espacio o si no es un espacio adyacente a otro espacio, copia el carácter a la cadena resultante
        if (!isspace(string[i]) || (i > 0 && !isspace(string[i - 1]))) {
            string[resultIndex] = string[i];
            resultIndex++;
        }
    }

    // Agrega un carácter nulo al final para terminar la cadena
    string[resultIndex] = '\0';
}

bool verifyEgolatet(int egolater) {
    int digito = 0, aux = egolater, sum = 0;

    while (aux > 0){
        digito = aux % 10;
        int powDigito = pow(digito, 3);
        sum += powDigito;
        aux /= 10;
    }

    if(egolater == sum){
        printf("hola si es un egolatra igual que mi ex");
        return true;
    } else{
        printf("Este si vale la pena cariño");
        return false;
    }
}

int numberDivisors(int  number){
    int i, sum = 0;

    for(i = 1; i < number; i++){
        if((number % i) == 0){
            sum += i;
        }
    }
    return sum;
}

bool verifyFriendsNumber(int  numberOne, int numberTwo){
    int sum = 0;

    sum = numberDivisors(numberOne);

    if(sum == numberTwo){
        sum = numberDivisors(numberTwo);
        if(sum == numberOne){
            printf("Somos amix");
            return true;
        }
    }else{
        printf("Te odixxx");
        return false;
    }
}

const char* nameMoths[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                           "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

bool esBisiesto(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void describeDate(const char* date) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) == 3 &&
        month >= 1 && month <= 12 &&
        day >= 1 && day <= (month == 2 && esBisiesto(year) ? 29 : (31 - (month - 1) % 7 % 2))) {
        printf("%d de %s de %d\n", day, nameMoths[month - 1], year);
    } else {
        printf("Date not valid.\n");
    }
}


int main() {
    int option;

    printf("Select the exercise to be performed:\n");
    printf("1. Product Point\n");
    printf("2. Multiplication of Matrices\n");
    printf("3. Whole Number to Roman\n");
    printf("4. Egomaniac Numbers\n");
    printf("5. Friends Numbers\n");
    printf("6. Date\n");
    printf("7. Prime Factors\n");
    printf("8. Own name\n");
    printf("Enter the option number: ");
    scanf("%d", &option);


    //Variables

    //Punto1:
    int array1[3];
    int array2[3];

    //Punto2:
    int matrix1[3][3];
    int matrix2[3][3];
    int result[3][3];

    //Punto 3 y 4:
    int number;

    //Punto 5:
    char words[100];

    //
    int numberEgolater = 0;
    //
    int friendNumberOne = 0, friendNumberTwo = 0;

    char date[30];


    switch (option) {
        case 1:
            printf("\nIngrese los elementos del primer arreglo:\n");
            for (int i = 0; i < 3; i++) {
                scanf("%d", &array1[i]);
            }

            printf("Ingrese los elementos del segundo arreglo:\n");
            for (int i = 0; i < 3; i++) {
                scanf("%d", &array2[i]);
            }

            int result1 = productPoint(array1, array2, 3);
            printf("\nEl producto punto de los arreglos es: %d\n", result1);
            break;


        case 2:
            printf("\nGenerando matriz 1:\n");
            generateMatrix(matrix1, 3, 3);
            showMatrix(matrix1, 3, 3);

            printf("\nGenerando matriz 2:\n");
            generateMatrix(matrix2, 3, 3);
            showMatrix(matrix2, 3, 3);

            multiplyMatrix(matrix1, matrix2, result);

            printf("\nResultado de la multiplicacion:\n");
            showMatrix(result, 3, 3);
            break;

        case 3:
            printf("Ingrese un numero: ");
            scanf("%d", &number);
            numberToRoman(number);
            break;


        case 4:
            printf("\nEnter a number for verify if is egolater\n");
            scanf("%i", &numberEgolater);

            printf("\n%s", verifyEgolatet(numberEgolater) ? "True " : "False");
            break;

        case 5:
            printf("\nEnter a number\n");
            scanf("%d", &friendNumberOne);

            printf("\nEnter a number\n");
            scanf("%d", &friendNumberTwo);

            printf("%s", verifyFriendsNumber(friendNumberOne, friendNumberTwo) ? "True" : "False");
            break;

        case 6:

            fflush(stdin);

            printf("Enter a date in the format dd/mm/aaaa: ");
            fgets(date, 30, stdin);

            describeDate(date);
            break;


        case 7:
            printf("Ingrese un numero: ");
            scanf("%d", &number);
            primeFactors(number);
            break;


        case 8:
            printf("Ingrese una cadena: ");
            scanf(" %99[^\n]", words);
            printf("Cadena de Entrada: %s\n", words);

            properName(words);
            printf("Cadena de salida: %s\n", words);
            break;

        default:
            printf("\nOpcion invalida. Por favor, seleccione una opcion valida.\n");
            break;
    }

    return 0;
}