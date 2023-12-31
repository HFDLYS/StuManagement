#include "show_ui.h"
#include "global.h"
#include "stu_service.h"
#include "stu_file.h"

//HFDLYS 2023/11/29

//display the windows
void showStuInf(Student *point) {

    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Student Information Table");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    GtkWidget *scrolled_window;
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    GtkWidget *tree_view;
    tree_view = gtk_tree_view_new();

    GtkListStore *list_store;
    list_store = gtk_list_store_new(7, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_DOUBLE, G_TYPE_DOUBLE, G_TYPE_DOUBLE);
    Student *p = point;
    while (p != NULL) {
        GtkTreeIter iter;
        gtk_list_store_append(list_store, &iter);
        
        gtk_list_store_set(list_store, &iter, 0, p->Student_ID, 1, p->Name, 2, p->Gender, 3, p->Age, 4, p->C_Sorce, 5, p->Math_Sorce, 6, p->English_Sorce, -1);

        p = p->next;
    }

    //load ui
    gtk_tree_view_set_model(GTK_TREE_VIEW(tree_view), GTK_TREE_MODEL(list_store));
    g_object_unref(list_store);

    GtkCellRenderer *renderer;
    renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column;
    //set column loader
    column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    column = gtk_tree_view_column_new_with_attributes("Name", renderer, "text", 1, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    column = gtk_tree_view_column_new_with_attributes("Gender", renderer, "text", 2, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    column = gtk_tree_view_column_new_with_attributes("Age", renderer, "text", 3, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    column = gtk_tree_view_column_new_with_attributes("C Program", renderer, "text", 4, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    column = gtk_tree_view_column_new_with_attributes("Math", renderer, "text", 5, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    column = gtk_tree_view_column_new_with_attributes("English", renderer, "text", 6, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    gtk_container_add(GTK_CONTAINER(scrolled_window), tree_view);

    gtk_widget_show_all(window);

}

//Add onclick
void addOnClick(GtkWidget *button, GtkWidget **entries) {

    Student *p = malloc(sizeof(Student));
    printf(":%s\n", gtk_entry_get_text(GTK_ENTRY(entries[0])));
    strcpy(p->Student_ID, gtk_entry_get_text(GTK_ENTRY(entries[0])));
    strcpy(p->Name, gtk_entry_get_text(GTK_ENTRY(entries[1])));
    strcpy(p->Gender, gtk_entry_get_text(GTK_ENTRY(entries[2])));
    p->Age = atoi(gtk_entry_get_text(GTK_ENTRY(entries[3])));
    p->C_Sorce = atof(gtk_entry_get_text(GTK_ENTRY(entries[4])));
    p->Math_Sorce = atof(gtk_entry_get_text(GTK_ENTRY(entries[5])));
    p->English_Sorce = atof(gtk_entry_get_text(GTK_ENTRY(entries[6])));
    p->prev = NULL;
    p->next = head;
    if (head != NULL) {
        head->prev = p;
    }
    head = p;
    return;
}

//display the add window
void showAddWindow() {
    GtkWidget *window, *grid, *label, *entry, *button;
    static GtkWidget *entries[7];
    //ui load and set
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Add Student Info");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    label = gtk_label_new("Student ID:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 2, 1);
    entries[0] = entry;

    label = gtk_label_new("Name:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 1, 2, 1);
    entries[1] = entry;

    label = gtk_label_new("Gender:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 2, 2, 1);
    entries[2] = entry;

    label = gtk_label_new("Age:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 3, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 3, 2, 1);
    entries[3] = entry;

    label = gtk_label_new("C Program:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 4, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 4, 2, 1);
    entries[4] = entry;

    label = gtk_label_new("Math:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 5, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 5, 2, 1);
    entries[5] = entry;

    label = gtk_label_new("English:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 6, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 6, 2, 1);
    entries[6] = entry;


    button = gtk_button_new_with_label("➕➕➕➕➕➕");
    g_signal_connect(button, "clicked", G_CALLBACK(addOnClick), entries);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 8, 3, 1);

    gtk_widget_show_all(window);
}

//search student info
void screarchOnclick(GtkWidget *button, GtkWidget **entries) {
    char name[MAX_STU_NAMELEN];
    strcpy(name, gtk_entry_get_text(GTK_ENTRY(entries[0])));
    Student *p = head;
    Student *temp = NULL;
    Student *pre = NULL;
    while (p != NULL) {
        //Print all the student whose name is the same as the input
        if (strcmp(name, p->Name) == 0) {
            Student *q = (Student *)malloc(sizeof(Student));
            strcpy(q->Student_ID, p->Student_ID);
            strcpy(q->Name, p->Name);
            strcpy(q->Gender, p->Gender);
            q->Age = p->Age;
            q->C_Sorce = p->C_Sorce;
            q->Math_Sorce = p->Math_Sorce;
            q->English_Sorce = p->English_Sorce;
            if (temp == NULL) {
                temp = q;
            } else {
                pre->next = q;
            }
            q->prev = pre;
            q->next = NULL;
            pre = q;
        }
        p = p->next;
    }
    showStuInf(temp);
    return;
}

//display the search window
void showSearchWindow() {
    GtkWidget *window, *grid, *label, *entry, *button;
    static GtkWidget *entries[1];

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Search Student Info");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    //set the button
    label = gtk_label_new("Name:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 2, 1);
    entries[0] = entry;

    button = gtk_button_new_with_label("🔎🔍🔎🔍🔎🔍");
    g_signal_connect(button, "clicked", G_CALLBACK(screarchOnclick), entries);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 3, 1);

    gtk_widget_show_all(window);
}
