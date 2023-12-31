#include "global.h"
#include "stu_file.h"
#include "stu_service.h"
#include "show_ui.h"

//HFDLYS 2023/11/29

/*
//print menu
void printMenu();   //now abandoned

*/
//global or extern
Student *head = NULL;

int main() {
    //choice
    int choice;
    
    //init gtk and the main window
    gtk_init(NULL, NULL);
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Student Information Management");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *fixed;
    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    GtkWidget *button1;
    button1 = gtk_button_new_with_label("Add student info");
    gtk_fixed_put(GTK_FIXED(fixed), button1, 50, 50);
    gtk_widget_set_size_request(button1, 200, 35);

    GtkWidget *button2;
    button2 = gtk_button_new_with_label("Display student info");
    gtk_fixed_put(GTK_FIXED(fixed), button2, 50, 100);
    gtk_widget_set_size_request(button2, 200, 35);

    GtkWidget *button3;
    button3 = gtk_button_new_with_label("Sort by student ID");
    gtk_fixed_put(GTK_FIXED(fixed), button3, 50, 150);
    gtk_widget_set_size_request(button3, 200, 35);

    GtkWidget *button4;
    button4 = gtk_button_new_with_label("Search student info");
    gtk_fixed_put(GTK_FIXED(fixed), button4, 50, 200);
    gtk_widget_set_size_request(button4, 200, 35);

    GtkWidget *button5;
    button5 = gtk_button_new_with_label("Save student info to database");
    gtk_fixed_put(GTK_FIXED(fixed), button5, 50, 250);
    gtk_widget_set_size_request(button5, 200, 35);

    GtkWidget *button6;
    button6 = gtk_button_new_with_label("Load student info from database");
    gtk_fixed_put(GTK_FIXED(fixed), button6, 50, 300);
    gtk_widget_set_size_request(button6, 200, 35);

    GtkWidget *button7;
    button7 = gtk_button_new_with_label("Exit");
    gtk_fixed_put(GTK_FIXED(fixed), button7, 50, 350);
    gtk_widget_set_size_request(button7, 200, 35);
    //connect signal with event
    g_signal_connect(button1, "clicked", G_CALLBACK(addStuInfo), NULL);
    g_signal_connect(button2, "clicked", G_CALLBACK(displayStuInfo), NULL);
    g_signal_connect(button3, "clicked", G_CALLBACK(sortStuInfo), NULL);
    g_signal_connect(button4, "clicked", G_CALLBACK(searchStuInfo), NULL);
    g_signal_connect(button5, "clicked", G_CALLBACK(saveStuInfo), NULL);
    g_signal_connect(button6, "clicked", G_CALLBACK(loadStuInfo), NULL);
    g_signal_connect(button7, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show_all(window);
    gtk_main();
    /*
    now abandoned👋
    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStuInfo();
                break;
            case 2:
                displayStuInfo();
                break;
            case 3:
                sortStuInfo();
                break;
            case 4:
                searchStuInfo();
                break;
            case 5:
                saveStuInfo();
                break;
            case 6:
                head = loadStuInfo();
                break;
            default:
                printf("🤔🤔🤔make sure if vaild\n");
                break;
        }
    }
    printf("👋👋👋👋👋👋👋👋👋👋\n");
    return 0;
    */
}

//print menu (now abandoned)
void printMenu() {
    printf("****************************\n");
    printf("Student Information Management\n");
    printf("****************************\n");
    printf("************Menu************\n");
    printf("1 - Add student info\n");
    printf("2 - Display student info\n");
    printf("3 - Sort by student ID\n");
    printf("4 - Search student info\n");
    printf("5 - Save student info to database\n");
    printf("6 - Load student info from database\n");

    printf("0 - Exit\n");
    printf("****************************\n");
}