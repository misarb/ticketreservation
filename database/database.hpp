#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <pqxx/pqxx>

class Database {
public:
    static Database* getInstance(const std::string &connection_string);
    pqxx::connection& get_connection();
    
    void createUsersTable();
    void createEventsTable();
    void createReservationsTable();

    // User-related methods
    bool addUser(const std::string& username, const std::string& email, const std::string& password);
    bool getUserById(int user_id, std::string& username, std::string& email);
    bool updateUser(int user_id, const std::string& username, const std::string& email);
    bool deleteUser(int user_id);

protected:
    Database(const std::string &connection_string);

private:
    static Database* _instance;
    pqxx::connection conn;
};





#endif // DATABASE_H


// CREATE TABLE users (
//     user_id SERIAL PRIMARY KEY,
//     username VARCHAR(100) UNIQUE NOT NULL,
//     email VARCHAR(100) UNIQUE NOT NULL,
//     password VARCHAR(100) NOT NULL
// );

// CREATE TABLE events (
//     event_id SERIAL PRIMARY KEY,
//     event_name VARCHAR(100) NOT NULL,
//     event_date DATE NOT NULL,
//     location VARCHAR(100) NOT NULL
// );

// CREATE TABLE reservations (
//     reservation_id SERIAL PRIMARY KEY,
//     user_id INT REFERENCES users(user_id),
//     event_id INT REFERENCES events(event_id),
//     reservation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
// );
