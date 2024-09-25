#!/bin/bash

make_rand_num() {
    random_number=$((RANDOM%100 + 1))
    echo $random_number
}

get_user_input() {
    read num
    echo $num

}

numcmp() {
    num1=$1
    num2=$2

    if [[ $num1 -eq $num2 ]]; then
        echo "Guess correct"
        return 0
    elif [[ $num1 -gt $num2 ]]; then
        echo "Guess incorrect. $num1 is greater than random number"
        return 1
    else
        echo "Guess incorrect. $num1 is less than random number"
        return 1
    fi
}

ran_num=$(make_rand_num)
while true
do
    echo "input a number"
    input_num=$(get_user_input)
    numcmp $input_num $ran_num
    ret=$?
    if [[ $ret -eq 0 ]]; then
        break
    fi


done