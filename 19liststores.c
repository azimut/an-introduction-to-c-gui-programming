#include <gtk-2.0/gtk/gtk.h>

int pos = 0;

void end_program(GtkWidget *wid, gpointer ptr) { gtk_main_quit(); }

void combo_changed(GtkWidget *wid, gpointer ptr) {
  int sel = gtk_combo_box_get_active(GTK_COMBO_BOX(wid));
  char *selected = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(wid));
  printf("The value of the combo is %d \"%s\"\n", sel, selected);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Close");

  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

  // Toggle button
  GtkListStore *ls = gtk_list_store_new(1, G_TYPE_STRING);
  gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 1", -1);
  gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 2", -1);
  gtk_list_store_insert_with_values(ls, NULL, pos++, 0, "Option 3", -1);

  GtkWidget *comb = gtk_combo_box_new_with_model(GTK_TREE_MODEL(ls));
  GtkCellRenderer *rend = gtk_cell_renderer_text_new();
  gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(comb), rend, FALSE);
  gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(comb), rend, "text", 0);
  gtk_combo_box_set_active(GTK_COMBO_BOX_TEXT(comb), 0);
  gtk_signal_connect(comb, "changed", G_CALLBACK(combo_changed), NULL);

  GtkWidget *tbl = gtk_table_new(2, 2, TRUE);
  gtk_table_attach_defaults(GTK_TABLE(tbl), comb, 0, 1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 1, 2);
  gtk_container_add(GTK_CONTAINER(win), tbl);

  gtk_widget_show_all(win);
  gtk_main(); // Main loop
  return 0;
}
