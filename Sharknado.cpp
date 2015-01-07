#include "Sharknado.h"
#include "Model.h"
#include "Fish.h"


Sharknado::Sharknado() :GameObject('N',0)
{

}

Sharknado::Sharknado(Model*world) : GameObject('N', 1)
{
	this->world = world;
	location = CartPoint(-132, -10);
}


Sharknado::~Sharknado()
{
	cout << "Sharknado destructed" << endl;
}

bool Sharknado::update()
{
	if (((this->world)->get_time()) % warning == 0){
		cout << "Early Sharknado Warning!" << endl;
		warning += 15; //Should be giving warnings at time 10, 25, 40, 55, etc....
		return true;
	}
	
	else if (((this->world)->get_time()) % 15 == 0){
		cout << "Goodbye fishies!" << endl;
		erase_fish();
		return true;
	}
	else { return false; }
}

void Sharknado::erase_fish()
{
	list<Tuna*>::iterator ptr_tuna = world->tuna_list.begin();
	while (ptr_tuna != world->tuna_list.end())
		{
		if ((*ptr_tuna)->get_state() != 'h')
		{
		(world->dead_fish).insert((world->dead_fish).end(), (*ptr_tuna));
		ptr_tuna = (world->tuna_list).erase(ptr_tuna);
		}
		else
		{
			++ptr_tuna;
		}
		}

	list<Shark*>::iterator ptr_shark = world->shark_list.begin();
	while (ptr_shark != world->shark_list.end())
	{
			(world->dead_fish).insert((world->dead_fish).end(), (*ptr_shark));
			ptr_shark = (world->shark_list).erase(ptr_shark);
		}
	
	
	list<GameObject*>::iterator ptr_go = world->object_list.begin();
	list<Fish*>::iterator ptr_fish = world->dead_fish.begin();
	/*
	while (ptr_fish != world->dead_fish.end()){
		while (ptr_go != world->object_list.end()){
			if (*ptr_go == *ptr_fish){
				ptr_go = (world->object_list).erase(ptr_go);
			}
			else{ ++ptr_go; }
		}
		++ptr_fish;
	} 
	*/
	
	for (ptr_fish; ptr_fish != (world->dead_fish).end(); ptr_fish++){
		for (ptr_go; ptr_go != (world->object_list).end(); ptr_go++){
			if ((*ptr_go) == (*ptr_fish)){
				ptr_go = (world->object_list).erase(ptr_go);
			}
		} ++ptr_fish;
	} 



}
