/*
Name: KevinKumar Patel
Student Number: 8913814
Project Name: patel-k
Description: The "assessgrade.h" header file provides function declarations for evaluating grades based on various criteria, including a text input, a double input, and an array of integer input.
Date: 20/05/2023
*/
#ifndef ASSESSGRADE_H
#define ASSESSGRADE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

#define MAX_INPUT_LENGTH 100

void assessGrade(char* grade);
void assessGrade(double mark);
void assessGrade(int marks[]);

void parseUserInput(char* input);
#endif
