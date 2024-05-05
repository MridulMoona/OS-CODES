#!/bin/bash
echo "enter the number"
read num
a=` echo "$num % 2" | bc`
if [ $a -eq 0 ]
then 
    echo "the number is even"
else 
    echo "the number is odd"
fi