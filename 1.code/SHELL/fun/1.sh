#!/bin/bash

echo "sum1=$sum"

add() {
    local num1=$1
    local num2=$2
    sum=$((num1 + num2))
}



add 1 2
echo "num1=$num1"
echo "sum2=$sum"