#!/bin/bash
#/***************************************************************************************
# * 
# * run.sh: programa para automatizar experimento 
# *     
# * Programmer: Gabriel Valdez
# *
# * Santiago de Chile, 20/11/2024
# *
# **************************************************************************************/

data_files=("data0.txt" "data1.txt" "data2.txt" "data3.txt" "data4.txt" "data5.txt" "data6.txt" "data7.txt" "data8.txt" "data9.txt" "data10.txt" "data11.txt" "data12.txt" "data13.txt" "data14.txt" "data15.txt" "data16.txt" "data17.txt" "data18.txt")


for file in "${data_files[@]}"
do
    
    echo "Ejecutando con archivo $file" >> output.txt
    ./t2 -A -S < "$file" >> output.txt
    ./t2 -B -S < "$file" >> output.txt
    ./t2 -C -S < "$file" >> output.txt
    ./t2 -D -S < "$file" >> output.txt
    ./t2 -E -S < "$file" >> output.txt
    ./t2 -F -S < "$file" >> output.txt
    ./t2 -G -S < "$file" >> output.txt
    ./t2 -H -S < "$file" >> output.txt
    echo "Finalizado $file" >> output.txt
done

echo "Todas las ejecuciones han finalizado."
