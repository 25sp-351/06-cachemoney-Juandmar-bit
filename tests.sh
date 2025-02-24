#!/bin/bash

# Compile the program
make rebuild

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Define the expected outputs for the tests
declare -a expected_outputs=(
    "one thousand five hundred"
    "thirty two dollars and forty four cents"
    "thirty four cents"
    "The value is not an integer."
    "The value is greater than one thousand five hundred dollars."
    "The value is not an integer."
    "The value contains non-positive integers."
    "three hundred twenty four dollars thirty three cents"
    "thirty two dollars forty four cents"
)

# Run the program and capture the output
output=$(./money_to_string)

echo "Raw output from the program:"
echo "$output"

# Clean up any blank lines or unwanted lines
cleaned_output=$(echo "$output" | grep -v '^\s*$')

# Count the number of lines in the cleaned output
num_lines=$(echo "$cleaned_output" | wc -l)

# Check if the number of lines in the output matches the number of test cases
if [ "$num_lines" -ne "${#expected_outputs[@]}" ]; then
    echo "Error: The number of output lines ($num_lines) does not match the number of expected tests (${#expected_outputs[@]})"
    exit 1
fi

# Process the output and compare with expected outputs
index=0
echo "$cleaned_output" | while IFS= read -r line; do
    expected_output="${expected_outputs[$index]}"

    # Check if the output matches the expected output
    if [[ "$line" == *"$expected_output"* ]]; then
        echo "Test $((index+1)) passed"
    else
        echo "Test $((index+1)) failed"
        echo "Expected: $expected_output"
        echo "Got: $line"
    fi
    ((index++))
done

# Clean up
make clean
