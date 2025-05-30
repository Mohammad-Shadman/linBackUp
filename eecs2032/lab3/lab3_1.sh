#!/bin/bash

if [[ $# -ne 2 ]]
    then 
    echo "You should enter 2 numbers!"
    exit
fi
if [[ $1 -eq $2 ]]
    then
    echo "These two numbers are equal!"
    exit
fi
if [[ $1 -gt $2 ]]
    then
    big_num=$1
    small_num=$2
else
    big_num=$2
    small_num=$1
fi

let d=big_num%small_num
if [[ $d -eq 0 ]]
    then 
    let n=big_num/small_num
    echo "$big_num is $n times the small_num!"
    exit
fi

echo No relation!