#include <gtk-2.0/gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr) { gtk_main_quit(); }

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);

  GtkWidget *lbl = gtk_label_new("My label");
  GtkWidget *box = gtk_vbox_new(FALSE, 5);

  g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
  g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

  gtk_box_pack_start(GTK_BOX(box), lbl, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), btn, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(win), box);

  gtk_widget_show_all(win);
  gtk_main(); // Main loop
  return 0;
}
