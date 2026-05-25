#include <stdio.h>

#define ASIGNATURAS 3
#define NOTA_MINIMA 0.0
#define NOTA_MAXIMA 10.0
#define NOTA_APROBATORIA 6.0

void cargarCalificaciones(int n, float *ptr);

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

    // Llamada a la función de carga enviando el puntero base
    cargarCalificaciones(numEstudiantes, (float *)calificaciones);

    return 0;
}

void cargarCalificaciones(int n, float *ptr) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Registro - Estudiante %d ---\n", i + 1);
        for (int j = 0; j < ASIGNATURAS; j++) {
            float *nota = ptr + (i * ASIGNATURAS) + j; 
            do {
                printf("  Asignatura %d: ", j + 1);
                if (scanf("%f", nota) != 1) {
                    printf("    [!] Error de lectura. Reintente.\n");
                    while (getchar() != '\n');
                    *nota = -1.0;
                } else if (*nota < NOTA_MINIMA || *nota > NOTA_MAXIMA) {
                    printf("    [!] Rango invalido (%.1f - %.1f).\n", NOTA_MINIMA, NOTA_MAXIMA);
                }
            } while (*nota < NOTA_MINIMA || *nota > NOTA_MAXIMA);
        }
    }
}