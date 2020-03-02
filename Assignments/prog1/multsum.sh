#!/bin/bash

# Course: 
#   CSC 399: Systems Programming

# Program Name: 
#   multsum.sh

# Program Purpose:
#    Program will print which numbers are a multsum, given a range
#    `START` to `FINISH` and a number to `MOD` by.

# Author(s):
#   Kyle DeGennaro
#   Tyler DeGennaro
#   Joey Germain

# Regex pattern to enure the argument passed is an integer
integer="^-?[0-9]+$"

# Regex pattern to enure the argument passed is a positive integer
positiveInteger="^[0-9]*[1-9][0-9]*$"

# Usage message
usage="Usage: ./multsum START STOP MOD"

# Validate user input, ensure there are three arguments passed
if [ "$#" -ne "3" ]; then
    echo $usage
    exit
# Check to make sure argument one `START` is an integer
elif [[ ! $1 =~ $integer ]]; then
    echo $usage
    exit
# Check to make sure argument two `STOP` is an integer
elif [[ ! $2 =~ $integer ]]; then
    echo $usage
    exit
# Check to make sure argument three `MOD` is a positive integer
elif [[ ! $3 =~ $positiveInteger ]]; then
    echo $usage
    exit
fi

START=${1}
STOP=${2}
MOD=${3}

# Function: isMultSum()
# Determines whether or not the argument passed
# `$1` is a multsum number. 
isMultSum() {
	sumOfDigits=0
	productOfDigits=1
	# Variable to store the arugment passed
	absNumber=${1#-}
	#echo ${absNumber}
	lengthOfNumber=${#absNumber}
	# For each digit in the number `number`
	for (( j=0; j<${lengthOfNumber}; j++ )); do
		digit=${absNumber:$j:1}
		sumOfDigits=$(( ${sumOfDigits}+${digit}  ))
		productOfDigits=$(( ${productOfDigits}*${digit} ))
	done
	# Check if the number is a multsum
	if [[ $(($sumOfDigits % $MOD)) == $(($productOfDigits % $MOD)) ]]
	then
		return 1
	else
		return 0
	fi	
}

for (( i=${START}; i<=${STOP}; i++ )); do
	isMultSum $i
	# If the number is a multsum (1 is returned)
	if [[ ${?} == 1 ]]; then
		# print the number
		echo ${i}
	fi
done
