//Ui shower
#pragma once
#ifndef SHOW_UI_H_
#define SHOW_UI_H_

#include "stu_service.h"
#include "stu_file.h"
#include <gtk/gtk.h>

//display the sutdent information
void showStuInf(Student *point);

//Add onclick
void addOnClick(GtkWidget *button, GtkWidget **entries);

//displau the add window
void showAddWindow();

//search student info
void screarchOnclick(GtkWidget *button, GtkWidget **entries);

//display the search window
void showSearchWindow();









#endif