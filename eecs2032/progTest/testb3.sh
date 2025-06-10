#!/bin/bash

if [[ $# -ne 1 ]]
then 
echo bad input
exit 1
fi

sed -n '/./p' "$1" | wc -l
