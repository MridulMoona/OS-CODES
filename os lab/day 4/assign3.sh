#!/bin/sh
echo "enter number"
read n
i=2
s=0

if [ $n -lt 2 ]
then 
    s=$((s + 1))
fi

while [ $i -lt $n ]
do
    q=$((n % i))
    if [ $q -eq 0 ]
    then
        s=$((s + 1))
    fi
    i=$((i + 1))
done

if [ $s -eq 0 ]
then
    echo "is prime"
else
    echo "not prime"
fi