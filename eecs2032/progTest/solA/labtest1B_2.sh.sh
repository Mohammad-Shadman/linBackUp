#!/bin/bash

# Check if exactly one argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <file path>"
    exit 1
fi

file="$1"

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "Error: File '$file' not found."
    exit 1
fi

# Check if the file is empty
if [ ! -s "$file" ]; then
    echo "The file is empty."
    exit 1
fi

# Find the shortest line
shortest_line=""
min_length=-1

while IFS= read -r line; do
    line_length=${#line}
    
    if [ "$min_length" -eq -1 ] || [ "$line_length" -lt "$min_length" ]; then
        shortest_line="$line"
        min_length="$line_length"
    fi
done < "$file"

# Display the shortest line and its correct character count
echo "Shortest line ($min_length characters):"
echo "\"$shortest_line\""