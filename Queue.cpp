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
	
	t_arrival = 0.0;
	t_departure = 0.0;
	t_observer = 0.0;
	
}

Queue::~Queue()
{
	
}

void Queue::simulate()
{
    int gamma = 3*Random::lambda;
    double packetLength, serviceTime;
    int C_rate = 1000000, L_length = 12000;
    Random *random = new Random();
    
    while(t_arrival < (double)T_time)
    {
            //std::cout<< t_arrival << std::endl;
            t_arrival += random->generateExponentialRanVar();
            //Packet *packet = new Packet(Packet::arrival, t_arrival);
            //delete packet;
            //printf("type: %c\n", packet->event);
            DES[t_arrival] = arrival;
    }
    while(t_observer < (double)T_time)
    {
        t_observer += random->generateExponentialRanVar(gamma);
        DES[t_observer] = observer;
    }
    while(!DES.empty())
    {
        std::map<double,Event>::iterator it = DES.begin();
        Event event = it->second;
        double eventTime = it->first;
        if(event == arrival)
        {
            packetLength = random->generateExponentialRanVar(1.0/L_length);
            serviceTime = packetLength/C_rate;
            if(n_arrivals - n_departures == 0){
                t_departure = eventTime + serviceTime;
            }else{
                t_departure += serviceTime;
            }
            DES[t_departure] = departure;
            n_arrivals++;
            DES.erase(it);
        }
        else if(event == departure){
            n_departures++;
            DES.erase(it);
        }
        else if(event == observer){
            n_observers++;
            n_packets += n_arrivals - n_departures;
            if((n_arrivals - n_departures) == 0){
                n_idle_count++;
            }
            DES.erase(it);
        }
    }
    std::cout<< "Average number of packets: "<< (double)n_departures/n_observers<< std::endl;
    std::cout<< "idle probability: "<< (double)n_idle_count/n_observers<< std::endl;
    std::cout<< "utilization: "<< (double)gamma*L_length/C_rate<< std::endl;
    delete random;
    
//    std::cout << "DES contains:\n";
//    std::map<double,Event>::iterator it = DES.begin();
//    for (it=DES.begin(); it!=DES.end(); ++it){
//        std::cout << it->first << " => " << it->second << '\n';
//    }

}
