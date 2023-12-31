// global variable declaration
#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H


//set max length of student ID and name
#define MAX_STU_IDLEN 10
#define MAX_STU_NAMELEN 20

#define DB_NAME "stu_data.db"

//basic struct of student
typedef struct Student {
    char Student_ID[MAX_STU_IDLEN];
    char Name[MAX_STU_NAMELEN];
    char Gender[2];
    int Age;
    double C_Sorce;
    double Math_Sorce;
    double English_Sorce;
    struct Student *next;
    struct Student *prev;
} Student;

//global variable of head pointer
extern Student *head;















#endif