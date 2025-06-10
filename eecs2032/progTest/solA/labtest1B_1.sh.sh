#!/bin/bash

# Prompt user for input
read -p "Enter a list of words separated by spaces: " -a words

# Declare variables
declare -A word_lengths
max_length=0

# Iterate through the words and store their lengths
for word in "${words[@]}"; do
    length=${#word}
    word_lengths["$word"]=$length

    # Update max_length if a longer word is found
    if (( length > max_length )); then
        max_length=$length
    fi
done

# Find the longest word(s)
longest_words=()
for word in "${!word_lengths[@]}"; do
    if (( word_lengths["$word"] == max_length )); then
        longest_words+=("$word")
    fi
done

# Display the results
echo "Longest word(s): ${longest_words[*]}"
echo "Length: $max_length"

