#include <gtk-2.0/gtk/gtk.h>

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
  GtkWidget *comb = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 1");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 2");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(comb), "Option 3");
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
