#include "Shark.h"
#include "Model.h"
#include <cmath>



Shark::Shark() : Fish('S', 20)
{
	attack_strength = 2;
	range = 1;
	cout << "Shark default constructed" << endl;
}

Shark::Shark(int id_num, CartPoint set_location, Model*world) : Fish('S', 20, set_location, id_num, world)
{
	attack_strength = 2;
	range = 1;
	cout << "Shark constructed" << endl;
}

Shark::Shark(int id_num, Model *world) : Fish('S', 20, random_location(), id_num, world)
{
	attack_strength = 2;
	range = 1;
	cout << "Shark constructed" << endl;
}

CartPoint Shark::random_location()
{
	srand(world->get_time());
	CartPoint random;
	random.x = rand() % 20;
	random.y = rand() % 20;
	return random;
}

double Shark::get_speed()
{
	double speed = (1 / get_size())* get_energy() * 8;
	return speed;
}

bool Shark::update()
{
	if (state == 'x') { return false; }
	else if (state == 's') { return false; }
	else if (state == 'e') { 
		if (Fish::update()) { 
			return true; } 
		else { 
			return false; } }
	else if (state == 'a')
	{
		if (attack_range())
		{
			if ((this->target)->is_alive())
			{
				cout << "Chomp!" << endl;
				target->get_bitten(this->attack_strength);
				return false;
			}
			else
			{
				cout << "I triumph!" << endl;
				this->state = 's';
				energy += 5;

				Tuna * dead = dynamic_cast<Tuna*>(target);

				world->move_dead_tuna_from_list(dead);
				target = NULL;
				return true;
			}
		}
		else
		{
			cout << "Darn! It escaped." << endl;
			target = NULL;
			this->state = 's';
		}
		
		return false;
	}
	else { if (Fish::update()) { return true; } else { return false; } }
}

void Shark::show_status()
{
	cout << "Shark status: ";
	Fish::show_status();
	cout << endl;
	
}

void Shark::start_attack(Fish* target)
{
	this->target = target;
//	CartVector range = (this->get_destination()) - ((this->target)->get_destination());
//	if ((sqrt(pow(range.x, 2) + pow(range.y, 2))) <= (this->range))
	if ((abs(cart_distance((this->location), ((this->target)->get_location())))) <= 1)
	{
		this->state = 'a';
		cout << "Chomp!" << endl;
		target->get_bitten(this->attack_strength);
	}
	else
	{
		cout << "Fish are friends. Not food!" << endl;
		(this->target) = NULL;
	}
}

bool Shark::attack_range()
{
	if ((abs(cart_distance((this->location), ((this->target)->get_location())))) <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Shark::save(ofstream& file)
{
	Fish::save(file);
	file << attack_strength << endl;
	file << range << endl;
	if ((this->target) == NULL){
		file << -1 << endl;
	}
	else{
		file << (this->target)->get_id() << endl;
	}
}
