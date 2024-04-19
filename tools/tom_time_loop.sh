#!/bin/bash
# Infinite loop that waits for the user input
echo "Welcome to Tom time Loop"
while true
do
    echo "Type 'q' to quit the script, or wait for 10 seconds to prompt again."
    # Wait for user input with a timeout
    read -t 10 -p "Input: " input

    # Check if the user wants to exit
    if [[ $input == "q" ]]; then
        echo "Exiting the script."
        break
    fi

    # Validate input to ensure it's not a dangerous command
    if [[ "$input" == "rm" || "$input" == "dd" ]]; then
        echo "Forbidden command. Please enter a different input."
        continue
    fi

    # Sleep for a bit - this is optional since read already has a timeout
    echo "Waiting for more input..."
done
