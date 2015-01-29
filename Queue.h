#ifndef QUEUE_H
#define QUEUE_H
#endif

#include <vector>
#include <stdlib.h> 

#include "Packet.h"


class Queue
{
	public:
		static const int T_time = 10;
		int n_arrivals, n_departures, n_observers, n_idle_count, n_packets;
		double t_arrival, t_departure, t_observer;
		std::vector<Packet*> DES;
		
		Queue();
		~Queue();
		void simulate();
};
