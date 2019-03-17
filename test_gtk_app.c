/*
Compile:
gcc test_gtk_app.c -o test_gtk_app `pkg-config --libs --cflags gtk+-2.0`
*/

#include <gtk/gtk.h>

void undo_redo(GtkWidget *widget, gpointer item) {
  static gint count = 2;
  const gchar *name = gtk_widget_get_name(widget);

  if (g_strcmp0(name, "undo") ) {
    count++;
  } else {
    count--;
  }

  if (count < 0) {
     gtk_widget_set_sensitive(widget, FALSE);
     gtk_widget_set_sensitive(item, TRUE);
  }

  if (count > 5) {
     gtk_widget_set_sensitive(widget, FALSE);
     gtk_widget_set_sensitive(item, TRUE);
  }
}

void button_clicked(GtkWidget *widget, gpointer data) {
  const gchar *name = gtk_widget_get_name(widget);

  if (!strcmp(name, "btn1")) {
    g_print("You clicked button 1.\n");
  }
  else if (!strcmp(name, "btn2")) {
    g_print("You clicked button 2.\n");
  }
  else if (!strcmp(name, "btn3")) {
    g_print("You clicked button 3.\n");
  }
  else if (!strcmp(name, "btn4")) {
    g_print("You clicked button 4.\n");
  }
  else if (!strcmp(name, "btn5")) {
    g_print("You clicked button 5.\n");
  }
}

void show_about(GtkWidget *widget, gpointer data) {
  GtkWidget *dialog = gtk_about_dialog_new();

  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "Test GTK App");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "0.1");
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),"(c) zurg3");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
     "I just learning GTK2 and C language.");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog),
     "https://github.com/zurg3");
  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
}

static void submit_table(GtkWidget **entry, GtkWidget *widget) {
  GtkWidget *get_entry1 = entry[0];
  GtkWidget *get_entry2 = entry[1];
  GtkWidget *get_entry3 = entry[2];
  GtkWidget *get_entry4 = entry[3];
  GtkWidget *get_entry5 = entry[4];

  const gchar *first_name = gtk_entry_get_text(GTK_ENTRY(get_entry1));
  const gchar *last_name = gtk_entry_get_text(GTK_ENTRY(get_entry2));
  const gchar *age = gtk_entry_get_text(GTK_ENTRY(get_entry3));
  const gchar *country = gtk_entry_get_text(GTK_ENTRY(get_entry4));
  const gchar *city = gtk_entry_get_text(GTK_ENTRY(get_entry5));

  g_print("First name: %s\n", first_name);
  g_print("Last name: %s\n", last_name);
  g_print("Age: %s\n", age);
  g_print("Country: %s\n", country);
  g_print("City: %s\n", city);
}

int main(int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *menubar;
  GtkWidget *toolbar;
  GtkWidget *fixed;

  GtkWidget *fileMenu;
  GtkWidget *imprMenu;
  GtkWidget *exprMenu;

  GtkWidget *settingsMenu;
  GtkWidget *settingsGraphicsMenu;
  GtkWidget *settingsSoundMenu;
  GtkWidget *settingsGameplayMenu;

  GtkWidget *multiplayerMenu;
  GtkWidget *multiplayerJoinMenu;
  GtkWidget *multiplayerHostMenu;
  GtkWidget *multiplayerSettingsMenu;

  GtkWidget *sep;
  GtkWidget *fileMi;
  GtkWidget *settingsMi;
  GtkWidget *multiplayerMi;
  GtkWidget *aboutMi;
  GtkWidget *aboutMenu;

  GtkWidget *imprMi;
  GtkWidget *exprMi;

  GtkWidget *settingsGraphicsMi;
  GtkWidget *settingsSoundMi;
  GtkWidget *settingsGameplayMi;

  GtkWidget *multiplayerJoinMi;
  GtkWidget *multiplayerHostMi;
  GtkWidget *multiplayerSettingsMi;

  GtkWidget *feedMi;
  GtkWidget *bookMi;
  GtkWidget *mailMi;

  GtkWidget *feedMi_ex;
  GtkWidget *bookMi_ex;
  GtkWidget *mailMi_ex;

  GtkWidget *quitMi;

  GtkToolItem *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb;
  GtkToolItem *sep2;
  GtkToolItem *undo;
  GtkToolItem *redo;
  GtkToolItem *sep3;
  GtkToolItem *exit;

  GtkWidget *btn1;
  GtkWidget *btn2;
  GtkWidget *btn3;
  GtkWidget *btn4;
  GtkWidget *btn5;

  GtkWidget *halign;
  GtkWidget *btn;

  GtkWidget *about;

  GtkWidget *label_big;

  GtkWidget *table;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label4;
  GtkWidget *label5;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *entry4;
  GtkWidget *entry5;
  GtkWidget *submitTableButton;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Test GTK App");
  gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  menubar = gtk_menu_bar_new();
  toolbar = gtk_toolbar_new();
  fixed = gtk_fixed_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

  gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

  gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

  table = gtk_table_new(5, 2, FALSE);

  fileMenu = gtk_menu_new();
  settingsMenu = gtk_menu_new();
  multiplayerMenu = gtk_menu_new();
  aboutMenu = gtk_menu_new();

  fileMi = gtk_menu_item_new_with_label("File");
  settingsMi = gtk_menu_item_new_with_label("Settings");
  multiplayerMi = gtk_menu_item_new_with_label("Multiplayer");
  aboutMi = gtk_menu_item_new_with_label("About");

  imprMenu = gtk_menu_new();
  exprMenu = gtk_menu_new();

  settingsGraphicsMenu = gtk_menu_new();
  settingsSoundMenu = gtk_menu_new();
  settingsGameplayMenu = gtk_menu_new();

  multiplayerJoinMenu = gtk_menu_new();
  multiplayerHostMenu = gtk_menu_new();
  multiplayerSettingsMenu = gtk_menu_new();

  imprMi = gtk_menu_item_new_with_label("Import");
  exprMi = gtk_menu_item_new_with_label("Export");

  settingsGraphicsMi = gtk_menu_item_new_with_label("Graphics");
  settingsSoundMi = gtk_menu_item_new_with_label("Sounds");
  settingsGameplayMi = gtk_menu_item_new_with_label("Gameplay");

  multiplayerJoinMi = gtk_menu_item_new_with_label("Join");
  multiplayerHostMi = gtk_menu_item_new_with_label("Host");
  multiplayerSettingsMi = gtk_menu_item_new_with_label("Settings");

  feedMi = gtk_menu_item_new_with_label("Import news feed...");
  bookMi = gtk_menu_item_new_with_label("Import bookmarks...");
  mailMi = gtk_menu_item_new_with_label("Import mail...");

  feedMi_ex = gtk_menu_item_new_with_label("Export news feed...");
  bookMi_ex = gtk_menu_item_new_with_label("Export bookmarks...");
  mailMi_ex = gtk_menu_item_new_with_label("Export mail...");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(imprMi), imprMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(exprMi), exprMenu);

  gtk_menu_shell_append(GTK_MENU_SHELL(imprMenu), feedMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(imprMenu), bookMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(imprMenu), mailMi);

  gtk_menu_shell_append(GTK_MENU_SHELL(exprMenu), feedMi_ex);
  gtk_menu_shell_append(GTK_MENU_SHELL(exprMenu), bookMi_ex);
  gtk_menu_shell_append(GTK_MENU_SHELL(exprMenu), mailMi_ex);

  sep = gtk_separator_menu_item_new();
  quitMi = gtk_menu_item_new_with_label("Quit");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(settingsMi), settingsMenu);
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(multiplayerMi), multiplayerMenu);

  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), imprMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), exprMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), sep);
  gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);

  gtk_menu_shell_append(GTK_MENU_SHELL(settingsMenu), settingsGraphicsMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(settingsMenu), settingsSoundMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(settingsMenu), settingsGameplayMi);

  gtk_menu_shell_append(GTK_MENU_SHELL(multiplayerMenu), multiplayerJoinMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(multiplayerMenu), multiplayerHostMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(multiplayerMenu), multiplayerSettingsMi);

  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), settingsMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), multiplayerMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), aboutMi);

  newTb = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);
  gtk_tool_item_set_tooltip_text(newTb, "New");

  openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);
  gtk_tool_item_set_tooltip_text(openTb, "Open");

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);
  gtk_tool_item_set_tooltip_text(saveTb, "Save");

  sep2 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep2, -1);

  undo = gtk_tool_button_new_from_stock(GTK_STOCK_UNDO);
  gtk_widget_set_name(GTK_WIDGET(undo), "undo");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), undo, -1);
  gtk_tool_item_set_tooltip_text(undo, "Undo");

  redo = gtk_tool_button_new_from_stock(GTK_STOCK_REDO);
  gtk_widget_set_name(GTK_WIDGET(redo), "redo");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), redo, -1);
  gtk_tool_item_set_tooltip_text(redo, "Redo");

  sep3 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep3, -1);

  exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit, -1);
  gtk_tool_item_set_tooltip_text(exit, "Exit");

  btn1 = gtk_button_new_with_label("Button 1");
  gtk_widget_set_name(GTK_WIDGET(btn1), "btn1");
  gtk_fixed_put(GTK_FIXED(fixed), btn1, 10, 10);
  gtk_widget_set_size_request(btn1, 100, 50);

  btn2 = gtk_button_new_with_label("Button 2");
  gtk_widget_set_name(GTK_WIDGET(btn2), "btn2");
  gtk_fixed_put(GTK_FIXED(fixed), btn2, 120, 10);
  gtk_widget_set_size_request(btn2, 100, 50);

  btn3 = gtk_button_new_with_label("Button 3");
  gtk_widget_set_name(GTK_WIDGET(btn3), "btn3");
  gtk_fixed_put(GTK_FIXED(fixed), btn3, 230, 10);
  gtk_widget_set_size_request(btn3, 100, 50);

  btn4 = gtk_button_new_with_label("Button 4");
  gtk_widget_set_name(GTK_WIDGET(btn4), "btn4");
  gtk_fixed_put(GTK_FIXED(fixed), btn4, 340, 10);
  gtk_widget_set_size_request(btn4, 100, 50);

  btn5 = gtk_button_new_with_label("Button 5");
  gtk_widget_set_name(GTK_WIDGET(btn5), "btn5");
  gtk_fixed_put(GTK_FIXED(fixed), btn5, 450, 10);
  gtk_widget_set_size_request(btn5, 100, 50);

  submitTableButton = gtk_button_new_with_label("Submit");
  gtk_widget_set_name(GTK_WIDGET(submitTableButton), "submitTableButton");
  gtk_widget_set_size_request(submitTableButton, 100, 50);

  label_big = gtk_label_new("Lorem ipsum dolor sit amet\n\
consectetur adipisicing elit\n\
sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\n\
Ut enim ad minim veniam\n\
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n\
Duis aute irure dolor in reprehenderit in voluptate\n\
velit esse cillum dolore eu fugiat nulla pariatur.\n\
Excepteur sint occaecat cupidatat non proident\n\
sunt in culpa qui officia deserunt mollit anim id est laborum.");

  label1 = gtk_label_new("First name");
  label2 = gtk_label_new("Last name");
  label3 = gtk_label_new("Age");
  label4 = gtk_label_new("Country");
  label5 = gtk_label_new("City");

  gtk_table_attach(GTK_TABLE(table), label1, 0, 1, 0, 1,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), label2, 0, 1, 1, 2,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), label3, 0, 1, 2, 3,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), label4, 0, 1, 3, 4,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), label5, 0, 1, 4, 5,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();
  entry3 = gtk_entry_new();
  entry4 = gtk_entry_new();
  entry5 = gtk_entry_new();

  gtk_table_attach(GTK_TABLE(table), entry1, 1, 2, 0, 1,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry2, 1, 2, 1, 2,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry3, 1, 2, 2, 3,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry4, 1, 2, 3, 4,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry5, 1, 2, 4, 5,
      GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  GtkWidget **tableEntries;
  tableEntries = malloc(5 * sizeof(GtkWidget));
  tableEntries[0] = entry1;
  tableEntries[1] = entry2;
  tableEntries[2] = entry3;
  tableEntries[3] = entry4;
  tableEntries[4] = entry5;

  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), fixed, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), label_big, FALSE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), submitTableButton, FALSE, FALSE, 0);

  g_signal_connect(G_OBJECT(btn1), "clicked",
      G_CALLBACK(button_clicked), NULL);

  g_signal_connect(G_OBJECT(btn2), "clicked",
      G_CALLBACK(button_clicked), NULL);

  g_signal_connect(G_OBJECT(btn3), "clicked",
      G_CALLBACK(button_clicked), NULL);

  g_signal_connect(G_OBJECT(btn4), "clicked",
      G_CALLBACK(button_clicked), NULL);

  g_signal_connect(G_OBJECT(btn5), "clicked",
      G_CALLBACK(button_clicked), NULL);

  g_signal_connect_swapped(submitTableButton, "clicked",
      G_CALLBACK(submit_table), tableEntries);

  g_signal_connect(G_OBJECT(undo), "clicked",
        G_CALLBACK(undo_redo), redo);

  g_signal_connect(G_OBJECT(redo), "clicked",
        G_CALLBACK(undo_redo), undo);

  g_signal_connect(G_OBJECT(aboutMi), "button-press-event",
        G_CALLBACK(show_about), (gpointer) aboutMi);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(quitMi), "activate",
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(exit), "clicked",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
