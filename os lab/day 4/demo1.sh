#Write a shell script to demonstrate while loop
#!/bin/sh

a=0
while [ $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1`
done