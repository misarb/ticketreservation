#ifndef RESERVATION_H
#define RESERVATION_H

#include "../database/database.hpp"

class Reservation {
public:
    Reservation(Database& db);
    void create_reservation(int user_id, int event_id);

    

private:
    Database& db;
};

#endif // RESERVATION_H
