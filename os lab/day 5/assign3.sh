#!/bin/bash

echo "Enter a number (n):"
read n

sum=0

for ((i=1; i<=n; i++))
do
    sum=$((sum + i))
done

echo "The sum of integers from 1 to $n is: $sum"
