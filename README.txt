1- gcc -o test1 test1.c   (para crear los txt )
------------------------------------------------------------------------------------------------------
2- ./test1 m k n incremento max    (compilar el programa para crear txt con incrementos)

m = filasMatrizA (numero de orden de partida para el data0.txt)
k = columnasMatrizA y filasMatrizB (numero de orden de partida para el data0.txt)
n = columnasMatrizB (numero de orden de partida para el data0.txt)
incremento = incremento para sumar al orden inicial para data1.txt
max = numero máximo que alcanzara después de iterar el incremento en el numero base ( m,k.n) 
------------------------------------------------------------------------------------------------------
3- gcc -o t2 t2.c (existen 2 modos de compilar 4.1 y 4.2)
--------------------------------------------------------------------------------------------------------
4.1- ./t2 -V -O < data0.txt  (compilación del código en los distintos modos especificados)

V= {A: ijk , B: jik , C: ikj , D: jki , E: kij , F: kji , G: multiplicacion_1D , H: aritmeticaPunteros}
O = {V: modo verboso , S: modo silencioso}
data[X].txt.  X=0,1,2,3,...cantidadtxts
--------------------------------------------------------------------------------------------------------
4.2- ./run.sh

ejecuta con todos los modos de ejecuccion en modo silencioso y guarda las salidas en output.txt, con los archivos data0.txt , data1.txt .... , data18.txt. este sh sirve para recrear el experimento de forma automatica. 