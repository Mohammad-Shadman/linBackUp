#!/bin/bash

IFS=$':'

while read bid btitle bauthor bcopies
do 
    while read id copies
    do
        if [[  id -eq bid ]] && [[ bcopies -lt copies ]]
            then
            echo "$btitle"
        fi
    done < "borrowed.txt"
done < "books.txt"