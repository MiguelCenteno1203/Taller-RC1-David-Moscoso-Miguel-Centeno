#include <stdio.h>

#define ASIGNATURAS 3
#define NOTA_MINIMA 0.0
#define NOTA_MAXIMA 10.0
#define NOTA_APROBATORIA 6.0

void cargarCalificaciones(int n, float *ptr);
void procesarEstudiantes(int n, float *ptr);
void procesarAsignaturas(int n, float *ptr);

int main() {
    int numEstudiantes;
    do {
        printf("Ingrese la cantidad de estudiantes: ");
        if (scanf("%d", &numEstudiantes) != 1 || numEstudiantes <= 0) {
            while (getchar() != '\n');
            numEstudiantes = 0;
        }
    } while (numEstudiantes <= 0);

    float calificaciones[numEstudiantes][ASIGNATURAS];

    cargarCalificaciones(numEstudiantes, (float *)calificaciones);
    procesarEstudiantes(numEstudiantes, (float *)calificaciones);
    procesarAsignaturas(numEstudiantes, (float *)calificaciones);

    return 0;
}

void cargarCalificaciones(int n, float *ptr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            float *nota = ptr + (i * ASIGNATURAS) + j; 
            do {
                printf("  Estudiante %d - Asignatura %d: ", i + 1, j + 1);
                scanf("%f", nota);
            } while (*nota < NOTA_MINIMA || *nota > NOTA_MAXIMA);
        }
    }
}

void procesarEstudiantes(int n, float *ptr) {
    for (int i = 0; i < n; i++) {
        float *fila = ptr + (i * ASIGNATURAS); 
        float suma = 0, max = *fila, min = *fila; 
        for (int j = 0; j < ASIGNATURAS; j++) {
            float val = *(fila + j);
            suma += val;
            if (val > max) max = val;
            if (val < min) min = val;
        }
    }
}

void procesarAsignaturas(int n, float *ptr) {
    printf("\n==================================================\n");
    printf("          REPORTE GENERAL POR ASIGNATURA          \n");
    printf("==================================================\n");

    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0, max = *(ptr + j), min = *(ptr + j);
        int aprobados = 0; // Agregado de variable estadística

        for (int i = 0; i < n; i++) {
            float val = *(ptr + (i * ASIGNATURAS) + j); 
            suma += val;
            if (val > max) max = val;
            if (val < min) min = val;
            if (val >= NOTA_APROBATORIA) aprobados++; // Lógica de incremento
        }

        printf("Asignatura %d:\n", j + 1);
        printf("  > Promedio General  : %.2f\n", suma / n);
        printf("  > Calificacion Alta : %.2f\n", max);
        printf("  > Calificacion Baja : %.2f\n", min);
        // Modificación de la salida agregando aprobados y reprobados calculados aritméticamente
        printf("  > Aprobados: %d | Reprobados: %d\n", aprobados, n - aprobados);
        printf("--------------------------------------------------\n");
    }
}