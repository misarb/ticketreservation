#ifndef API_HPP
#define API_HPP

#include "../database/database.hpp"
#include "../models/user.hpp"
#include <pqxx/pqxx>

#include <string>
#include <optional>

class API {
public:
    API(Database& db);

    // User-related API endpoints
    bool register_user(const std::string& username, const std::string& email, const std::string& password);
    std::optional<int> login(const std::string& username, const std::string& password);
    bool change_password(int user_id, const std::string& old_password, const std::string& new_password);
    std::optional<std::pair<std::string, std::string>> get_user_info(int user_id);
    bool update_user_profile(int user_id, const std::string& new_username, const std::string& new_email);


private:
    Database& db;
    User user;
};

#endif // API_HPP
