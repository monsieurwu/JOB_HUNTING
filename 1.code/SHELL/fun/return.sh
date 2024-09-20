#!/bin/bash

g_num=7
check_even(){
    local num=$1
    if [ $((num%2)) -eq 0 ]; then
        return 0
    else
        return 1
    fi
}

check_even $g_num
return_code=$?

if [ $return_code -eq 0 ]; then
    echo "$g_num is an even number."
else
    echo "$g_num is an odd number."
fi