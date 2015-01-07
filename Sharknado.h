#ifndef ____Sharknado____
#define ____Sharknado____

#include "GameObject.h"
#include <list>

class Model;

class Sharknado: public GameObject
{
public:
	Sharknado();
	Sharknado(Model * world);
	~Sharknado();
	bool update();
	void erase_fish();


private:
	Model * world;
	int warning = 10;


};





#endif