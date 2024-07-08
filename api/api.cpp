#include "api.hpp"

API::API(Database& db):db(db),user(db) {}

bool API::register_user(const std::string& username, const std::string& email, const std::string& password) {
    return user.create_user(username, email, password);
}   

std::optional<int> API::login(const std::string& username, const std::string& password) {
    //getUserByUsername(username);
    // If login successful, retrieve and return the user ID
    if (user.login(username, password)) {
        return 1; // Dummy user_id for now
    }
    return std::nullopt;
}

bool API::change_password(int user_id, const std::string& old_password, const std::string& new_password) {
    return user.change_password(user_id, old_password, new_password);
}

std::optional<std::pair<std::string, std::string>> API::get_user_info(int user_id) {
    // Retrieve user information (e.g., username and email) based on user_id
    return std::make_pair("username", "email"); // Dummy values for now
}

bool API::update_user_profile(int user_id, const std::string& new_username, const std::string& new_email) {
    // Update user profile information (e.g., username and email) based on user_id
    return true; // Dummy return value for now
}