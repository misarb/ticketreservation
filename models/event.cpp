#include "event.hpp"

Event::Event(Database& db) : db(db) {}

void Event::create_event(const std::string& event_name, const std::string& event_date, const std::string& location) {
    pqxx::work W(db.get_connection());
    std::string query = "INSERT INTO events (event_name, event_date, location) VALUES (" +
                        W.quote(event_name) + ", " + W.quote(event_date) + ", " + W.quote(location) + ")";
    W.exec(query);
    W.commit();
}
