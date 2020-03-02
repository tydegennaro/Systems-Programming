#!/bin/bash

# Course: 
#   CSC 399: Systems Programming

# Program Name: 
#   myPrime.sh

# Program Purpose:
#   This script takes two integers as arguments, 
#   and prints all prime numbers from `START_NUMBER` ($1) to `END_NUMBER` ($2)

# Author(s):
#   Kyle DeGennaro
#   Tyler DeGennaro
#   Joey Germain


# Regex pattern to enure the argument passed is an integer
integer="^[0-9]+$"
usage="Usage: ./myPrime START_NUMBER END_NUMBER\nPrints all primes from START to END numbers."

# Validate user input, ensure there are two arguments passed
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

# Function: isPrime()
# Determines whether or not the argument passed
# `$1` is a prime number. 
isPrime() {
    for (( j=2; j<$1; j++ )); do
        if [[ $(($1 % $j)) == 0 ]]; then
            return 0
        fi
    done
    return 1
}

# For loop to check each number from
# `$1` to `$2` range... (START_NUMBER to END_NUMBER)
for (( i = $1; i <= $2; i++ )); do
    isPrime $i
    if [ "$?" -eq "1" ]; then
        echo $i
    fi
done