#include <gtk/gtk.h>
#include "config.h"

void on_main_window_destroy() {
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    GError *err = NULL;
    GtkBuilder* builder;
    builder = gtk_builder_new();
    if (0 == gtk_builder_add_from_file (builder, GLADE_FILE_PATH, &err)) {
        fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
    }

    GtkWidget* window;
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}