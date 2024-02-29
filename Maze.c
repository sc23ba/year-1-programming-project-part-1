#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structures and subroutines
struct Cell {
    int row;
    int column;
    char type;
};

struct Cell ValidateMaze(char* filename) { //this will be the first subroutine that will be run, 
    char line_buffer[50];         //it will take the user's input and validate if the input is valid before doing anything else 
    int countRow = -1;
    int countCol = 0;
    int startCheck = 0;
    int endCheck = 0; 
    struct Cell mazedimensions;
    mazedimensions.column = 1;
    mazedimensions.row = 1;
    mazedimensions.type = ' ';

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Invalid file name, please try again\n");
        return mazedimensions;
    }
    else {
        while (fgets(line_buffer, line_buffer[50], file) != NULL) {
            countCol++;
            if (countRow != -1) {
                countRow = strlen(line_buffer);
            }
            else if (countRow != strlen(line_buffer)){
                return mazedimensions;
            }
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
                return mazedimensions;
            }

        }
    }
    mazedimensions.column = countCol;
    mazedimensions.row = countRow;
    fclose(file);
    printf("check");
    return mazedimensions; 
}

char** LoadMaze(struct Cell dimensions , char* filename) { //is the user's input is valid and the maze itself is valid it will
    char line_buffer[50];                          //then save the 
    char** maze = (char**)malloc(dimensions.row * sizeof(char*));
    int j = 0;

    for (int i = 0; i < dimensions.column; i++) {
        maze[i] = (char*)malloc(dimensions.column * sizeof(char));
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


struct Cell LoadStartPosition(char** maze, struct Cell dimensions) {
    for (int i = 0; i < dimensions.row; i++) {
        for (int j = 0; j < dimensions.column; j++) {
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


struct Cell Move(struct Cell currentLocation, char** maze, struct Cell dimensions, int option) {
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
        if (currentLocation.row + 1 == dimensions.row) {
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
        if (currentLocation.column + 1 == dimensions.column) {
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
        printf("Well done, you won!\n");
        return 1; 
    }
    else{
        return 0;
    }
}

void showMap(char** maze, struct Cell currentPosition, struct Cell dimensions) {
    for (int i = 0; i < dimensions.row; i++) {
        for (int j = 0; j < dimensions.column; j++) {
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
    struct Cell dimensions;
    dimensions.row = 1;
    int option;
    char fileName[50];
    while (dimensions.row == 1){
        printf("Please enter your Maze file name\n");
        scanf(" %s", fileName);
        dimensions = ValidateMaze(fileName);
    }
    char** maze = LoadMaze(dimensions, fileName);
    struct Cell currentPosition = LoadStartPosition(maze, dimensions);

    //the loading phase has ended and the game will then begin
    while(wingame == 0){
        printf("Select Option\n");
        printf("1. Move\n");
        printf("2. See Map\n");
        printf("(enter number option)\n");
        scanf(" %d", &option);

        if(option == 1){

        }
        else if(option == 2){
            showMap(maze,currentPosition,dimensions);
        }
        else{
            printf("Invalid input, please try again");
        }
        wingame = Wincheck(currentPosition);
    }

    return 0;
}
