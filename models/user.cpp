#include "user.hpp"
#include <iostream>


User::User(Database& db) : db(db) {}
// re check plz
bool User::create_user(const std::string& username, const std::string& email, const std::string& password) {
    pqxx::work W(db.get_connection());
    std::string query = "INSERT INTO users (username, email, password) VALUES (" +
                        W.quote(username) + ", " + W.quote(email) + ", " + W.quote(password) + ")";
    W.exec(query);
    W.commit();
    return true;
}

bool User::register_user(const std::string& username, const std::string& email, const std::string& password) {
    pqxx::work W(db.get_connection());
    std::string query = "SELECT * FROM users WHERE username = " + W.quote(username) + " OR email = " + W.quote(email);
    pqxx::result R = W.exec(query);
    if (R.size() > 0) {
        std::cout << "User already exists with the given username or email" << std::endl;
        return false;
    }
    create_user(username, email, password);
    return true;
}

bool User::login(const std::string& username, const std::string& password) {
    pqxx::work W(db.get_connection());
    std::string query = "SELECT * FROM users WHERE username = " + W.quote(username) + " AND password = " + W.quote(password);
    pqxx::result R = W.exec(query);
    if (R.size() == 0) {
        std::cout << "Invalid username or password" << std::endl;
        return false;
    }
    std::cout << "Login successful" << std::endl;
    return true;
}

bool User::change_password(int user_id, const std::string& old_password, const std::string& new_password) {
    pqxx::work W(db.get_connection());
    std::string query = "SELECT * FROM users WHERE user_id = " + W.quote(user_id) + " AND password = " + W.quote(old_password);
    pqxx::result R = W.exec(query);
    if (R.size() == 0) {
        std::cout << "Invalid user_id or password" << std::endl;
        return false;
    }
    query = "UPDATE users SET password = " + W.quote(new_password) + " WHERE user_id = " + W.quote(user_id);
    W.exec(query);
    W.commit();
    std::cout << "Password changed successfully" << std::endl;
    return true;
}