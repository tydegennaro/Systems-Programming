#!/bin/bash

#   CSC 399: Systems Programming

# Program Name:
#   mybackup.sh

# Program Purpose:
#   This script makes a backup of recently modified files in
#   your home directory. You can (optionally) specify how far
#   back to go (in hours) for a file to be consired recent

# Author(s):
#   Kyle DeGennaro
#   Tyler DeGennaro
#   Joey Germain



# Validate input
if [ "$#" -gt "1" ]; then
    echo "USAGE: mybackup.sh [AGE]"
    exit
elif [ "$#" -eq "0" ]; then
    age=24
elif [[ ! $1 =~ ^[0-9]+$ ]]; then
    echo "USAGE: mybackup.sh [AGE]"
    echo "AGE is optional, but must be an integer"
    exit
else
    age=$1
fi

# Make sure backups directory exists
mkdir -p $HOME/Backups

# Create the archive
find $HOME -mmin -$(( age * 60 )) | tail -n +2 | tar -cf $HOME/Backups/backup.$(date +%Y.%m.%d.%H.%M).tgz -T -
