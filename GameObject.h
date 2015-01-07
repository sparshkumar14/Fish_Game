#ifndef __GameObject__
#define __GameObject__

#include <iostream>
#include "CartPoint.h"
#include <sstream>
#include <fstream>
//#include "Model.h"

class Model;

class GameObject
{

public:
	GameObject(char in_code, int in_id);
	GameObject(char in_code, int in_id, CartPoint in_loc);
	CartPoint get_location();
	int get_id();
	virtual void show_status();
	int get_id_num();
	virtual bool update() = 0;
	void drawself(char* grid);
	int get_x();
	int get_y();
	virtual ~GameObject();
	virtual void save(ofstream& file);
//	virtual void restore(ifstream& file, Model * model);
	char get_display_char();
	char get_state();

private:
	int id_num;
	//Model * model;

protected:
	CartPoint location;
	char display_code;
	char state;

};

#endif
