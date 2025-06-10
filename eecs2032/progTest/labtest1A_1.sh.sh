#!/bin/bash

# Read words from user input
read -p "Enter a list of words separated by spaces: " -a words

# Initialize an associative array to store word counts
declare -A word_counts

# Count occurrences of each word
for word in "${words[@]}"; do
    ((word_counts["$word"]++))
done

# Find the most frequent word
most_frequent=""
max_count=0

for word in "${!word_counts[@]}"; do
    if (( word_counts["$word"] > max_count )); then
        most_frequent=$word
        max_count=${word_counts["$word"]}
    fi
done

# Display results
echo "Most frequent word: $most_frequent"
echo "Occurrences: $max_count"


