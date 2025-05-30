#!/bin/bash

if [ 0 -eq $# ]
    then
    echo "No arguments provided"
    exit
fi

read -p "Please enter an integer: " x

if [ $x -le $# ] && [ $x -ge 1 ]
    then
    echo "The argument at position $x is: ${!x}" 
    exit
fi

echo "No argument has been provided at position $x."
