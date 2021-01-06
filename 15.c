#include <gtk-2.0/gtk/gtk.h>

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *btn = gtk_button_new_with_label("Close");
  gtk_container_add(GTK_CONTAINER(win), btn);
  gtk_widget_show_all(win);
  gtk_main(); // Main loop
  return 0;
}
