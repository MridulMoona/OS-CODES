#!/bin/bash
#
echo "Enter the tim in seconds"
read sec
m=`echo $sec % 3600 | bc `
hrs=`echo $sec/3600 | bc `
min=`echo $m / 60 | bc `
sec1=`echo $sec % 60 | bc `
echo "hours : $hrs" 
echo "minutes : $min"
echo "seconds : $sec1"