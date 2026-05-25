#include <stdio.h>

#define ASIGNATURAS 3
#define NOTA_MINIMA 0.0
#define NOTA_MAXIMA 10.0
#define NOTA_APROBATORIA 6.0

void cargarCalificaciones(int n, float *ptr);
void procesarEstudiantes(int n, float *ptr);

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
    printf("\n==================================================\n");
    printf("          REPORTE GENERAL POR ESTUDIANTE          \n");
    printf("==================================================\n");
    printf("Estudiante\tPromedio\tNota Max\tNota Min\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        float *fila = ptr + (i * ASIGNATURAS); 
        float suma = 0, max = *fila, min = *fila; 

        for (int j = 0; j < ASIGNATURAS; j++) {
            float val = *(fila + j);
            suma += val;
            if (val > max) max = val;
            if (val < min) min = val;
        }
        printf("Alumno %d\t%.2f\t\t%.2f\t\t%.2f\n", i + 1, suma / ASIGNATURAS, max, min);
    }
}