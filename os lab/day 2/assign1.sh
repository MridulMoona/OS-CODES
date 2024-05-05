#!/bin/bash
echo "Enter the radius of the circle in meter"
read radius
area=`echo $radius \* $radius \* 3.14 | bc`
echo "Are of the circle is : $area"