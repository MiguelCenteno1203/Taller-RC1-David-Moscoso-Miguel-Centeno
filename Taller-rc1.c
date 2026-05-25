#include <stdio.h>

#define ASIGNATURAS 3
#define NOTA_MINIMA 0.0
#define NOTA_MAXIMA 10.0
#define NOTA_APROBATORIA 6.0

int main() {
    int numEstudiantes;
    printf("==================================================\n");
    printf("      SISTEMA DE GESTION DE CALIFICACIONES        \n");
    printf("==================================================\n");

    do {
        printf("Ingrese la cantidad de estudiantes: ");
        if (scanf("%d", &numEstudiantes) != 1 || numEstudiantes <= 0) {
            printf("Error: Ingrese un entero positivo.\n");
            while (getchar() != '\n');
            numEstudiantes = 0;
        }
    } while (numEstudiantes <= 0);

    float calificaciones[numEstudiantes][ASIGNATURAS];

    return 0;
}