#!/bin/bash
echo "input file name"
read file


if [[ -f $file ]]; then
    echo "File exists."
else
    echo "File does not exist."
    
fi

