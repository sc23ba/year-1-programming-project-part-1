#!/bin/bash

gcc Maze.c -o first

echo -e "Testing File Input and validation"

echo "Maze1" | ./first > tmp

if grep -q "Invalid file name, please try again\n" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo "Maze1.txt" | ./first > tmp

if grep -q "Select Option\n" tmp; 
then
    echo "PASS"
else
    echo "FAIL"
fi

echo "2" | ./first > tmp

echo "User will need to determine if it is a pass or fail by observing if there is a outputted map and if there is no visible 'S'"

echo "1" | ./first > tmp

if grep -q "Please enter your movement(W/A/S/D): " tmp;
then 
    echo "PASS"
else 
    echo "FAIL"
fi

echo "W" | ./first > tmp
if grep -q "Invalid movement, please try again.\n" tmp;
then 
    echo "PASS"
else 
    echo "FAIL"
fi
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "D" | ./first > tmp
echo "1" | ./first > tmp
echo "S" | ./first > tmp
echo "1" | ./first > tmp
echo "S" | ./first > tmp
echo "1" | ./first > tmp
echo "S" | ./first > tmp
echo "1" | ./first > tmp
echo "S" | ./first > tmp

echo "2" | ./first > tmp
if grep -q "##########
            #S       #
            #   #### #
            #     #  #
            # ####   #
            #      EX#
            ##########" tmp;
then 
    echo "PASS"
else 
    echo "FAIL"
fi

echo "W" | ./first > tmp

if grep -q "Well dont, you won!" tmp;
then
   echo "PASS"
else
   echo "FAIL"
fi


rm -f tmp first




