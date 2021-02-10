#include <gtk-2.0/gtk/gtk.h>

GtkWidget *txt;

void end_program(GtkWidget *wid, gpointer ptr) { gtk_main_quit(); }

void copy_text(GtkWidget *wid, gpointer ptr) {
  const char *input = gtk_entry_get_text(GTK_ENTRY(txt));
  gtk_label_set_text(GTK_LABEL(ptr), input);
}

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Close");
  GtkWidget *cpy = gtk_button_new_with_label("Copy button");
  GtkWidget *lbl = gtk_label_new("My label");

  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
  g_signal_connect(cpy, "clicked", G_CALLBACK(copy_text), lbl);

  // default, min, max, step, page increments
  GtkObject *adj = gtk_adjustment_new(0, -10, 10, 1, 0, 0);
  // climb rate, number of decimals to show
  txt = gtk_spin_button_new(GTK_ADJUSTMENT(adj), 0, 0);

  GtkWidget *tbl = gtk_table_new(2, 2, TRUE);
  // left, right, top, bottom
  gtk_table_attach_defaults(GTK_TABLE(tbl), lbl, 0, 1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), cpy, 1, 2, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(tbl), btn, 0, 1, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE(tbl), txt, 1, 2, 1, 2);
  gtk_container_add(GTK_CONTAINER(win), tbl);

  gtk_widget_show_all(win);
  gtk_main(); // Main loop
  return 0;
}
