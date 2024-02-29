#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structures and subroutines
struct Cell {
    int row;
    int column;
    char type;
};

int ValidateMaze(char* filename) { //this will be the first subroutine that will be run, 
    char line_buffer[50];         //it will take the user's input and validate if the input is valid before doing anything else 
    int count = 0;
    int startCheck = 0;
    int endCheck = 0; 
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Invalid file name, please try again\n");
        return 1;
    }
    else {
        while (fgets(line_buffer, line_buffer[50], file) != NULL) {
            count++;
        }
    }
    rewind(file);
    //this initial section is influenced from code I made for coursework in a previous universityu module "Procedural programming"

    while (fgets(line_buffer, line_buffer[50], file) != NULL) 
    {
        for (int i = 0; i < strlen(line_buffer); i++) {
            if (line_buffer[i] == '#' || ' ') {
              
            }
            else if (line_buffer[i] == 'E' && endCheck == 0) {
                endCheck = 1;
            }
            else if(line_buffer[i] == 'S' && startCheck == 0){
                startCheck = 1;
            }
            else{
                return 1;
            }

        }
        if (count != strlen(line_buffer)) {
            return 1;
        }
    }
    fclose(file);
    return count; 
}

char** LoadMaze(const int count, char* filename) { //is the user's input is valid and the maze itself is valid it will
    char line_buffer[50];                          //then save the 
    char** maze = (char**)malloc(count * sizeof(char*));
    int j = 0;

    for (int i = 0; i < count; i++) {
        maze[i] = (char*)malloc(count * sizeof(char));
    }
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("");
        return NULL;
    }
    while (fgets(line_buffer, 50, file) != NULL)
    {
        for (int i = 0; i < strlen(line_buffer); i++) {
            maze[j][i] = line_buffer[i];
        }
        j++;
    }
    fclose(file);
    return maze;
}


struct Cell LoadStartPosition(char** maze, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (maze[i][j] = 'S') {
                struct Cell currentLocation;
                currentLocation.row = i;
                currentLocation.column = j;
                currentLocation.type = 'S';
                return currentLocation;
            }
        }
    }
}

int GetInput() {
    int errorCheck = 0;
    char option; 
    while (errorCheck == 0){
        printf("\n");
        printf("Please enter your movement(W/A/S/D): ");
        scanf(" %c", &option);
        printf("\n");
        if (option == 'A' || option == 'a') {
            return 1;
        }
        else if (option == 'W' || option == 'w') {
            return 2;
        }
        else if (option == 'D' || option == 'd') {
            return 3;
        }
        else if (option == 'S' || option == 's') {
            return 4;
        }
        else{
            printf("Invalid Input, please try again. ");
        }


    };
}


struct Cell Move(struct Cell currentLocation, char** maze, int count, int option) {
    if (option == 1) {
        if (currentLocation.row - 1 == -1) {
            printf("Invalid movement, please try again.\n");
        }
        else if (maze[currentLocation.row - 1][currentLocation.column] = '#') {
            printf("Invalid movement, please try again.\n");
        }
        else{
            currentLocation.type = maze[currentLocation.row - 1][currentLocation.column];
            currentLocation.row += -1;       
        }
        return currentLocation;
    }
    else if (option == 2) {
        if (currentLocation.column - 1 == -1) {
            printf("Invalid movement, please try again.\n");
        }
        else if (maze[currentLocation.row][currentLocation.column - 1] = '#') {
            printf("Invalid movement, please try again.\n");
        }
        else {
            currentLocation.type = maze[currentLocation.row][currentLocation.column - 1];
            currentLocation.column += -1;
        }
        return currentLocation;
    }
    else if (option == 3) {
        if (currentLocation.row + 1 == count) {
            printf("Invalid movement, please try again.\n");
        }
        else if (maze[currentLocation.row + 1][currentLocation.column] = '#') {
            printf("Invalid movement, please try again.\n");
        }
        else {
            currentLocation.type = maze[currentLocation.row + 1][currentLocation.column];
            currentLocation.row += 1;
        }
        return currentLocation;
    }
    else if (option == 4) {
        if (currentLocation.column + 1 == count) {
            printf("Invalid movement, please try again.\n");
        }
        else if (maze[currentLocation.row][currentLocation.column + 1] = '#') {
            printf("Invalid movement, please try again.\n");
        }
        else {
            currentLocation.type = maze[currentLocation.row][currentLocation.column + 1];
            currentLocation.column += 1;
        }
        return currentLocation;
    }
}

int Wincheck(struct Cell currentPosition)
{
    if (currentPosition.type == 'E') {
        return 1; 
    }
    else{
        return 0;
    }
}

void showMap(char** maze, struct Cell currentPosition, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (currentPosition.row == i && currentPosition.column == j) {
                printf("X");
            }
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}





//

int main() {
    int wingame = 0;
    int option;
    int count = 1;
    char fileName[50];
    while (count == 1)
    {
        printf("Please enter your Maze file name\n");
        scanf(" %s", fileName);
        count = ValidateMaze(fileName);
    }

    return 0;
}
