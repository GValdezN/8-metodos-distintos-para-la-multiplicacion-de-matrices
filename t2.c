/***************************************************************************************
 * 
 * t2.c: Multiplicacion Clasica De Matrices y Metodos 1D con aritmetica de punteros 
 * y formulas para acceder a una matriz 2D en 1D    
 *
 * Programmer: Gabriel Valdez
 *
 * Santiago de Chile, 20/11/2024
 *
 **************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void usage(char *m) {

    printf("\nUso: %s -V -O < data.txt \n", m);
    printf("V= {-A: ijk , -B: jik , -C: ikj , -D: jki, -E: kij, -F: kji, -G: 1D, -H: aritPunt}\n");
    printf("O = {-V: modo verboso, -S: modo silencioso}\n");

}

//recorrer filas 
void multiplicar_i_j_k(int filas, int fila_columna, int columnas, float **a, float **b, float **c) {

    int i,j,k;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
                c[i][j] = 0; 
            for (k = 0; k < fila_columna; k = k + 1) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

}

//recorrer columna
void multiplicar_j_i_k(int filas, int fila_columna, int columnas, float **a, float **b, float **c) {

    int i,j,k;

    for (j = 0; j < columnas; j = j + 1) {
        for (i = 0; i < filas; i = i + 1) {
                c[i][j] = 0; 
            for (k = 0; k < fila_columna; k = k + 1) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

}

//productos parciales k recorriendo por filas
void multiplicar_i_k_j(int filas, int fila_columna, int columnas, float **a, float **b, float **c) {

    int i,j,k;

    for (i = 0; i < filas; i = i + 1) {
        for (k = 0; k < fila_columna; k = k + 1) {
            for (j = 0; j < columnas; j = j + 1) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

}

//productos parciales k recorriendo por columnas
void multiplicar_j_k_i(int filas, int fila_columna, int columnas, float **a, float **b, float **c) {

    int i,j,k;

    for (j = 0; j < columnas; j = j + 1) {
        for (k = 0; k < fila_columna; k = k + 1) {
            for (i = 0; i < filas; i = i + 1) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

}

//acceder a los k compartidos recooriendo filas
void multiplicar_k_i_j(int filas, int fila_columna, int columnas, float **a, float **b, float **c) {

    int i,j,k;

    for (k = 0; k < fila_columna; k = k + 1) {
        for (i = 0; i < filas; i = i + 1) {
            for (j = 0; j < columnas; j = j + 1) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

}

//acceder a los k compartidos recooriendo columnas
void multiplicar_k_j_i(int filas, int fila_columna, int columnas, float **a, float **b, float **c) {

    int i,j,k;

    for (k = 0; k < fila_columna; k = k + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            for (i = 0; i < filas; i = i + 1) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

}

void imprimir_matrix(int filas, int columnas, float **matrix) {

    int i,j;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void llenar_matrix(float **matrix, int filas, int columnas) {

    int i, j;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            scanf("%f", &matrix[i][j]);
        }
    }
}

float **reservar_memoria(int filas , int columnas){

    int i;
    float **matrix = NULL;

    matrix = (float **)calloc(filas, sizeof(float*));
    for (i = 0; i < filas; i = i + 1) {
        matrix[i] = (float *)calloc(columnas, sizeof(float));
    }

    return matrix;
}

void free_matrix(float **matrix, int filas){

    int i;

    for (i = 0; i < filas; i = i + 1) {
        free(matrix[i]);
    }

    free(matrix);
}

void multiplicar_1D(int filas, int fila_columna, int columnas, float *a_1D, float *b_1D, float *c_1D) {

    int i,j,k;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
                c_1D[i * columnas + j] = 0; 
            for (k = 0; k < fila_columna; k = k + 1) {
                c_1D[i * columnas + j] = c_1D[i * columnas + j] + a_1D[i * fila_columna + k] * b_1D[k * columnas + j];
            }
        }
    }

}

void imprimir_matrix1D(int filas, int columnas, float *matrix) {

    int i,j;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            printf("%f ", matrix[i * columnas + j]);
        }
        printf("\n");
    }
}

void llenar_matrix1D(float *matrix, int filas, int columnas) {

    int i, j;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            scanf("%f", &matrix[i * columnas + j]);
        }
    }
}

float *reservar_memoria_1D(int filasXcolumnas){

    int i;
    float *matrix = NULL;

    matrix = (float *)calloc(filasXcolumnas, sizeof(float));

    return matrix;
}

void multiplicar_aritmetica_punteros_1D(int filas, int fila_columna, int columnas, float *a, float *b, float *c) {

    int i,j,k;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
                *(c + i * columnas + j) = 0; 
            for (k = 0; k < fila_columna; k = k + 1) {
                *(c + i * columnas + j) = *(c + i * columnas + j) + (*(a + i * fila_columna + k)) * (*(b + k * columnas + j));
            }
        }
    }

}

void imprimir_matrix_aritmetica_punteros_1D(int filas, int columnas, float *matrix) {

    int i,j;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            printf("%f ", *(matrix + i * columnas + j));
        }
        printf("\n");
    }
}

void llenar_matrix_aritmetica_punteros_1D(float *matrix, int filas, int columnas) {

    int i,j;

    for (i = 0; i < filas; i = i + 1) {
        for (j = 0; j < columnas; j = j + 1) {
            scanf("%f", matrix);
            matrix = matrix + 1; 
        }
    }
}

int main(int argc,char **argv) {
    
    int m,k,n,verbose;
    float **a,**b,**c,*a_1D,*b_1D,*c_1D;
    clock_t start,end;
    double time;
    
    if (argc == 3){
    
    if (strcmp(argv[2], "-V") == 0) {
        verbose = 1;
    } else if (strcmp(argv[2], "-S") == 0) {
        verbose = 0;
    }

    scanf("%d",&m);
    scanf("%d",&k);
    scanf("%d",&n);

    printf("m=%d, k=%d, n=%d \n",m,k,n);

    if((strcmp(argv[1],"-A") == 0) || (strcmp(argv[1],"-B") == 0) || (strcmp(argv[1],"-C") == 0) || (strcmp(argv[1],"-D") == 0) || (strcmp(argv[1],"-E") == 0) || (strcmp(argv[1],"-F") == 0)){
    
    a = reservar_memoria(m, k);
    llenar_matrix(a,m,k);
    
    b = reservar_memoria(k, n);
    llenar_matrix(b,k,n);

    c = reservar_memoria(m, n);
    
    if(verbose){   
    printf("\n");   

    printf("Matrix a[%d][%d]: \n",m,k);    
    imprimir_matrix(m,k,a);
    printf("\n");

    printf("Matrix b[%d][%d]: \n",k,n);    
    imprimir_matrix(k,n,b);
    printf("\n");
    }

    if(strcmp(argv[1],"-A") == 0){
    start = clock();
    multiplicar_i_j_k(m,k,n,a,b,c);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    }
    if(strcmp(argv[1],"-B") == 0){
    start = clock();
    multiplicar_j_i_k(m,k,n,a,b,c);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    }
    if(strcmp(argv[1],"-C") == 0){
    start = clock();
    multiplicar_i_k_j(m,k,n,a,b,c);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    }
    if(strcmp(argv[1],"-D") == 0){
    start = clock();
    multiplicar_j_k_i(m,k,n,a,b,c);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    }
    if(strcmp(argv[1],"-E") == 0){
    start = clock();
    multiplicar_k_i_j(m,k,n,a,b,c);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    }
    if(strcmp(argv[1],"-F") == 0){
    start = clock();
    multiplicar_k_j_i(m,k,n,a,b,c);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    }

    if(verbose){    
    printf("Matrix c[%d][%d]: \n",m,n);    
    imprimir_matrix(m,n,c);
    printf("\n");
    }

    printf("Tiempo de ejecución del algoritmo en segundos es: %.6f \n", time);
    
    free_matrix(a,m);
    free_matrix(b,k);
    free_matrix(c,m);
    }

    if((strcmp(argv[1],"-G") == 0)){

    a_1D = reservar_memoria_1D(m*k);
    llenar_matrix1D(a_1D,m,k);
    
    b_1D = reservar_memoria_1D(k*n);
    llenar_matrix1D(b_1D,k,n);

    c_1D = reservar_memoria_1D(m*n);

    if(verbose){     
    printf("\n");   
    printf("Matrix a[%d][%d]: \n",m,k);    
    imprimir_matrix1D(m,k,a_1D);
    printf("\n");

    printf("Matrix b[%d][%d]: \n",k,n);    
    imprimir_matrix1D(k,n,b_1D);
    printf("\n");
    }
    
    start = clock();
    multiplicar_1D(m,k,n,a_1D,b_1D,c_1D);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    
    if(verbose){    
    printf("Matrix c[%d][%d]: \n",m,n);  
    imprimir_matrix1D(m,n,c_1D);
    printf("\n");
    }

    printf("Tiempo de ejecución del algoritmo en segundos es: %.6f \n", time);

    free(a_1D);
    free(b_1D);
    free(c_1D);
    }

    if((strcmp(argv[1],"-H") == 0)){

    a_1D = reservar_memoria_1D(m*k);
    llenar_matrix_aritmetica_punteros_1D(a_1D,m,k);
    
    b_1D = reservar_memoria_1D(k*n);
    llenar_matrix_aritmetica_punteros_1D(b_1D,k,n);

    c_1D = reservar_memoria_1D(m*n);

    if(verbose){     
    printf("\n");   
    printf("Matrix a[%d][%d]: \n",m,k);    
    imprimir_matrix_aritmetica_punteros_1D(m,k,a_1D);
    printf("\n");

    printf("Matrix b[%d][%d]: \n",k,n);    
    imprimir_matrix_aritmetica_punteros_1D(k,n,b_1D);
    printf("\n");
    }
    
    start = clock();
    multiplicar_aritmetica_punteros_1D(m,k,n,a_1D,b_1D,c_1D);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    
    if(verbose){  
    printf("Matrix c[%d][%d]: \n",m,n);  
    imprimir_matrix_aritmetica_punteros_1D(m,n,c_1D);
    printf("\n");
    }

    printf("Tiempo de ejecución del algoritmo en segundos es: %.6f \n", time);

    free(a_1D);
    free(b_1D);
    free(c_1D);
    }

    }
    else{usage(argv[0]);}

    return 0;
}
