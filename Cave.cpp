#include "Cave.h"
#include <fstream>

Cave::Cave() : GameObject('c', 0)
{
    this->space = 100;
	this->state = 'e';
	cout << "Cave default constructed" << endl;
}

Cave::Cave(int in_id, CartPoint in_loc, Model * world) : GameObject('c', in_id, location)
{
	this->space = 100;
	this->state = 'e';
	this->location.x = in_loc.x;
	this->location.y = in_loc.y;
	this->world = world;
	cout << "Cave constructed" << endl;
}

bool Cave::hide_fish(Fish* fish_to_hide)
{
 if (fish_to_hide -> is_hidden())
	{
	  return false;
	}
 else
        {
	      if  (this->space >= fish_to_hide -> get_size())
		{
			space -=  fish_to_hide -> get_size();
			return true;
		}
	      else
		{
		  return false;
		}
	}
}

bool Cave::release_fish(Fish* fish_to_release)
{
  if (fish_to_release -> is_hidden())
    {
	  this->space += fish_to_release->get_size();
      return true;
    }
  else
    {
      return false;
    }
}

bool Cave::update()
{
	if (this->space == 0 && this->state != 'p')
	{
		this->state = 'p';
		this->display_code = 'C';

		cout << "Cave " << this->get_id() << " is depleted" << endl;
		return true;
	}
	
	
	else if (this->space != 0 && this->state == 'p')
	{
		state = '\0';
		display_code = 'c';
		return true;
	}
	else
	{
		return false;
	}

}

void Cave::show_status()
{
  cout << "Cave Status: "; 
  GameObject::show_status();
  cout << " has a space of " << space << endl;
}

Cave::~Cave()
{
	cout << "Cave destructed" << endl;
}

double Cave::get_space()
{
	return space;
}

void Cave::save(ofstream& file)
{
	GameObject::save(file);
	file << space << endl;
}



