#!/bin/bash

echo "Enter the three sides of the triangle:"
read side1
read side2
read side3


if [ $((side1 + side2)) -gt $side3 ] && [ $((side2 + side3)) -gt $side1 ] && [ $((side1 + side3)) -gt $side2 ]; then

    if [ $side1 -eq $side2 ] && [ $side2 -eq $side3 ]; then
        echo "Equilateral triangle"
    elif [ $side1 -eq $side2 ] || [ $side2 -eq $side3 ] || [ $side1 -eq $side3 ]; then
        echo "Isosceles triangle"
    else
        echo "Scalene triangle"
    fi
else
    echo "Invalid triangle. The sum of any two sides must be greater than the third side."
fi
