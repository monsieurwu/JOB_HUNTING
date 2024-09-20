#!/bin/bash

counter=1

while [ $counter -le 5 ]
do
    if [ $counter -eq 4 ]; then
        ((counter++))
        continue
    fi
    echo "Count:$counter"
    ((counter++))
done