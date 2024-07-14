#include "event.hpp"

Event::Event(Database& db) : db(db) {}

void Event::create_event(const std::string& event_name, const std::string& event_date, const std::string& location) {
    pqxx::work W(db.get_connection());
    std::string query = "INSERT INTO events (event_name, event_date, location) VALUES (" +
                        W.quote(event_name) + ", " + W.quote(event_date) + ", " + W.quote(location) + ")";
    W.exec(query);
    W.commit();
}


std::vector<std::tuple<int, std::string, std::string, std::string>> Event::getAllEvents() {
    pqxx::work W(db.get_connection());
    pqxx::result R = W.exec("SELECT event_id, event_name, event_date, location FROM events");
    std::vector<std::tuple<int, std::string, std::string, std::string>> events;
    for (const auto& row : R) {
        events.emplace_back(row[0].as<int>(), row[1].as<std::string>(), row[2].as<std::string>(), row[3].as<std::string>());
    }
    return events;
}
