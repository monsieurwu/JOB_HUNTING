#!/bin/bash

add() {

    local num1=$1
    local num2=$2
    sum=$(($num1+$num2))
    echo $sum
}

result=$(add 1 2)
echo "sum=$sum"

echo "sum is $result"