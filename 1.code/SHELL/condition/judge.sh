#!/bin/bash

echo "please input a int number: "
read num

if [ $num -lt 100 ]; then
    echo "The number is less than 100"
elif [ $num -gt 1000 ]; then
    echo "The number($num) is greater than 1000"
else
    echo "The number($num) is smaller than 100"
fi

echo "if finished"