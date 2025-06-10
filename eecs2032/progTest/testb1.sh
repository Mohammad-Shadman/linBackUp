#!/bin/bash

if [[ $# -ne 3 ]]
then 
    echo bad input
    exit 1
fi

ass=1
des=1
read -a arr <<< "$@"
for i in {1..2}
do
    if [[ ${arr[$i]} -le ${arr[$[$i-1]]} ]]
    then 
    ass=0
    fi
    if [[ ${arr[$i]} -ge ${arr[$[$i-1]]} ]]
    then
    des=0
    fi
    if [[ ${arr[$i]} -eq ${arr[$[$i-1]]} ]]
    then 
    ass=0
    des=0
    fi
done

if [[ $ass -eq 1 ]]
then
echo ASSENDING
fi
if [[ $des -eq 1 ]]
then 
echo DESCENDING
fi
if [[ $des -eq $ass ]]
then
echo NEITHER
fi