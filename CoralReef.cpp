

#include "CoralReef.h"


CoralReef::CoralReef(): GameObject('R', 0)
{
	this->state = 'f';
	this->amount = 100;
	cout << "CoralReef default constructed" << endl;
}

CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject('R', in_id, location)
{
	this->state = 'f';
	this->location.x = in_loc.x;
	this->location.y = in_loc.y;
	amount = 100;
	cout << "CoralReef constructed" << endl;

}

bool CoralReef::is_empty()
{
	if (amount == 0)
		return true;
	else
		return false;
}

double CoralReef::provide_food(double amount_to_provide)
{
	if (this->amount >= amount_to_provide)
	{
		this->amount = amount - amount_to_provide;
		return amount_to_provide;
	}
	else
	{
		double a = this->amount;
		this->amount = 0;
		return a;
	}
}

bool CoralReef::update()
{
	if (this->is_empty() && state != 'e')
	{
		this->state = 'e';
		this->display_code = 'r';
		cout << "CoralReef " << this->get_id() << " has been depleted" << endl;
		return true;
	}
	else
		return false;
}

void CoralReef::show_status()
{
  cout << "CoralReef Status: ";
  GameObject::show_status();
  cout << " containing food " << this->amount << endl;
}

CoralReef::~CoralReef()
{
	cout << "CoralReef Destructed" << endl;
}

void CoralReef::save(ofstream& file)
{

}
