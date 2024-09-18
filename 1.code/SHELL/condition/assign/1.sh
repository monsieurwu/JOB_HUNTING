#!/bin/bash

echo "input x y z"
read x y z

if [ $x -gt $y ]; then 
    temp=$x
    x=$y
    y=$temp
fi

if [ $y -gt $z ]; then 
    temp=$y
    y=$z
    z=$temp

    if [ $x -gt $y ]; then 
        temp=$x
        x=$y
        y=$temp
    fi
fi
echo "after sequence: x:$x y:$y z:$z"