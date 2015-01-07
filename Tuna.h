#ifndef __Tuna__
#define __Tuna__

#include "Fish.h"


class Model;
class Cave;

using namespace std;


class Tuna : public Fish
{
public:
	Tuna();
	Tuna(int id, Cave* home, Model*world);
	~Tuna();
	double get_speed();
	bool start_mating(Tuna *fish_mate);
	bool update();
	void show_status();
	int mate_timer;
	void do_mating();
	void save(ofstream& file);

private:
	bool mate_initiator;


};




#endif