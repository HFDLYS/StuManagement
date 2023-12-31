#include "stu_file.h"
#include "global.h"

//HFDLYS 2023/11/28

//Save student info to database
void saveStuInfo() {
    //Load the database
    char *errMsg = NULL;
    sqlite3 *db = NULL;
    int ret = sqlite3_open("stu_data.db", &db);
    if (ret) {
        printf("No ideas to open database!🤔\n");
        return;
    }
    /*
    printf("Warning!!!This operate will rewirte the orginal data in database!!!\n");
    printf("Do you want to continue? (n or q to exit)");
    char choice[1000];
    scanf("%s", choice);
    if (choice[0] == 'n' || choice[0] == 'q' || choice[0] == 'N' || choice[0] == 'Q') {
        return;
    }
    */
    const char *drop = "DROP TABLE IF EXISTS Students";
    ret = sqlite3_exec(db, drop, NULL, NULL, &errMsg);
    if (ret) {
        printf("Failed to rewrite table!😭\n");
        printf("wrong: %s\n", errMsg);
        sqlite3_close(db);
        return;
    }
    //Create table
    char *create = "CREATE TABLE Students ( "
    "Student_ID VARCHAR(%d), "
    "Name VARCHAR(%d), "
    "Gender VARCHAR(2), "
    "Age INTEGER, "
    "C_Score REAL, "
    "Math_Score REAL, "
    "English_Score REAL, "
    "PRIMARY KEY (Student_ID) "
    ")";
    char *sql_cmd = malloc(strlen(create) + 100);
    sprintf(sql_cmd, create, MAX_STU_IDLEN, MAX_STU_NAMELEN);
    ret = sqlite3_exec(db, sql_cmd, NULL, NULL, &errMsg);
    if (ret) {
        printf("Failed to create table!😭\n");
        printf("wrong: %s\n", errMsg);
        sqlite3_close(db);
        return;
    }
    char *insert = "INSERT INTO Students VALUES ( "
    "'%s', '%s', '%s', %d, %.2lf, %.2lf, %.2lf )";
    
    //Write data to database
    Student *p = head;
    while (p != NULL) {
        char *sql_cmd = malloc(strlen(insert) + 100);
        sprintf(sql_cmd, insert, p->Student_ID, p->Name, p->Gender, p->Age, p->C_Sorce, p->Math_Sorce, p->English_Sorce);
        ret = sqlite3_exec(db, sql_cmd, NULL, NULL, &errMsg);
        if (ret) {
            printf("Failed to save data!😭\n");
            printf("wrong: %s\n", errMsg);
            sqlite3_close(db);
            return;
        }
        printf("Saving data with student %s\n", p->Student_ID);
        p = p->next;
    }
    printf("Save successfully!👍\n");
    sqlite3_close(db);
    return;
}


//Load student info from database
void loadStuInfo() {
    sqlite3 *db = NULL;
    
    int ret = sqlite3_open("stu_data.db", &db);
    if (ret) {
        printf("No ideas to open database!🤔\n");
        return NULL;
    }
    const char *query = "SELECT name FROM sqlite_master WHERE type='table' AND name='Students'";
    sqlite3_stmt *stmt;
    ret = sqlite3_prepare_v2(db, query, -1, &stmt, 0);
    if (sqlite3_step(stmt) != SQLITE_ROW) {
        printf("Have your ever saved data successfully🤔\n");
        sqlite3_close(db);
        return NULL;
    }
    sqlite3_finalize(stmt);
    //Load data from database

    Student *pre = NULL;
    const char *select = "SELECT * FROM Students";
    ret = sqlite3_prepare_v2(db, select, -1, &stmt, 0);
    if (ret == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            //copy data
            const unsigned char *Student_ID = sqlite3_column_text(stmt, 0);
            const unsigned char *Name = sqlite3_column_text(stmt, 1);
            const unsigned char *Gender = sqlite3_column_text(stmt, 2);
            int Age = sqlite3_column_int(stmt, 3);
            double C_Sorce = sqlite3_column_double(stmt, 4);
            double Math_Sorce = sqlite3_column_double(stmt, 5);
            double English_Sorce = sqlite3_column_double(stmt, 6);
            Student *q = (Student *)malloc(sizeof(Student));
            strcpy(q->Student_ID, Student_ID);
            strcpy(q->Name, Name);
            strcpy(q->Gender, Gender);
            q->Age = Age;
            q->C_Sorce = C_Sorce;
            q->Math_Sorce = Math_Sorce;
            q->English_Sorce = English_Sorce;
            //insert to list
            if (pre == NULL) {
                head = q;
            } else {
                pre->next = q;
            }
            q->prev = pre;
            q->next = NULL;
            pre = q;
            printf("Loading data with student %s\n", q->Student_ID);
        }
    } else {
        printf("Something unexpected happened!😭\n");
        sqlite3_close(db);
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);
    printf("Load successfully!👍\n");
    sqlite3_close(db);
    return;
}