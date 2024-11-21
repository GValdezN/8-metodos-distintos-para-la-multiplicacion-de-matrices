/***************************************************************************************
 * 
 * test1.c: creador de archivos txt para t2.c
 * 
 * Programmer: Gabriel Valdez
 *
 * Santiago de Chile, 20/11/2024
 *
 **************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void generar_matrix(int rows, int cols, FILE *file) {

    int i, j;

    for (i = 0; i < rows; i = i + 1) {
        for (j = 0; j < cols; j = j + 1) {
            fprintf(file, "1 \n"); 
        }
    }
}

int main(int argc, char **argv) {

    int m, k, n, incremento, max, file_count = 0;

    if (argc != 6) {
        printf("Usage: %s <m> <k> <n> <incremento> <max>\n", argv[0]);
        return 1;
    }

    m = atoi(argv[1]);
    k = atoi(argv[2]);
    n = atoi(argv[3]);
    incremento = atoi(argv[4]);
    max = atoi(argv[5]);

    while (m <= max && k <= max && n <= max) {
        char filename[20];
        snprintf(filename, sizeof(filename), "data%d.txt", file_count);

        FILE *file = fopen(filename, "w");
        if (!file) {
            printf("Error opening file %s!\n", filename);
            return 1;
        }

        fprintf(file, "%d\n%d\n%d\n", m, k, n); 
        generar_matrix(m, k, file); 
        generar_matrix(k, n, file); 

        fclose(file);
        printf("Archivo %s generado con m=%d, k=%d, n=%d\n", filename, m, k, n);

        m = m + incremento; 
        k = k + incremento; 
        n = n + incremento; 

        
        if (m > max || k > max || n > max) {
            break;
        }

        file_count = file_count + 1; 
    }

    return 0;
}
