#include "GameCommand.h"
#include "InputHandling.h"
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

void do_swim_command(Model& model)
{
	int ID;
	double x;
	double y;
	cin >> ID;
	cin >> x;
	cin >> y;
	if (model.get_Fish_ptr(ID)==NULL) { throw InvalidInput("Fish ID number doesn't exist!"); }
	if (x > 20 || x < 0) { throw InvalidInput("X coordinate is out of range"); }
	if (y > 20 || y < 0) { throw InvalidInput("Y coordinate is out of range"); }
	CartPoint dest = CartPoint(x, y);
	cout << "Swimming " << ID << " to " << dest << endl;
	model.get_Fish_ptr(ID)-> start_swimming(dest);
}

void do_eat_command(Model& model)
{
	int ID_1; 
	int ID_2;
	if (!(cin >> ID_1)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw InvalidInput("Was expecting an integer?");
	}
	if (!(cin >> ID_2)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw InvalidInput("Was expecting an integer?");
		} 
	if (model.get_Fish_ptr(ID_1) == NULL) { throw InvalidInput("Fish ID number doesn't exist!"); }
	if (model.get_CoralReef_ptr(ID_2) == NULL) { throw InvalidInput("Reef ID number doesn't exist!"); }

		model.get_Fish_ptr(ID_1)->start_eating(model.get_CoralReef_ptr(ID_2));

	
}

void do_float_command(Model& model)
{
	int ID;
	if (!(cin >> ID)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw InvalidInput("Was expecting an integer?");
	}
	if (model.get_Fish_ptr(ID) == NULL) { throw InvalidInput("Fish ID number doesn't exist!"); }
	model.get_Fish_ptr(ID)->float_in_place();
}

void do_zoom_command(Model& model)
{
	int ID_1;
	int ID_2;
	cin >> ID_1;
	cin >> ID_2;
	if (model.get_Fish_ptr(ID_1) == NULL) { throw InvalidInput("Fish ID number doesn't exist!"); }
	if (model.get_Cave_ptr(ID_2) == NULL) { throw InvalidInput("Cave ID number doesn't exist!"); }
	model.get_Fish_ptr(ID_1)->start_hiding(model.get_Cave_ptr(ID_2));
}

void do_go_command(Model& model)
{
	cout << "Advancing one tick" << endl;
	model.update();
	model.show_status();
}

void do_run_command(Model& model)
{
	cout << "Advancing to the next event" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (model.update())
		{
			break;
		}
	}
	model.show_status();
}

void do_new_command(Model& model)
{
	char type;
	cin >> type;
	if (type == 'R')
	{
		int ID;
		int X;
		int Y;
		cin >> ID;
		cin >> X;
		cin >> Y;
		if (model.if_reef_id_is_present(ID)) { throw InvalidInput("Reef ID already exists!"); }
		if (X > 20 || X < 0) { throw InvalidInput("X coordinate is out of range"); }
		if (Y > 20 || Y < 0) { throw InvalidInput("Y coordinate is out of range"); }
		model.add_new_object(new CoralReef(ID, CartPoint(X, Y)));
	}
	else if (type == 'C')
	{
		int ID;
		int X;
		int Y;
		cin >> ID;
		cin >> X;
		cin >> Y;
		if (model.if_cave_id_is_present(ID)) { throw InvalidInput("Cave ID already exists!"); }
		if (X > 20 || X < 0) { throw InvalidInput("X coordinate is out of range"); }
		if (Y > 20 || Y < 0) { throw InvalidInput("Y coordinate is out of range"); }
		model.add_new_object(new Cave(ID, CartPoint(X, Y), &model));
	} 
	else if (type == 'T')
	{
		int ID;
		int ID_HOME;
		cin >> ID;
		cin >> ID_HOME;
		if (model.if_fish_id_is_present(ID)) { throw InvalidInput("Fish ID already exists!"); }
		if (!(model.if_cave_id_is_present(ID_HOME))) { throw InvalidInput("Cave ID does not exist!"); }
		model.add_new_object(new Tuna(ID, model.get_Cave_ptr(ID_HOME), &model));
	}
	else if (type == 'S')
	{
		int ID;
		cin >> ID;
		if (model.if_fish_id_is_present(ID)) { throw InvalidInput("FIsh ID already exists!"); }
		srand(time(NULL));
		CartPoint random;
		random.x = rand() % 20;
		random.y = rand() % 20;
		model.add_new_object(new Shark(ID, random, &model));
	}
	else{
		throw InvalidInput("Invalid Type!");
	}

	cout << "Adding a new object!" << endl;

}

void do_attack_command(Model& model)
{
	int ID_1;
	int ID_2;
	cin >> ID_1;
	cin >> ID_2;
	if (model.get_Fish_ptr(ID_1) == NULL) { throw InvalidInput("Fish ID_1 number doesn't exist!"); }
	if (model.get_Fish_ptr(ID_2) == NULL) { throw InvalidInput("Fish ID_2 number doesn't exist!"); }
	model.get_Fish_ptr(ID_1)->start_attack(model.get_Fish_ptr(ID_2));

}

void do_save_command(Model& model)
{
	string file_name;
	cin >> file_name;
	ofstream foo(file_name.c_str());
	model.save(foo);
}
void do_restore_command(Model& model)
{
	string file_name;
	cin >> file_name;
	ifstream fah(file_name.c_str());
	model.restore(fah);
	//Yeah I have no clue on how to make the program read the file properly
}