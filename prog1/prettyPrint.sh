#!/bin/bash

# Course: 
#   CSC 399: Systems Programming

# Program Name: 
#   prettyPrint.sh

# Program Purpose:
#   This script takes a list of files as arguments (file1.txt, file2.txt, file3.txt ...)
#   It will concatenate all the files into a single file (temp_out_file.txt) and will then use
#   ensciprt to convert the file (temp_out_file.txt) into a PostScript file (with the file extension .ps).
#   Once converted to a PostScript file (printMe.ps), the PostScript file is then
#   converted to a PDF file (printMe.pdf).

# Author(s):
#   Kyle DeGennaro
#   Tyler DeGennaro
#   Joey Germain

# Dependencies:
#   brew install enscript
#   brew install ghostscript


# Create a variable for the temp_out_file.txt file
TEMP_OUT_FILE=temp_out_file.txt

# Create a variable for the printMe.ps file
POST_SCRIPT_FILE=printMe.ps

# Clear the existing TEMP_OUT_FILE if it already exists
echo "" > ${TEMP_OUT_FILE}

# This function takes a file as an argument, and will concatenate the file
# it receives as an argument to the TEMP_OUT_FILE (temp_out_file.txt)
function concatenateFileToTempOutFile {
    echo "------------- ${1} -------------" >> "${TEMP_OUT_FILE}"
    cat $1 >> "${TEMP_OUT_FILE}"
    echo >> "${TEMP_OUT_FILE}"
}

# Iterate through each argument (In our case, each file name) passed upon executing the script
# The "$@" refers to all of the shell script's command-line arguments
for fileName in "$@"
do
    # This conditional checks if the file exists
    if [ -f $fileName ]; then
        printf "Appending file: ${fileName}\n"
        concatenateFileToTempOutFile $fileName
    else
        printf "File ${fileName} does not exist, ignoring.\n"
    fi  
done

# Run the enscript command with the TEMP_OUT_FILE (In which should now have all our files concatenated as one)
# and convert the TEMP_OUT_FILE to a PostScript file, with 2 columns. 
# The -p flag for the enscript command specifies the output for the PostScript file. In our case,
# ./printMe.ps
enscript ${TEMP_OUT_FILE} –columns=2 -p ${POST_SCRIPT_FILE}

# Convert the POST_SCRIPT_FILE (printMe.ps) to a PDF file
# By default, the ps2pdf command will use the file name from the PostScript file
# So, the result from running this command should be printMe.pdf
ps2pdf ${POST_SCRIPT_FILE}