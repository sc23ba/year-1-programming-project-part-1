#!/bin/bash

echo -e "Testing File Input and validation"

echo "Maze1" | ./first > tmp

if grep -q "Invalid file name, please try again\n" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo "Maze1.txt"




