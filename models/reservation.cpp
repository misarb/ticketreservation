#include "reservation.hpp"

Reservation::Reservation(Database& db) : db(db) {}

void Reservation::create_reservation(int user_id, int event_id) {
    pqxx::work W(db.get_connection());
    std::string query = "INSERT INTO reservations (user_id, event_id) VALUES (" +
                        W.quote(user_id) + ", " + W.quote(event_id) + ")";
    W.exec(query);
    W.commit();
}
