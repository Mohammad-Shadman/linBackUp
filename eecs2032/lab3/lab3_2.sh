#!/bin/bash

generate_random_number(){
    local min=1
    local max=100
    random_number=$(( ( RANDOM % (max-min+1) ) + min ))
    
}

play_game(){
    generate_random_number
    echo "Welcome to the Number Guessing Game! I have selected a number between 1 and 100. Can you guess it? Enter your guess (or type ’exit’ to quit):"
    n=0
    attempts=0
    while [[ $n -ne $random_number ]]; do
        echo -n "Enter a positive Integer (1-100): "
        read n
        if [[ $n = exit ]]
        then 
        echo "good bye, number was $random_number"
        exit
        fi
        if [[ $n != [1-9] && $n != [0-9][0-9] && $n != 100 ]]
            then
            echo "Error: Enter a Valid Positive Integer (1-100)"
            continue
        fi
        attempts=$((attempts+1))
        if [[ $n -lt $random_number ]]
            then
            echo "Guess too low"
        elif [[ $n -gt $random_number ]]
            then
            echo "Guess too high"
        else
            echo "Guess is correct"
        fi

    done
    echo "Correct number was $random_number"
    echo "Number of attempts was $attempts"
}


play_game