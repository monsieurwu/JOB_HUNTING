#!/bin/bash

counter=1

while [ $counter -le 5 ]
do
    echo "Count:$counter"
    ((counter++))
    if [ $counter -eq 4 ]; then
        break;
    fi

done