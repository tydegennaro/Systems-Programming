#!/bin/bash

# Validate user input
integer="^-?[0-9]+$"
positive_integer="^[0-9]+$"
usage="Usage: ./multsum.sh START STOP MOD"
if [ "$#" -ne "3" ]; then
    echo $usage
    exit
elif [[ ! $1 =~ $integer ]]; then
    echo $usage
    echo START was not a valid integer.
    exit
elif [[ ! $2 =~ $integer ]]; then
    echo $usage
    echo STOP was not a valid integer.
    exit
elif [[ ! $3 =~ $integer ]]; then
    echo $usage
    echo MOD was not a valid integer.
    exit
elif [[ ! $3 =~ $positive_integer ]]; then
    echo $usage
    echo MOD must be positive.
    exit
fi

# Let's give those parameters some names and strip out negatives
start=${1//-/}
stop=${2//-/}
mod=$3

# Define a function that calculates if a number is multsum
is_multsum() {
    sum_of_digits=0
    product_of_digits=1
    for (( num=$1; num>0; num /= 10 )); do
        last_digit=$(($num % 10));
        sum_of_digits=$(( $sum_of_digits + $last_digit ))
        product_of_digits=$(( $product_of_digits * $last_digit ))
    done
    a=$(( $product_of_digits % $mod ))
    b=$(( $sum_of_digits % $mod ))
    if [ "$a" -eq "$b" ]; then
        return 1
    else
        return 0
    fi
}

# Print primes
# for i in $(seq $start $stop); do
for (( i=$start; i<=$stop; i++ )); do
    is_multsum $i
    if [ "$?" -eq "1" ]; then
        echo $i
    fi
done