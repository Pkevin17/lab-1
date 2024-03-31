/*
Name: KevinKumar Patel
Student Number: 8913814
Project Name: patel-k
Description: An interactive interface for entering and evaluating student marks is provided by this C programme, which accepts both file input and direct human input.
Date: 20/05/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assessGrade.h"
int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Enter Student's Grade(s) >>> ");
        fgets(input, sizeof(input), stdin);
        //remove newline character from input string
        input[strcspn(input, "\n")] = '\0'; 

        if (input[0] == 'X') {
            break;
        }
        else if (input[0] == 'Z') {
            //extract filename from input string
            char* fname = input + 2;
            FILE* file = fopen(fname, "r");
            printf("HI\n");
            if (file == NULL) {
                printf("File I/O ERROR\n");
                continue;
            }

            char line[MAX_INPUT_LENGTH];
            while (fgets(line, sizeof(line), file) != NULL) {
                line[strcspn(line, "\n")] = '\0'; 
                parseUserInput(line);
            }
            //close the file
            fclose(file);
        }
        else {
            //process user input
            parseUserInput(input);
        }
    }

    return 0;
}