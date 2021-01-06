#include <gtk-2.0/gtk/gtk.h>

int main(int argc, char *argv[]) {
  gtk_init(&argc, &argv);
  GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_show(win);
  gtk_main(); // Main loop
  return 0;
}
