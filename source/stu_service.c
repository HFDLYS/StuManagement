#include "stu_service.h"
#include "global.h"
#include "show_ui.h"

//HFDLYS 2023/11/29

//Add student info
void addStuInfo() {
    showAddWindow();
    /*
    //For safe
    if (head == NULL) {
        printf("Warning!!!You haven't load the data, which may lead to clash with orginal data!!!\n");
        printf("Do you want to continue? (n to exit)");
        char choice[1000];
        scanf("%s", choice);
        if (choice[0] == 'n') {
            return;
        }
    }
    //New student node
    Student *p = malloc(sizeof(Student));
    printf("Please enter student ID: ");
    scanf("%s", p->Student_ID);
    printf("Please enter student name: ");
    scanf("%s", p->Name);
    printf("Please enter student gender: ");
    char temp;
    scanf("%c", &temp);
    while ((temp) != 'F' && (temp) != 'M' && ((temp) != 'f') && ((temp) != 'm' )) {
        scanf("%c", &temp);
        continue;
    }
    p->Gender[0] = temp;
    p->Gender[1] = '\0';
    printf("Please enter student age: ");
    scanf("%d", &p->Age);
    printf("Please enter student C sorce: ");
    scanf("%lf", &p->C_Sorce);
    printf("Please enter student Math sorce: ");
    scanf("%lf", &p->Math_Sorce);
    printf("Please enter student English sorce: ");
    scanf("%lf", &p->English_Sorce);
    //Insert to head🤗
    p->prev = NULL;
    p->next = head;
    if ((head) != NULL) {
        (head)->prev = p;
    }
    head = p;
    */
    return;
}

//Display student info
void displayStuInfo() {
    showStuInf(head);
    Student *p = head;
    
    printf("ID\tName\tGender\tAge\tC\tMath\tEnglish\n");
    
    while (p!= NULL) {
        printf("%s\t%s\t%s\t%d\t%.2lf\t%.2lf\t%.2lf\n", p->Student_ID, p->Name, p->Gender, p->Age, p->C_Sorce, p->Math_Sorce, p->English_Sorce);
        p = p->next;
    }
    return;
}

//Swap the data of two student
void Swap(Student *p, Student *q) {
    Student temp;
    temp = *p;
    strcpy(p->Student_ID, q->Student_ID);
    strcpy(p->Name, q->Name);
    strcpy(p->Gender, q->Gender);
    p->Age = q->Age;
    p->C_Sorce = q->C_Sorce;
    p->Math_Sorce = q->Math_Sorce;
    p->English_Sorce = q->English_Sorce;
    strcpy(q->Student_ID, temp.Student_ID);
    strcpy(q->Name, temp.Name);
    strcpy(q->Gender, temp.Gender);
    q->Age = temp.Age;
    q->C_Sorce = temp.C_Sorce;
    q->Math_Sorce = temp.Math_Sorce;
    q->English_Sorce = temp.English_Sorce;
}

//Sort by student ID (Selection sort)
void sortStuInfo() {
    Student *p = head;
    Student *q = NULL;
    Student *temp = NULL;
    //Selection sort
    while (p != NULL) {
        q = p->next;
        
        while (q != NULL) {
            if (strcmp(p->Student_ID, q->Student_ID) > 0) {
                //Just swap the data,Instead of the node😭
                Swap(p, q);
            }
            q = q->next;
        }
        p = p->next;
    }
    return;
}

//Search student info
void searchStuInfo() {
    showSearchWindow();
    /*
    //Search by name
    printf("Please enter the name you want to search:");
    char name[MAX_STU_NAMELEN];
    scanf("%s", name);
    Student *p = head;
    printf("ID\tName\tGender\tAge\tC\tMath\tEnglish\n");
    while (p != NULL) {
        //Print all the student whose name is the same as the input
        if (strcmp(name, p->Name) == 0) {
            printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n", p->Student_ID, p->Name, p->Gender, p->Age, p->C_Sorce, p->Math_Sorce, p->English_Sorce);
        
        }
        p = p->next;
    }
    */
    return;
}