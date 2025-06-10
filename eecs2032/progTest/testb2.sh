#!/bin/bash

read x1
read x2
while read x3
do
    if [[ $[$x1+$x2] -lt $x3 ]]
    then 
        echo $x3
        break
    fi
    x1=$x2
    x2=$x3
done