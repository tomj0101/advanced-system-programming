/*GUI with GTK+ Programming - A minimal GTK+ program
# 1. Install GTK+ Library Dependencies
$ sudo apt-get install libgtk-3-dev
Need to get 7,440 kB/83.5 MB of archives.
After this operation, 50.6 MB of additional disk space will be used.

Run:
gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`
*/
// copied from https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
#include <gtk/gtk.h>

void destroy_func(GtkWidget *widget, gpointer data);

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), __FILE__);
  gtk_window_set_default_size (GTK_WINDOW (window), 300, 250);
  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

