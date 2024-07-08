#ifndef EVENT_H
#define EVENT_H

#include "../database/database.hpp"
#include <string>

class Event {
public:
    Event(Database& db);
    void create_event(const std::string& event_name, const std::string& event_date, const std::string& location);

private:
    Database& db;
};

#endif // EVENT_H
