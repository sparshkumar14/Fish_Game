#include "Fish.h"
#include "Cave.h"
#include <cmath>



Fish::Fish(char display_code, int size_of_fish) : GameObject(display_code, 0){
	this->energy = 15;
	this->size = size_of_fish;
	this->prefeast_size = size;
	this->reef = NULL;
	this->state = 'f';
	this->home = NULL;
	CartPoint destination = CartPoint();
	cout << "Fish Default Constructed" << endl;
}

Fish::Fish(char display_code, int size_of_fish, Cave* home, int in_id, Model*world) : GameObject(display_code, in_id, home->get_location()){
	this->energy = 15;
	this->size = size_of_fish;
	this->prefeast_size = size;
	this -> home = home;
	this->world = world;
	state = 'f';
	if (home -> hide_fish(this))
	  {
	    state = 'h';
	  }
	cout << "Fish Constructed" << endl;
}

Fish::Fish(char display_code, int size_of_fish, CartPoint starting_location, int in_id, Model*world) : GameObject(display_code, in_id, starting_location){
	this->energy = 15;
	this->size = size_of_fish;
	this->prefeast_size = size;
	this->reef = NULL;
	this->home = NULL;
	this->world = world;
	state = 'f';
	cout << "Fish Constructed" << endl;
}

void Fish::setup_destination(CartPoint dest){
	this->destination = dest;
	this->delta = (this->destination - this->location) * (this->get_speed() / cart_distance(this->destination, this->location));
}

bool Fish::update()
{
	switch (this->state)
	{
	case 'f':
       	  return false;
    case 's':
	  if (Fish::update_location())
	    {
		  this->state = 'f';
	      return true;
	    }
	  else
	    {
	      return false;
	    }
	  break;
    case 'e':   
		if (this->size >= 2*this->prefeast_size)
		{
			setup_destination(home->get_location());
			this->state = 'z';
			cout << this->display_code << "" << this->get_id() << ": I'm full! I'm heading home! " << endl;
			return true;
		}

		if (!(this->reef)->is_empty())
		{
		this->size += (this->reef)->provide_food() / 2;
		cout << this->display_code << "" << this->get_id() << ": Grew to size " << this->size << endl;
		return true;
		}
		else
		{
		state = 'f';
		cout << display_code << "" << get_id() << ": this reef has no more food for me" << size << endl;
		}
     case 'z':
		if (update_location())
		{
			if ((this->home)->hide_fish(this))
			{
				this->state = 'h';
				cout << this->display_code << "" << this->get_id() << ": I am hidden and safe" << endl;
				return true;
			}
			else
			{
				this->state = 'p';
				cout << this->display_code << "" << this->get_id() << ": Help! My home is full" << endl;
				return true;
			}
		}
	  else
	  {
		  return false;
	  }
		break;
	case 'o':
	{
		if (update_location())
		{
			this->state = 'e';
			this->prefeast_size = this->size;
			cout << this->display_code << this->get_id() << ": Starting to dine at a coral reef" << endl;
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
    case 'h':
		energy -= (.25)*energy;
		if (energy < 5)
		{
			state = 'x';
			return true;
		}
		else
		{
			return false;
		}

    case 'p':
	  return false;
	case 'x':
		return false;
	  
    default:
	  return false;

	}

}

double Fish::get_size(){
	return size;
}

bool Fish::is_hidden(){
	if (state == 'h')
		return true;
	else
		return false;
}

double Fish::get_speed()
{
	return (1 / size) * (energy)* 5;
}

void Fish::start_swimming(CartPoint dest)
{
	if (this->is_hidden())
    {
      home -> release_fish(this);
    }
	destination = dest;
	setup_destination(destination);
	state = 's';
	cout << "F" << get_id() << ": On my way" << endl;
}

void Fish::start_eating(CoralReef* destReef)
{
    if(is_hidden())
    {
      home -> release_fish(this);
    }
    reef = destReef;
    setup_destination(destReef -> get_location());
    state = 'o';
    cout << "Fish " << get_id() << " eating at CoralReef " << reef->CoralReef::get_id() << " and returning back to Cave " << (this->home)->Cave::get_id() << endl;
//	cout << "F" << get_id() << ": Food here I come!" << endl;
}

void Fish::start_hiding(Cave* destCave)
{
    if(is_hidden())
    {
      home -> release_fish(this);
    }
    home = destCave;
    setup_destination(destCave -> get_location());
    state = 'z';
    cout << "Fish " << get_id() << " swimming to Cave " << destCave -> get_id() << endl;
	cout << "Off to safety" << endl;

}

void Fish::float_in_place()
{
    if(is_hidden())
    {
      home -> release_fish(this);
    }
    state = 'f';
    cout << "Stopping " << get_id() << endl;
    cout << display_code << "" << get_id() << " resting my fins" << endl;
}

void Fish::show_status()
{
 //cout << "Fish status: ";
 GameObject::show_status();
 switch (state)
   {
 case 'f':
    cout << " is floating. Has a size of: " << size  << " and energy of: " << energy;
    break;
 case 's':
	 cout << " Has a speed of: " << get_speed() << " and is heading to: " << destination;
    break;
 case 'o':
    cout << " is outbound to Reef: " << reef -> get_id() << " with a speed of " << get_speed();
    break;
 case 'e':  
   cout << " is eating at Reef " << reef -> get_id();
   break;
 case 'z':
      cout << " is swimming to Cave " << home -> get_id() << " with a speed of " << get_speed();
      break;
 case 'h':
   cout << " is hidden in Cave " <<  home -> get_id();
      break;
 case 'p':
      cout << " is panicked";
      break;
 default:
	 break;
   }
}

bool Fish::update_location()
{
  CartVector v = destination - location; 
  if (fabs(v.x) <= fabs(delta.x) && fabs(v.y) <= fabs(delta.y))
    {
      location = destination;
      cout << "F" << get_id() << ": I'm there" << endl;
     return true;
    }
  else
    {
      location = location + delta;
	  cout << "F" << get_id() << ": Just keep swimming..." << endl;
      return false;
    }

  return true;
}
  
Fish::~Fish()
{
	cout << "Fish destructed" << endl;
}

void Fish::start_attack(Fish* fish)
{
	cout << "I cannot attack" << endl;
}

void Fish::start_mating(Fish* fish)
{
	cout << "I cannot mate" << endl;
}

void Fish::get_bitten(int attack_strength)
{
	energy -= attack_strength;
	if (energy <= 0)
	{
		cout << "Oh no, I've become chum!" << endl;
		this->state = 'x';
	}
	else
	{
		cout << "Ouch" << endl;
	}
}

double Fish::get_energy(){
	return energy;
}

Cave* Fish::get_home(){
	return home;
}

CartPoint Fish::get_destination(){
	return destination;
}

bool Fish::is_alive(){
	if (state != 'x')
		return true;
	else
		return false;
}

void Fish::save(ofstream& file)
{
	GameObject::save(file);
	file << size << endl;
	file << prefeast_size << endl;
	file << destination << endl;
	file << delta << endl;
	if ((this->reef) == NULL){
		file << -1 << endl;
	}
	else{
		file << (this->reef)->get_id() << endl;
	}
	file << (this->home)->get_id() << endl;
}