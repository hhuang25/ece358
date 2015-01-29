#ifndef PACKET_H
#define PACKET_H
#endif

class Packet
{
	public:
		enum Event {arrival='a', departure='d', observer='o'};
		Event event;
		double time;
		Packet(Event e, double t){event = e; time = t;}
		
		//friend std::ostream& operator<< (std::ostream &out, Packet &packet);
		double GetTime(){return time;}
};
/*
std::ostream& operator<< (std::ostream &out, Packet &packet)
{
	// Since operator<< is a friend of the Point class, we can access
	// Point's members directly.
	out << "(" << packet.event << ", " <<
		packet.time << ")";
	return out;
}
*/
