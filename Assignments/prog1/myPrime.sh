#!/bin/bash

# Validate user input
integer="^[0-9]+$"
usage="Usage: ./myPrime START_NUMBER END_NUMBER"
if [ "$#" -ne "2" ]; then
    echo $usage
    exit
elif [[ ! $1 =~ $integer ]]; then
    echo $usage
    echo START_NUMBER was not a valid integer.
    exit
elif [[ ! $2 =~ $integer ]]; then
    echo $usage
    echo END_NUMBER was not a valid integer.
    exit
fi

# Define a function that calculates primes in linear time
isprime() {
    for (( j=2; j<$1; j++ )); do
        if [[ $(($1 % $j)) == 0 ]]; then
            return 0
        fi
    done
    
    return 1
}

# Print primes
for (( i = $1; i <= $2; i++ )); do
    isprime $i
    if [ "$?" -eq "1" ]; then
        echo $i
    fi
done