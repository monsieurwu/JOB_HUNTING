#!/bin/bash
echo "input the first number "
read a
echo "input the second number "
read b
echo "before swap: a=$a b=$b"
temp=$a
a=$b
b=$temp
echo "after swap: a=$a b=$b"
