#ifndef __CoralReef__
#define __CoralReef__


#include "GameObject.h"
#include "CartPoint.h"


class CoralReef: public GameObject
{
public:
	CoralReef();
	CoralReef(int in_id, CartPoint in_loc);
	bool is_empty();
	double provide_food(double amount_to_provide = 20.0);
	bool update();
	void show_status();
	void save(ofstream& file);

	~CoralReef();

private:
	double amount;


};

#endif