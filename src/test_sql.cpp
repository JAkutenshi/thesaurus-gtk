#include <sqlite3.h>
#include <iostream>

#define SQL_CREATE_LIT_TABLE "create table if not exists LIT_ENTRIES (ID integer primary key, TITLE text);"

int test_sql() {
    // Connecting to DB
    sqlite3* db;
    int ret_code = sqlite3_open( "./test.db", &db );
    if ( ret_code ) {
        std::cout << "Cannot open DB" << std::endl;
        return -1;
    }
    std::cout << "DB connected" << std::endl;

    // Making query
    std::string query = SQL_CREATE_LIT_TABLE;
    char* err_msg;
    ret_code = sqlite3_exec( db, query.c_str(), nullptr, nullptr, &err_msg );
    if ( ret_code ) {
        std::cerr << "SQL query execution error: " << err_msg << std::endl;
        sqlite3_free( err_msg );
    }



    // Closing DB
    sqlite3_close( db );
    std::cout << "DB closed" << std::endl;

    return 0;
}