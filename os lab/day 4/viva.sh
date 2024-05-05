#/bin/bash
len=0
for (( start=1;start<=100;start++ ))              
do
        
    cl_no=$start                     
    while [ $cl_no -gt 0 ]
    do        
        cl_no=$( expr $cl_no / 10 ) 
        len=$(( $len + 1 ))
    done                                                                                               
    cln=$start
    mul=1
    sum=0
    while [ $cln -gt 0 ]
    do
        ldo=$( expr $cln % 10 )
        cln=$( expr $cln / 10 )
        for (( j=1;j<=$len;j++ ))
        do
        done
        sum=`expr $sum + $mul`   
        mul=1
    done
    if [ $sum -eq $start ]
    then
        echo $start
    fi
done