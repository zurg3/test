/*
Compile:
gcc test_gtk_app.c -o test_gtk_app `pkg-config --libs --cflags gtk+-2.0`
*/

#include <gtk/gtk.h>

void undo_redo(GtkWidget *widget,  gpointer item) {

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

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *menubar;

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

  GtkWidget *toolbar;
  GtkToolItem *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb;
  GtkToolItem *sep2;
  GtkToolItem *undo;
  GtkToolItem *redo;
  GtkToolItem *sep3;
  GtkToolItem *exit;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Test GTK App");
  gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  menubar = gtk_menu_bar_new();
  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

  gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

  fileMenu = gtk_menu_new();
  settingsMenu = gtk_menu_new();
  multiplayerMenu = gtk_menu_new();

  fileMi = gtk_menu_item_new_with_label("File");
  settingsMi = gtk_menu_item_new_with_label("Settings");
  multiplayerMi = gtk_menu_item_new_with_label("Multiplayer");

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

  newTb = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

  openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

  sep2 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep2, -1);

  undo = gtk_tool_button_new_from_stock(GTK_STOCK_UNDO);
  gtk_widget_set_name(GTK_WIDGET(undo), "undo");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), undo, -1);

  redo = gtk_tool_button_new_from_stock(GTK_STOCK_REDO);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), redo, -1);

  sep3 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep3, -1);

  exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit, -1);

  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  g_signal_connect(G_OBJECT(undo), "clicked",
        G_CALLBACK(undo_redo), redo);

  g_signal_connect(G_OBJECT(redo), "clicked",
        G_CALLBACK(undo_redo), undo);

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
