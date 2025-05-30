#!/bin/bash

argnum=4
string="$1 - "

while [ $argnum -le $# ]
do 
    string+=" ${!argnum}"
    ((argnum++))
done

echo $string
