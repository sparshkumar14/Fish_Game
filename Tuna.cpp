#include "Tuna.h"
#include "Cave.h"
#include "Model.h"


Tuna::Tuna(): Fish('T', 10){
	mate_initiator = false;
	mate_timer = 0;
	cout << "Tuna default constructed" << endl;
}

Tuna::Tuna(int id, Cave* home, Model*world) : Fish('T', 10, home, id, world) {
	mate_initiator = false;
	mate_timer = 0;
	cout << "Tuna constructed" << endl;
}

Tuna::~Tuna(){
	cout << "Tuna destructed" << endl;
}

double Tuna::get_speed(){
	double speed = (1 / get_size())* get_energy() * 4;
	return speed;
}

void Tuna::show_status(){
	if (state == 'm')
	{
		cout << "Tuna Status: ";
		Fish::show_status();
		cout << " is mating" << endl;
	}
	else
	{
		cout << "Tuna status: ";
		Fish::show_status();
		cout << endl;
	}

}

bool Tuna::update()
{
	if (state == 'h')
	{
		Tuna * mate = world->find_a_mate_for(this);
		if (mate == NULL){
			return false;
		}
		else{
			this->mate_initiator = true;
			mate->do_mating();
			start_mating(this);
			
		}
	}
	
	else if (state == 'm')
	{
		if (mate_timer == 2 && mate_initiator)
		{
/*			if (!(mate_initiator)){
			{this->mate_timer++;
				return false; 
					}
				mate_timer = 0;
				(this->state) = 'h'; 
			}
//			else{ */
				world->add_new_object(new Tuna((world->get_highest_fish_id_number()), this->get_home(), world));
				mate_timer = 0;
				(this->state) = 'h';
				mate_initiator = false;
				return true;
//			}
			
		}
		if (mate_timer == 3)    //for the non iniciator
		{
			mate_timer = 0;
			(this->state) = 'h';
			return true;
		}
		else
		{
			mate_timer++;
			return false;
		}
	}
	else
	{
		if (Fish::update()) { return true; }
		else{ return false; }
	}
}

bool Tuna::start_mating(Tuna* fish_mate){

		cout << "F" << this->get_id() << ": I found my mate!" << endl;
		state = 'm';
		return true;
	}

void Tuna::do_mating()
{
	state = 'm';
}

void Tuna::save(ofstream& file)
{
	Fish::save(file);
	file << mate_timer << endl;
	file << mate_initiator << endl;
}