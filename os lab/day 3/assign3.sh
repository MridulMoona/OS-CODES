#!/bin/sh
echo "enter the three numbers"
read a
read b
read c
if [ $a -gt $b -a $a -gt $c ]
then 
    echo "the greatest number is $a"
elif [ $b -gt $a -a $b -gt $c ]
    then
    echo "the greatest number is $b"
else
    echo "the greatest number is $c"
fi