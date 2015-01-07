#ifndef __Cave__
#define __Cave__

#include "GameObject.h"
#include "CartPoint.h"
#include "Fish.h"

class Fish;
class Model;

using namespace std;

class Cave: public GameObject
{
public:
	bool hide_fish(Fish*  fish_to_hide);
	bool release_fish(Fish* fish_to_release);
	bool update();
	void show_status();
	Cave();
	Cave(int in_id, CartPoint in_loc, Model * world);
	~Cave();
	double get_space();
	void save(ofstream& file);

private:
	double space;

protected:
	Model*world;
};


#endif
