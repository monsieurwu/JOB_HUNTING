#!/bin/bash

while true
do
    echo "input first number: "
    read n1
    echo "input second number: "
    read n2
    echo "input operator: "
    read operator
    echo "$n1 $operator $n2 = $(($n1$operator$n2))"
done