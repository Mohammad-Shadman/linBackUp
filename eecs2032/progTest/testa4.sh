#!/bin/bash

IFS=$'\t'

while read ProductID productName Price inventory
do
    if [[ $inventory -ge $[ $1-1 ] && $inventory -le $[ $1+1 ] ]]
    then 
        echo "$ProductID $productName"
    fi
done < 'inv.txt'