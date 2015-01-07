#ifndef __Model__
#define __Model__


#include "Fish.h"
#include "Cave.h"
#include "CoralReef.h"
#include "View.h"
#include "Tuna.h"
#include "Shark.h"
#include <stdlib.h> 
#include <list>
#include <fstream>



class GameObject;
class Fish;
class Cave;
class CoralReef;
class Tuna;
class Shark;
class View;
//class Sharknado;


class Model
{
public:
	Model();
    Fish* get_Fish_ptr(int id_num);
	CoralReef* get_CoralReef_ptr(int id_num);
	Cave* get_Cave_ptr(int id_num);
	Tuna* find_a_mate_for(Tuna* tuna);
	bool update();
	void display(View& view);
	void show_status();
	~Model();
	void create_new_tuna();
	bool if_fish_id_is_present(int ID);
	bool if_reef_id_is_present(int ID);
	bool if_cave_id_is_present(int ID);
	void add_new_object(GameObject* object);
	int get_highest_fish_id_number();
	void move_dead_tuna_from_list(Tuna* dead_tuna_shark);
	std::list<Cave*> cave_list;
	std::list<Fish*> fish_list;
	std::list<CoralReef*> reef_list;
	std::list<GameObject*> object_list;
	std::list<Tuna*> tuna_list;
	std::list<Shark*> shark_list;
	std::list<Fish*> dead_fish;
//	std::list<Sharknado*> sharknado_list;
	void save(ofstream& file);
	void restore(ifstream& file);
	int get_time();

private:
	int time;
	/*GameObject** object_ptrs;
	int num_objects;
	Fish** fish_ptrs;
	int num_fish;
	Cave** cave_ptrs;
	int num_caves;
	CoralReef** reef_ptrs;
	int num_reefs; */

	CartPoint random();
	std::list<Tuna*> dead_tuna;  //Store the tuna that the shark have killed

};


#endif