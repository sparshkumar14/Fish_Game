#ifndef __Fish__
#define __Fish__


#include "GameObject.h"
#include "CoralReef.h"

class Cave;
class Model;

using namespace std;

class Fish : public GameObject
{
public:
	Fish(char display_code, int size);
	Fish(char display_code, int size_of_fish, Cave* home, int in_id, Model*world);
	Fish(char display_code, int size_of_fish, CartPoint starting_location, int in_id, Model*world);
	~Fish();
	virtual bool update();
	double get_size();
	void start_swimming(CartPoint dest);
	void start_eating(CoralReef* destReef);
	bool is_hidden();
	void start_hiding(Cave* destCave);
	void float_in_place();
	void show_status();
	virtual double get_speed() = 0;
	virtual void start_attack(Fish* fish);
	virtual void start_mating(Fish* fish);
	void get_bitten(int attack_strength);
	double get_energy();
	Cave* get_home();
	CartPoint get_destination();
	virtual bool is_alive();
	void save(ofstream& file);

private:
	double size;
	double prefeast_size;
	CartPoint destination;
	CartVector delta;
	CoralReef* reef;
	Cave* home;
	bool update_location();
	void setup_destination(CartPoint dest);

protected:
	Model*world;
	double energy;
};

#endif
