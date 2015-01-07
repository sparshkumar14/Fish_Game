#include "Model.h"
#include "Tuna.h"
#include "Shark.h"
#include "Cave.h"
#include "Sharknado.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>



using namespace std;


Model::Model()
{
	time = 0;

	cave_list.push_back(new Cave(1, CartPoint(5, 1), this));
	cave_list.push_back(new Cave(2, CartPoint(6, 2), this));

	reef_list.push_back(new CoralReef(1, CartPoint(1, 20)));
	reef_list.push_back(new CoralReef(2, CartPoint(20, 1)));
	reef_list.push_back(new CoralReef(3, CartPoint(20, 20)));

	tuna_list.push_back(new Tuna(1, get_Cave_ptr(1), this));
	tuna_list.push_back(new Tuna(2, get_Cave_ptr(2), this));
	tuna_list.push_back(new Tuna(3, get_Cave_ptr(2), this));

	shark_list.push_back(new Shark(4, random(), this));
	shark_list.push_back(new Shark(5, random(), this));

//	sharknado_list.push_back(new Sharknado(this));

	fish_list.insert(fish_list.end(), tuna_list.begin(), tuna_list.end());
	fish_list.insert(fish_list.end(), shark_list.begin(), shark_list.end());
	
	/*
	fish_list.push_back(new Tuna(1, get_Cave_ptr(1), this));
	fish_list.push_back(new Tuna(2, get_Cave_ptr(2), this));
	fish_list.push_back(new Tuna(3, get_Cave_ptr(2), this));
	

	fish_list.push_back(new Shark(4, random(), this));
	fish_list.push_back(new Shark(5, random(), this));
	*/


	object_list.insert(object_list.end(), cave_list.begin(), cave_list.end());
	object_list.insert(object_list.end(), reef_list.begin(), reef_list.end());
	object_list.insert(object_list.end(), fish_list.begin(), fish_list.end());
//	object_list.insert(object_list.end(), sharknado_list.begin(), sharknado_list.end());

	/*

	cave_ptrs[0] = new Cave(1, CartPoint(5, 1), this);
	cave_ptrs[1] = new Cave(2, CartPoint(6, 2), this);
	reef_ptrs[0] = new CoralReef(1, CartPoint(1, 20));
	reef_ptrs[1] = new CoralReef(2, CartPoint(20, 1));
	reef_ptrs[2] = new CoralReef(3, CartPoint(20, 20));
	fish_ptrs[0] = new Tuna(1, cave_ptrs[0], this);
	fish_ptrs[1] = new Tuna(2, cave_ptrs[1], this);
	fish_ptrs[2] = new Tuna(3, cave_ptrs[1], this);
	fish_ptrs[3] = new Shark(4, CartPoint(10, 15), this);
	fish_ptrs[4] = new Shark(5, CartPoint(15, 10), this);

	object_ptrs[0] = cave_ptrs[0]; 
	object_ptrs[1] = cave_ptrs[1];
	object_ptrs[2] = reef_ptrs[0];
	object_ptrs[3] = reef_ptrs[1];
	object_ptrs[4] = reef_ptrs[2];
	object_ptrs[5] = fish_ptrs[0];
	object_ptrs[6] = fish_ptrs[1];
	object_ptrs[7] = fish_ptrs[2];
	object_ptrs[8] = fish_ptrs[3];
	object_ptrs[9] = fish_ptrs[4];
	*/
	
	cout << "Model default constructed" << endl;

}

Model::~Model()
{
	
	list<GameObject*>::iterator ptr_go;
	for (ptr_go = object_list.begin(); ptr_go != object_list.end(); ptr_go++){
		delete *ptr_go;
		}
	list<Fish*>::iterator ptr_fish;
	for (ptr_fish = fish_list.begin(); ptr_fish != fish_list.end(); ptr_fish++){
		delete *ptr_fish;
	}
	list<Cave*>::iterator ptr_cave;
	for (ptr_cave = cave_list.begin(); ptr_cave != cave_list.end(); ptr_cave++){
		delete *ptr_cave;
	}
	list<CoralReef*>::iterator ptr_reef;
	for (ptr_reef = reef_list.begin(); ptr_reef != reef_list.end(); ptr_reef++){
		delete *ptr_reef;
	}
	list<Tuna*>::iterator ptr_tuna;
	for (ptr_tuna = tuna_list.begin(); ptr_tuna != tuna_list.end(); ptr_tuna++){
		delete *ptr_tuna;
	}
	list<Shark*>::iterator ptr_shark;
	for (ptr_shark = shark_list.begin(); ptr_shark != shark_list.end(); ptr_shark++){
		delete *ptr_shark;
	}
	cout << "Model destructed." << endl;
	
	/*
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}
	*/
	
}

Fish* Model::get_Fish_ptr(int id_num)
{
	list<Fish*>::iterator ptr;
	for (ptr = fish_list.begin(); ptr != fish_list.end(); ptr++)
	{
		if (id_num == (((*ptr)->get_id()))) {
			return *ptr;
		}
	}
	return NULL;
	/*
	for (int i = 0; i < num_fish; i++)
	{
		if (fish_ptrs[i]->get_id() == id_num)
		{
			return fish_ptrs[i];
		}
		else
		{
			continue;
		}
	}
	return NULL; */
}

CoralReef* Model::get_CoralReef_ptr(int id_num)
{
	list<CoralReef*>::iterator ptr;
	for (ptr = reef_list.begin(); ptr != reef_list.end(); ptr++)
	{
		if (id_num == (((*ptr)->get_id()))) {
			return *ptr;
		}
	}
	return NULL;
	/*for (int i = 0; i < num_reefs; i++)
	{
		if (reef_ptrs[i]->get_id() == id_num)
		{
			return reef_ptrs[i];
		}
		else
		{
			continue;
		}
	}
	return NULL; */
}

Cave* Model::get_Cave_ptr(int id_num)
{
	
	/*
	for (int i = 0; i < num_caves; i++)
	{
		if (cave_ptrs[i]->get_id() == id_num)
		{
			return cave_ptrs[i];
		}
		else
		{
			continue;
		}
	}
	return NULL;
	*/
	
	list<Cave*>::iterator ptr;
	for (ptr = cave_list.begin(); ptr != cave_list.end(); ptr++)
	{
		if (id_num == (((*ptr)->get_id()))) {
			return *ptr;
		}
	}
	return NULL;
}

bool Model::update()
{
	time++;
	bool clicker = false;
	/*
	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->update())
		{
			update = true;
		}
	}
	*/
	list<GameObject*>::iterator ptr;
	for (ptr = object_list.begin(); ptr != object_list.end(); ptr++){
		if ((*ptr)->update()) {
			clicker = true;
				}
	}

	if (clicker){
		return true;
	}
	else{
		return false;
	}
	/*
	int True[7];
	//bool bUpdate = false;
	for (int i = 0; i < num_objects; i++)
	{
		int y = (object_ptrs[i]->update());
		True[i] = y;
	}
//if object_ptrs->update()
//return true
	for (int i = 0; i < num_objects; i++)
	{
		if (True[i] == 1)
			return true;
	}
	return false;
  */
}

void Model::show_status()
{
	cout << "---Fish---" << endl;
	list<Tuna*>::iterator ptr_tuna;
	for (ptr_tuna = tuna_list.begin(); ptr_tuna != tuna_list.end(); ptr_tuna++){
	(*ptr_tuna)->show_status();
	}
	list<Shark*>::iterator ptr_shark;
	for (ptr_shark = shark_list.begin(); ptr_shark != shark_list.end(); ptr_shark++){
		(*ptr_shark)->show_status();
	}
	cout << "---Cave---" << endl;
	list<Cave*>::iterator ptr_cave;
	for (ptr_cave = cave_list.begin(); ptr_cave != cave_list.end(); ptr_cave++){
		(*ptr_cave)->show_status();
	}
	cout << "---Reef---" << endl;
	list<CoralReef*>::iterator ptr_reef;
	for (ptr_reef = reef_list.begin(); ptr_reef != reef_list.end(); ptr_reef++){
		(*ptr_reef)->show_status();
	}
	/*for (int i = 0; i < num_objects; i++)
	{
		object_ptrs[i]->show_status();
	} */
}

void Model::display(View& view)
{
	cout << "Time: " << time << endl;
	view.clear();

	list<GameObject*>::iterator ptr;
	for (ptr = object_list.begin(); ptr != object_list.end(); ptr++){
		view.plot(*ptr);
	}
	view.draw();
	/*
	for (int i = 0; i < num_objects; i++)
	{
		view.plot(object_ptrs[i]);
	}
	*/
}

bool Model::if_reef_id_is_present(int ID)
{
	list<CoralReef*>::iterator ptr;
	bool check = false;
	for (ptr = reef_list.begin(); ptr != reef_list.end(); ptr++){
		if ((*ptr)->get_id() == ID){
			check = true;
			break;
		}
	}
	return check;
}

bool Model::if_cave_id_is_present(int ID)
{
	list<Cave*>::iterator ptr;
	bool check = false;
	for (ptr = cave_list.begin(); ptr != cave_list.end(); ptr++){
		if ((*ptr)->get_id() == ID){
			check = true;
			break;
		}
	}
	return check;
}

bool Model::if_fish_id_is_present(int ID)
{
	list<Fish*>::iterator ptr;
	bool check = false;
	for (ptr = fish_list.begin(); ptr != fish_list.end(); ptr++){
		if ((*ptr)->get_id() == ID){
			check = true;
			break;
		}
	}
	return check;

}

void Model::add_new_object(GameObject* object)
{
	if (CoralReef * reef_ptr = dynamic_cast<CoralReef*>(object)) {
		object_list.push_back(reef_ptr);
		reef_list.push_back(reef_ptr);
	}
	else if (Cave * cave_ptr = dynamic_cast<Cave*>(object)){
		object_list.push_back(cave_ptr);
		cave_list.push_back(cave_ptr);
	}
	else if (Tuna * tuna_ptr = dynamic_cast<Tuna*>(object)){
		object_list.push_back(tuna_ptr);
		fish_list.push_back(tuna_ptr);
		tuna_list.push_back(tuna_ptr);
	}
	else if (Shark * shark_ptr = dynamic_cast<Shark*>(object)){
		object_list.push_back(shark_ptr);
		fish_list.push_back(shark_ptr);
		shark_list.push_back(shark_ptr);
	}
}

CartPoint Model::random()
{
	CartPoint random;
	random.x = rand() % 20;
	random.y = rand() % 20;
	return random;
}

Tuna* Model::find_a_mate_for(Tuna* tuna)
{
	list<Tuna*>::iterator ptr;
	for (ptr = tuna_list.begin(); ptr != tuna_list.end(); ptr++){
		if (tuna->get_home() == (*ptr)->get_home()){
			if ((tuna->get_home())->get_space() > 10){
				if (tuna->get_size() >= 40 && tuna->get_size() <= 60 && (*ptr)->get_size() >= 40 && (*ptr)->get_size() <= 60){
					if ((100 - (tuna->get_size() + (*ptr)->get_size())) == (tuna->get_home())->get_space()){
						if (tuna != (*ptr)){
							cout << "F" << tuna->get_id() << ": I found my mate!" << endl;
							return *ptr;
						}
					}
				}
			}
		}
	}
	return NULL;
}

int Model::get_highest_fish_id_number(){

	int new_id = 0;
	list<Fish*>::iterator ptr;
	for (ptr = fish_list.begin(); ptr != fish_list.end(); ptr++){
		if ((*ptr)->get_id() > new_id){
			new_id = (*ptr)->get_id();
		}
	}
	return (new_id + 1);
}

void Model::move_dead_tuna_from_list(Tuna* dead_tuna_shark)
{
	list<Tuna*>::iterator ptr;
	for (ptr = tuna_list.begin(); ptr != tuna_list.end(); ptr++){
		if ((*ptr) == dead_tuna_shark){
			dead_tuna.insert(dead_tuna.end(), dead_tuna_shark);
			ptr = tuna_list.erase(ptr);
		}
	}
	list<GameObject*>::iterator ptr_go;
	for (ptr_go = object_list.begin(); ptr_go != object_list.end(); ptr_go++){
		if ((*ptr_go) == dead_tuna_shark){
			ptr_go = object_list.erase(ptr_go);
		}
	}

}

void Model::save(ofstream& file){

//	file.open();
	file << time << endl;
	list<GameObject*>::iterator ptr_go;
	list<Cave*>::iterator ptr_cave;
	list<Tuna*>::iterator ptr_tuna;
	list<Shark*>::iterator ptr_shark;
	list<CoralReef*>::iterator ptr_reef;

	cout << "Number of objects: " << object_list.size() << endl;
	cout << "------GameObjects Saved------" << endl;
	for (ptr_go = object_list.begin(); ptr_go != object_list.end(); ptr_go++){
		file << (*ptr_go)->get_display_char() << (*ptr_go)->get_id() << endl;
		cout << (*ptr_go)->get_display_char() << (*ptr_go)->get_id() << endl;
	}

	for (ptr_cave = cave_list.begin(); ptr_cave != cave_list.end(); ptr_cave++){
		(*ptr_cave)->save(file);
	}
	
	for (ptr_reef = reef_list.begin(); ptr_reef != reef_list.end(); ptr_reef++){
		(*ptr_reef)->save(file);
	}
	
	for (ptr_tuna = tuna_list.begin(); ptr_tuna != tuna_list.end(); ptr_tuna++){
		(*ptr_tuna)->save(file);
	}

}
void Model::restore(ifstream& file){
}

int Model::get_time()
{
	return time;
}