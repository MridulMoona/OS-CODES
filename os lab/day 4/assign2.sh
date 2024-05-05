#!/bin/sh
echo "enter number"
read n
j=$n
i=$n
p=0
s=0
while [ $n -gt 0 ]
do
    p=$((p + 1))
    n=$((n / 10))
done

while [ $i -gt 0 ]
do
    x=$((i % 10))
    x=$(echo "$x ^ $p" | bc)
    s=$((s + x))
    i=$((i / 10))
done
if [ $s -eq $j ]
then
    echo "is armstrong"
else
    echo "not armstrong"
fi