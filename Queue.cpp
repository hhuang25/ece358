#include <iostream>
#include <stdio.h>

#include "Queue.h"
#include "Random.h"

Queue::Queue()
{
	n_arrivals = 0;
	n_departures = 0;
	n_observers = 0;
	n_idle_count = 0;
	n_packets = 0;
	
	t_arrival = 0;
	t_departure = 0;
	t_observer = 0;
	
	DES.reserve(T_time);
}

Queue::~Queue()
{
	
}

void Queue::simulate()
{
	
	Random *random = new Random();
	while(t_arrival < (double)T_time)
	{
                std::cout<< t_arrival << std::endl;
		t_arrival += random->generateExponentialRanVar();
		Packet *packet = new Packet(Packet::arrival, t_arrival);
                //printf("type: %c\n", packet->event);
		DES.push_back(packet);
		delete packet;
	}
	
	delete random;
        
//        for (int i=0; i<DES.size();i++){
//            std::cout << DES[i]->event << std::endl;
//        }

    std::cout << DES.size() << std::endl;
	DES.clear();
}
