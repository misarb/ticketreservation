#include "api.hpp"
#include <qdebug.h>

APITicket::APITicket(Database& db):db(db),user(db),event(db) {}

bool APITicket::register_user(const std::string& username, const std::string& email, const std::string& password) {
    return user.create_user(username, email, password);
}   

std::optional<int> APITicket::login(const std::string& username, const std::string& password) {
    //getUserByUsername(username);
    // If login successful, retrieve and return the user ID
    if (user.login(username, password)) {
        return 1; // Dummy user_id for now
    }
    return std::nullopt;
}

bool APITicket::change_password(int user_id, const std::string& old_password, const std::string& new_password) {
    return user.change_password(user_id, old_password, new_password);
}

std::optional<std::pair<std::string, std::string>> APITicket::get_user_info(int user_id) {
    // Retrieve user information (e.g., username and email) based on user_id
    return std::make_pair("username", "email"); // Dummy values for now
}

bool APITicket::update_user_profile(int user_id, const std::string& new_username, const std::string& new_email) {
    // Update user profile information (e.g., username and email) based on user_id
    return true; // Dummy return value for now
}

std::vector<std::tuple<int, std::string, std::string, std::string>> APITicket::showAllEvents() {

    // return {std::make_tuple(1, "Event 1", "2022-01-01", "Location 1"),
    //         std::make_tuple(2, "Event 2", "2022-02-02", "Location 2")}; // Dummy values for now
    std::vector<std::tuple<int, std::string, std::string, std::string>> events = event.getAllEvents();
    for(const auto & event:events){
    qDebug() << "Event:" << std::get<0>(event) << std::get<1>(event).c_str() << std::get<2>(event).c_str() << std::get<3>(event).c_str();
    }
    return event.getAllEvents();


}
