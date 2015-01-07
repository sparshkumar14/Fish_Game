#include <iostream>

#include "CartVector.h"
#include "CartPoint.h"
#include "CoralReef.h"
#include "GameObject.h"
#include "Cave.h"
#include "Fish.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"
#include "Tuna.h"
#include "InputHandling.h"
#include "Sharknado.h"

using namespace std;

int main()
{
	Model model;
	char input;
	model.show_status();
	View view;
//	cout << model.get_highest_fish_id_number() << endl;
	do
	{
		{
			model.display(view);

			try{
				cout << "Enter command: ";
				cin >> input;
				switch (input){
				case 's':{
					do_swim_command(model);
					break;
				}
				case 'e':{
					do_eat_command(model);
					break;
				}
				case 'f':{
					do_float_command(model);
					break;
				}
				case 'z':{
					do_zoom_command(model);
					break;
				}
				case 'g':{
					do_go_command(model);
					break;
				}
				case 'r':{
					do_run_command(model);
					break;
				}
				case 'a':{
					do_attack_command(model);
					break;
				}
				case 'n':{
					do_new_command(model);
					break;
				}
				case 'S':{
					do_save_command(model);
					break;
				}

				default:
					throw InvalidInput("Invalid Game Command");
				}
			}
			catch (InvalidInput& except) {
				cout << "Invalid input - " << except.msg_ptr << endl;
			}
		}

			} while (input != 'q');

			cout << "Bye Bye!" << endl;

			return 0;
		}