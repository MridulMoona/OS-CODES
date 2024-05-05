#!/bin/bash
echo "Enter the height and base of the triangle"
read base
read height
area=`echo 0.5 *\ $base *\ $height | bc`
echo "The area of the triangle is : $area"