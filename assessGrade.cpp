/*
Name: KevinKumar Patel
Student Number: 8913814
Project Name: patel-k
Description: The provided code provides methods that compute and output grades in response to a variety of input formats, including letter grades, numerical scores, and an array of scores.
Date: 20/05/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assessGrade.h"
#pragma warning(disable:4996)
/*Function: assessGrade(char* grade)
* Paramters: char* grade: the grade to be assesssed.
* Description: The provided grade is evaluated and the related information about the students performance is printed.
* Return: None
*/
void assessGrade(char* grade) {
    if (strcmp(grade, "A+") == 0) {
        printf("Student achieved 95.00 %% which is a PASS condition.\n");
    }
    else if (strcmp(grade, "A") == 0) {
        printf("Student achieved 85.00 %% which is a PASS condition.\n");
    }
    else if (strcmp(grade, "B+") == 0) {
        printf("Student achieved 77.00 %% which is a PASS condition.\n");
    }
    else if (strcmp(grade, "B") == 0) {
        printf("Student achieved 72.00 %% which is a PASS condition.\n");
    }
    else if (strcmp(grade, "C+") == 0) {
        printf("Student achieved 67.00 %% which is a PASS condition.\n");
    }
    else if (strcmp(grade, "C") == 0) {
        printf("Student achieved 62.00 %% which is a PASS condition.\n");
    }
    else if (strcmp(grade, "D") == 0) {
        printf("Student achieved 57.00 %% which is a FAIL condition.\n");
    }
    else if (strcmp(grade, "F") == 0) {
        printf("Student achieved 50.00 %% which is a FAIL condition.\n");
    }
    else if (strcmp(grade, "I") == 0) {
        printf("Student has Special Situation : Incomplete\n");
    }
    else if (strcmp(grade, "Q") == 0) {
        printf("Student has Special Situation : Withdrawal After Drop/Refund Date\n");
    }
    else if (strcmp(grade, "AU") == 0) {
        printf("Student has Special Situation : Audit Condition\n");
    }
    else if (strcmp(grade, "DNA") == 0) {
        printf("Student has Special Situation : Did Not Attend\n");
    }
    else if (strcmp(grade, "I/P") == 0) {
        printf("Student has Special Situation : In Process\n");
    }
    else {
        printf("**ERROR : Invalid Input\n");
    }
}
/*Function: assessGrade(double mark)
* Paramters: double mark: the marks to be finalised.
* Description: checks if the marks is in given range.
* Return: None
*/
void assessGrade(double mark) {
    if (mark > 0.0 && mark <= 100.0) {
        printf("Student achieved %.2f %% which is a %s condition.\n", mark, mark >= 50.0 ? "PASS" : "FAIL");
    }
    else {
        printf("**ERROR : Invalid Input\n");
    }
}
/*Function: assessGrade(int mark[])
* Paramters: int mark[]: array of 5 characters
* Description: takes the sum and average of the five marks entered.
* Return: None
*/
void assessGrade(int marks[]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += marks[i];
    }

    double average = sum / 5.0;
    printf("Student achieved % .2f %%", average);
    printf(" which is a % s condition.\n", average >= 50.0 ? "PASS" : "FAIL");
}
/*Function: parseInput(char* input)
* Paramters: char* input: string of character input.
* Description: parse input as per the requirments using while loop and if conditions.
* Return: None
*/
void parseUserInput(char* input) {
    if (strcmp("A+", input) == 0 || strcmp("A", input) == 0 || strcmp("B+", input) == 0 || strcmp("B", input) == 0 || strcmp("C+", input) == 0 || strcmp("C", input) == 0 || strcmp("D", input) == 0 || strcmp("F", input) == 0 || strcmp("I", input) == 0 || strcmp("Q", input) == 0 || strcmp("AU", input) == 0 || strcmp("DNA", input) == 0 || strcmp("I/P", input) == 0)
    {
        assessGrade(input);
        return;
    }
    else if (input[0] > '9' || input[0] < '0') {
        printf("**ERROR : Invalid Input\n");
        return;
    }
    char* token = strtok(input, " ");
    int count = 0;
    int marks[5] = {};

    while (token != NULL) {
        double number = atof(token);
        if (number < 0 || number > 100) {
            printf("**ERROR : Invalid Input\n");
            return;
        }
        if (number != (int)number) {
            assessGrade(number);
            count = 0;
            return;
        }
        marks[count++] = number;
        token = strtok(NULL, " ");
    }

    if (count > 0) {
        assessGrade(marks);
        return;
    }

    printf("**ERROR : Invalid Input\n");
}
