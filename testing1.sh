#!/bin/bash

gcc Maze.c -o first

echo -e "Testing File Input and validation"

echo "Maze1" | ./first > tmp

if grep -q "Invalid file name, please try again\n" tmp;  #this test checks that the file can filter out an incorrect filename
then
    echo "PASS"
else
    echo "FAIL"
fi

echo "Maze1.txt" | ./first > tmp  #this test then checks that the program can validate a valid file and then not only load the file
                                  #as an array but also load the starting position of the starting position 
if grep -q "Select Option\n" tmp; 
then
    echo "PASS"
else
    echo "FAIL"
fi

echo "2" | ./first > tmp

echo "User will need to determine if it is a pass or fail by observing if there is a outputted map and if there is no visible 'S'"
#checks that not only can the program output the file, id validates the claim that it correctly loaded the file and the starting position
echo "1" | ./first > tmp

if grep -q "Please enter your movement(W/A/S/D): " tmp; 
then 
    echo "PASS"
else 
    echo "FAIL"
fi
# checks that the program can tell when a move is invalid and accepts the valid inputs and perfroms their direction correctly 
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

echo "2" | ./first > tmp  #this validates the current location function and shows that the player has moved as intended
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
# this checks that the program finishes when intended and only activated on it's intended cell type
if grep -q "Well dont, you won!" tmp;
then
   echo "PASS"
else
   echo "FAIL"
fi
git

rm -f tmp first




