#include <iostream>
#include <sqlite3.h>

int main() {
    // Open SQLite database
    sqlite3* db;
    int rc = sqlite3_open(":memory:", &db);  // Use ":memory:" for an in-memory database

    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT);";
    rc = sqlite3_exec(db, createTableQuery, NULL, 0, NULL);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Insert data into the table
    const char* insertDataQuery = "INSERT INTO users (name) VALUES ('John Doe');";
    rc = sqlite3_exec(db, insertDataQuery, NULL, 0, NULL);

    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Query data from the table
    const char* selectDataQuery = "SELECT * FROM users;";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, selectDataQuery, -1, &stmt, NULL);

    if (rc == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));

            std::cout << "ID: " << id << ", Name: " << name << std::endl;
        }

        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Error querying data: " << sqlite3_errmsg(db) << std::endl;
    }

    // Close the SQLite database
    sqlite3_close(db);

    return 0;
}







