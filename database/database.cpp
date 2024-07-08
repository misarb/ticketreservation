#include "database.hpp"
#include <iostream>

Database::Database(const std::string& connection_string) : conn(connection_string) {
    if (conn.is_open()) {
        std::cout << "Opened database successfully: " << conn.dbname() << std::endl;
    }else{
        throw std::runtime_error("Cannot open database");
    }
}

pqxx::connection& Database::get_connection() {
    return conn;
}

void Database::createUsersTable() {
    pqxx::work W(conn);
    std::string sql = "CREATE TABLE users ("
                      "user_id SERIAL PRIMARY KEY, "
                      "username VARCHAR(100) UNIQUE NOT NULL, "
                      "email VARCHAR(100) UNIQUE NOT NULL, "
                      "password VARCHAR(100) NOT NULL);";
    W.exec(sql);
    W.commit();
    std::cout << "Users Table created successfully" << std::endl;
}

void Database::createEventsTable() {
    pqxx::work W(conn);
    std::string sql = "CREATE TABLE events ("
                      "event_id SERIAL PRIMARY KEY, "
                      "event_name VARCHAR(100) NOT NULL, "
                      "event_date DATE NOT NULL, "
                      "location VARCHAR(100) NOT NULL);";
    W.exec(sql);
    W.commit();
    std::cout << "Events Table created successfully" << std::endl;
}

void Database::createReservationsTable() {
    pqxx::work W(conn);
    std::string sql = "CREATE TABLE reservations ("
                      "reservation_id SERIAL PRIMARY KEY, "
                      "user_id INT REFERENCES users(user_id), "
                      "event_id INT REFERENCES events(event_id), "
                      "reservation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP);";
    W.exec(sql);
    W.commit();
    std::cout << "Reservations Table created successfully" << std::endl;
}

bool Database::addUser(const std::string& username, const std::string& email, const std::string& password) {
    pqxx::work W(conn);
    std::string sql = "INSERT INTO users (username, email, password) VALUES ('" + username + "', '" + email + "', '" + password + "');";
    W.exec(sql);
    W.commit();
    std::cout << "User added successfully" << std::endl;
    return true;
}

bool Database::getUserById(int user_id, std::string& username, std::string& email) {
    pqxx::work W(conn);
    std::string sql = "SELECT username, email FROM users WHERE user_id = " + std::to_string(user_id) + ";";
    pqxx::result R = W.exec(sql);
    W.commit();
    if (R.size() == 0) {
        return false;
    }
    username = R[0][0].as<std::string>();
    email = R[0][1].as<std::string>();
    return true;
}

bool Database::updateUser(int user_id, const std::string& username, const std::string& email) {
    pqxx::work W(conn);
    std::string sql = "UPDATE users SET username = '" + username + "', email = '" + email + "' WHERE user_id = " + std::to_string(user_id) + ";";
    W.exec(sql);
    W.commit();
    std::cout << "User updated successfully" << std::endl;
    return true;
}

bool Database::deleteUser(int user_id) {
    pqxx::work W(conn);
    std::string sql = "DELETE FROM users WHERE user_id = " + std::to_string(user_id) + ";";
    W.exec(sql);
    W.commit();
    std::cout << "User deleted successfully" << std::endl;
    return true;
}

