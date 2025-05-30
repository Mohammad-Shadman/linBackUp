#!/bin/bash

hour=$(date '+%H')

day=$(date '+%A')

timeOfDay=$(date '+%H:%M')

timeNow=$(date '+%Y-%m-%d %H:%M:%S')

greating=""

if [ $hour -gt 4 ] && [ $hour -lt 12 ]
    then 
    greating="Good morning"
fi
if [ $hour -gt 11 ] && [ $hour -lt 18 ]
    then 
    greating="Good afternoon"
fi
if [ $hour -gt 17 ] && [ $hour -lt 22 ]
    then 
    greating="Good evening"
fi
if [ $hour -gt 21 ] || [ $hour -lt 5 ]
    then 
    greating="Good night"
fi

echo "$greating, Mo! Today is $day and the time is $timeOfDay." 

printf "$timeNow - $greating, Mo! Today is $day and the time is $timeOfDay.\n" >> .greeting.log