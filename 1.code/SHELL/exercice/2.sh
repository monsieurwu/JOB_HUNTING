#!/bin/bash
echo "input a series of numbers, input 0 to exit"
sum=0
while true
do
    read num
    
    if [ $num -eq 0 ];
    then
        break
    fi

    sum=$(($sum + $num))


 

done
echo "sum is $sum"