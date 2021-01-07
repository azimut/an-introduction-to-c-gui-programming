#include <gtk-2.0/gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr) { gtk_main_quit(); }

void check_toggle(GtkWidget *wid, gpointer ptr) {
  printf("TOGGLED: The state of the button is %d\n",
         gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(wid)));
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Close");
  GtkWidget *lbl = gtk_label_new("My label");

  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

  // Toggle button
  GtkWidget *rad1 = gtk_radio_button_new_with_label(NULL, "Button 1");
  GSList *group = gtk_radio_button_get_group(GTK_RADIO_BUTTON(rad1));
  GtkWidget *rad2 = gtk_radio_button_new_with_label(group, "Button 2");
  g_signal_connect(rad1, "toggled", G_CALLBACK(check_toggle), NULL);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rad2), TRUE);

  GtkWidget *tbl = gtk_table_new(2, 2, TRUE);
  // left, right, top, bottom
  gtk_table_attach_defaults(GTK_TABLE(tbl), rad1, 0, 1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), rad2, 1, 2, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 1, 2);
  gtk_container_add(GTK_CONTAINER(win), tbl);

  gtk_widget_show_all(win);
  gtk_main(); // Main loop
  return 0;
}
