#include <iostream>
#include <stdio.h>

#include "Queue.h"
#include "Random.h"

Queue::Queue()
{
    /*
	n_arrivals = 0;
	n_departures = 0;
	n_observers = 0;
	n_idle_count = 0;
	n_packets = 0;
	
	t_arrival = 0.0;
	t_departure = 0.0;
	t_observer = 0.0;
        
        T_time = 10000.0;
	C_rate = 1000000.0;
        L_length = 12000.0;
        lambda = 75.0;
    */
}

Queue::~Queue()
{
	
}

void Queue::simulate()
{
    std::map<double, Event> DES;
    
    double packetLength, serviceTime = 0;
    
    double T_time = 10000;
    double C_rate = 1000000; 
    double L_length = 12000;
    double lambda = ((double)0.25/(double)L_length)*(double)C_rate;
    
    std::cout<<"L = "<<L_length<<std::endl;
    std::cout<<"C = "<<C_rate<<std::endl;
    std::cout<<"lambda = "<<lambda<<std::endl;
    
    double gamma = 3*lambda;
    
    long n_arrivals, n_departures, n_observers, n_idle_count, n_packets;
    double t_arrival, t_departure, t_observer;
    std::cout<<"Hello1"<<std::endl;
    n_arrivals = 0;
    n_departures = 0;
    n_observers = 0;
    n_idle_count = 0;
    n_packets = 0;

    t_arrival = 0.0;
    t_departure = 0.0;
    t_observer = 0.0;
        
    Random *random = new Random();
    int joshcounter = 0;
    int joshcounter_obs = 0;
    
    while(t_arrival < (double)T_time)
    {
            //std::cout<< t_arrival << std::endl;
            t_arrival += random->generateExponentialRanVar(lambda);
            //Packet *packet = new Packet(Packet::arrival, t_arrival);
            //delete packet;
            //printf("type: %c\n", packet->event);
            DES[t_arrival] = arrival;
            
            //std::cout<< "t_arrival: "<< (double)t_arrival<< std::endl;
            joshcounter++;
//            std::cout<<"Hello1.5 "<<t_arrival<<std::endl;
    }
    std::cout<<"Hello2"<<std::endl;
    while(t_observer < (double)T_time)
    {
        t_observer += random->generateExponentialRanVar(gamma);
        DES[t_observer] = observer;
        joshcounter_obs++;
//        std::cout<<"Hello2.5"<<std::endl;
    }
    std::cout<<"done generation of packets!"<<std::endl;
    //while(!DES.empty())
    typedef std::map<double,Event>::iterator it;
    for(it iter = DES.begin(); iter != DES.end(); ++iter)
    {
        //std::map<double,Event>::iterator iter = DES.begin();
        Event event = iter->second;
        double eventTime = iter->first;
        if(event == arrival)
        {
//            std::cout<<"Arrival"<<std::endl;
            //std::cout<< "t_arrival: "<< (double)eventTime<< std::endl;
            packetLength = random->generateExponentialRanVar(1.0/L_length);
            serviceTime = packetLength/(double)C_rate;
            if(n_arrivals - n_departures == 0){
                t_departure = eventTime + serviceTime;
            }else{
                t_departure += serviceTime;
            }
            DES[t_departure] = departure;
            n_arrivals++;
            //DES.erase(iter);
        }
        else if(event == departure){
//            std::cout<<"Departure"<<std::endl;
            n_departures++;
            //DES.erase(iter);
        }
        else if(event == observer){
//            std::cout<<"Observer"<<std::endl;
            n_observers++;
            n_packets += n_arrivals - n_departures;
            if((n_arrivals - n_departures) == 0){
                n_idle_count++;
            }
            //DES.erase(iter);
        }
    }
    std::cout<< "Average number of packets: "<< (double)n_departures/n_observers<< std::endl;
    std::cout<< "idle count: "<< (double)n_idle_count<< std::endl;
    std::cout<< "josh\'s counter: "<< joshcounter<< std::endl;
    std::cout<< "josh\'s observer counter: "<< joshcounter_obs<< std::endl;
    std::cout<< "n_arrivals: "<< n_arrivals<< std::endl;
    std::cout<< "n_departures: "<< n_departures<< std::endl;
    std::cout<< "# of observers: "<< (double)n_observers<< std::endl;
    std::cout<< "idle probability: "<< (double)n_idle_count/n_observers<< std::endl;
//    std::cout<< "utilization: "<< (double)gamma*L_length/C_rate<< std::endl;
    delete random;
    
//    std::cout << "DES contains:\n";
//    std::map<double,Event>::iterator it = DES.begin();
//    for (it=DES.begin(); it!=DES.end(); ++it){
//        std::cout << it->first << " => " << it->second << '\n';
//    }

}
