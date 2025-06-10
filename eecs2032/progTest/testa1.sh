#!/bin/bash

i=$[ $1+1 ]

while [[ i -lt $2 ]] 
do
    echo -n "$i "
    i=$[$i+1]
done
echo ""