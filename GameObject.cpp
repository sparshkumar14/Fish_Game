

#include "GameObject.h"
#include "CartPoint.h"
#include <fstream>

using namespace std;


GameObject::GameObject(char in_code, int in_id)
{
	this->display_code = in_code;
	this->id_num = in_id;
	this->location.x = 0.0;
	this->location.y = 0.0;
	cout << "GameObject default constructed" << endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	this->display_code = in_code;
	this->id_num = in_id;
	this->location.x = in_loc.x;
	this->location.y = in_loc.y;
	cout << "GameObject constructed" << endl;
}

CartPoint GameObject::get_location()
{
	return this->location;
}

int GameObject::get_id()
{
	return this->id_num;
}

void GameObject::show_status()
{
	cout << this->display_code << " with ID " << this->id_num << " at location " << this->location;
}

int GameObject::get_id_num()
{
	return id_num;
}

GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

void GameObject::drawself(char* grid)
{
	*grid = this->display_code;
	*(grid + 1) = '0' + this->id_num;
}

char GameObject::get_display_char(){
	return display_code;
}

void GameObject::save(ofstream& file){
	file << id_num << endl;
	file << location << endl;
	file << display_code << endl;
	file << state << endl;
}

char GameObject::get_state(){
	return state;
}
