#ifndef __Shark__
#define __Shark__

#include "Fish.h"
#include <stdlib.h> 
#include <time.h>
#include <iostream>

using namespace std;

class Model;

class Shark : public Fish
{
public:
	Shark();
	Shark(int id_num, CartPoint set_location, Model*world);
	Shark(int id_num, Model*world);
	double get_speed();
	void start_attack(Fish* target);
	bool update();
	void show_status();
	CartPoint random_location();
	void save(ofstream& file);

private:
	int attack_strength;
	double range;
	Fish * target;
	bool attack_range();
};


#endif