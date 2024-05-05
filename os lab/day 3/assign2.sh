#1/bin/sh

echo "year"
read y
l=$((y % 4))
m=$((y % 100))
n=$((y % 400))
if [ $l -eq 0 ]
then
    if [ $n -eq 0 ]
    then
        echo "leap year"
    elif [ $m -ne 0 ]
    then    
        echo "leap year"
    else
        echo "not leap year"   
    fi  
else
    echo "not leap year"   
fi