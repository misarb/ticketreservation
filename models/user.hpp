#ifndef USER_H
#define USER_H

#include "../database/database.hpp"
#include <string>

class User {
public:
    User(Database& db);
    bool create_user(const std::string& username, const std::string& email, const std::string& password);
    // User-specific operations that might involve multiple database calls or additional logic
    bool register_user(const std::string& username, const std::string& email, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    bool change_password(int user_id, const std::string& old_password, const std::string& new_password);

private:
    Database& db;
};

#endif // USER_H
