#!/bin/sh
echo "marks"
read m
if [ $m -ge 90 ]
then
    echo "grade = O"
elif [ $m -ge 80 ]
then
    echo "grade = E"
elif [ $m -ge 70 ]
then
    echo "grade = A"
elif [ $m -ge 60 ]
then
    echo "grade = B"
elif [ $m -ge 50 ]
then
    echo "grade = C"
elif [ $m -ge 40 ]
then
    echo "grade = D" 
else
    echo "grade = F"    
fi