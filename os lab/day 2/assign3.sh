#!/bin/bash
echo "Enter the temperature in farenheiht"
read f
m=`echo $f \- 32 |bc `
c=`echo $m \* 1.8 | bc`
echo "The temperature in farenheight is  : $c"