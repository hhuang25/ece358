#ifndef QUEUE_H
#define QUEUE_H

#include <map>
#include <stdlib.h> 

class Queue
{
    public:
        double T_time;
        double C_rate; 
        double L_length;
        double lambda;
        enum Event {arrival, departure, observer};
        long n_arrivals, n_departures, n_observers, n_idle_count, n_packets;
        double t_arrival, t_departure, t_observer;

        Queue();
        ~Queue();
        double setT(double t){T_time = t; return T_time;}
        double setC(double c){C_rate = c; return C_rate;}
        double setL(double l){L_length = l; return L_length;}
        double setLambda(double l){lambda = l; return lambda;}
        void simulate();
    private:
        std::map<double, Event> DES;
};
#endif
