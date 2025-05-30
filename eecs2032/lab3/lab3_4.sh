#!/bin/bash


echo -n "Enter a list of words seperated by spaces: "

declare -a array
declare -A assarray

read array

for word in $array; do

    if [[ assarray[$word] -gt 0 ]] ; then
        assarray[$word]=$((assarray[$word]+1))
    else
        assarray+=([$word]=1)
    fi

done

greatest=""
num=0

for key in "${!assarray[@]}"; do
    if [[ ${assarray[$key]} -gt $num ]]; then
        greatest="$key"
        num=${assarray[$key]}
    fi
done

echo Most frequent word: $greatest 
echo Occurrences: $num
