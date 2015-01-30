#ifndef QUEUE_H
#define QUEUE_H

#include <map>
#include <stdlib.h> 

#include "Packet.h"


class Queue
{
    public:
        static const int T_time = 10000;
        enum Event {arrival, departure, observer};
        int n_arrivals, n_departures, n_observers, n_idle_count, n_packets;
        double t_arrival, t_departure, t_observer;

        Queue();
        ~Queue();
        void simulate();
    private:
        std::map<double, Event> DES;
};
#endif
