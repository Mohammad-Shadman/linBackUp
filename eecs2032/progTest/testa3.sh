#!/bin/bash


while read x1 x2 x3 x4
do
    if [[ $x1 -gt $[ $x2 + $x3 ] ]]
    then 
        echo "$x1 $x2 $x3 $x4"
    fi
done < "p2a.txt"