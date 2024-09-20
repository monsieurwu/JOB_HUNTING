#!/bin/bash

tail -n0 -f file.txt | while read line
do
    echo "line:$line"
done