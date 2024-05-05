#Write a shell script to demonstrate Until loop

#!/bin/bash
echo "until loop"
i=10
until [ $i -eq 1 ]
do
    echo "$i is not equal to 1";
    i=$((i - 1))
done
echo "i value is $i"
echo "loop terminated"