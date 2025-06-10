#!/bin/bash

# Check if the file path argument is provided
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <file_path>"
    exit 1
fi

file_path="$1"

# Check if the file exists
if [[ ! -f "$file_path" ]]; then
    echo "Error: File '$file_path' not found."
    exit 1
fi

# Initialize variables
max_length=0
longest_line=""

# Read the file line by line
while IFS= read -r line; do
    length=${#line}  # Get the length of the current line
    if (( length > max_length )); then
        max_length=$length
        longest_line="$line"
    fi
done < "$file_path"

# Check if the file is empty
if [[ $max_length -eq 0 ]]; then
    echo "The file is empty."
else
    echo "Longest line ($max_length characters):"
    echo "\"$longest_line\""
fi