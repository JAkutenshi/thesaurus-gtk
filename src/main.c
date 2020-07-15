#include <gtk/gtk.h>
#include <sqlite3.h>

#define SQL_CREATE_LIT_TABLE "create table if not exists LIT_ENTRIES (ID integer primary key, TITLE text);"

int test_sql() {
    // Connecting to DB
    sqlite3* db;
    int ret_code = sqlite3_open( "./test.db", &db );
    if ( ret_code ) {
        printf("%s\n", "Error while DB opening");
        return -1;
    }

    // Making query
    char* query = SQL_CREATE_LIT_TABLE;
    char* err_msg;
    ret_code = sqlite3_exec( db, query, NULL, NULL, &err_msg );
    if ( ret_code ) {
        printf("%s\n", "Error while SQL query executing");
        sqlite3_free( err_msg );
        return -2;
    }

    // Closing DB
    sqlite3_close( db );
    printf("DB closed correctly\n");

    return 0;
}

static void
activate( GtkApplication* app, gpointer user_data )
{
    GtkWidget* window;

    window = gtk_application_window_new( app );
    gtk_window_set_title( GTK_WINDOW( window ), "Window" );
    gtk_window_set_default_size( GTK_WINDOW( window ), 200, 200 );
    gtk_widget_show_all( window );
}

int
main( int argc, char** argv )
{
    GtkApplication* app;
    int status;

    app = gtk_application_new( "com.github.jakutenshi.thesaurus-gtk", G_APPLICATION_FLAGS_NONE );
    g_signal_connect( app, "activate", G_CALLBACK( activate ), NULL );
    status = g_application_run( G_APPLICATION( app ), argc, argv );
    g_object_unref( app );

    test_sql();

    return status;
}
