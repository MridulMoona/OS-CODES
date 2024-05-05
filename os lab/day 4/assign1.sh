#!/bin/sh
i=100
s=0
while [ $i -le 200 ]
do
    n=$((i % 9))
    if [ $n -eq 0 ]
    then
        s=$((s + i))
    fi 
    i=$((i + 1))
done
echo $s