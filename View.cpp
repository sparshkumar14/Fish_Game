#include <iostream>
#include "View.h"

using namespace std;

View::View()
{
  size = 11;
  scale = 2;
  origin = CartPoint();
//  clear();
}


void View::draw()
{
	
	for (int j = size - 1; j >= -1; j--)
	{
		for (int i = -1; i <= size - 1; i++)
		{
		if (i == -1 && j % 2 == 0)
			{
			cout << j * 2;
			if (j / 5 == 0)
			{
				cout << " ";
			}

			}
		else if (i == -1 && j % 2 != 0)
			{
				cout << "  ";
			}
			else if (j == -1 && i % 2 == 0)
			{
				cout << i * 2;
				if (i / 5 == 0)
				{
					cout << " ";
				}
				cout << "  ";
			}

			if (i >= 0 && j >= 0)
				cout << grid[i][j][0] << grid[i][j][1];

		}
		cout << endl;
	}
	
	
	
	/*	
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			cout << grid[x][y][0];
			cout << grid[x][y][1];
		}
		cout << endl;
	}
	*/
	}

void View::plot(GameObject* ptr)
{
	int x;
	int y;
	bool valid = get_subscripts(x, y, ptr->get_location());

	if (valid && grid[x][y][0] == '.')
		{
			ptr->drawself(grid[x][y]);
		}
	else if (valid)
		{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		}
	
}

bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
	CartVector CV = (location - this->origin) / this->scale;
	ix = CV.x;
	iy = CV.y;
	if (ix >= 0 || ix <= this->size-1 || iy >= 0 || iy <= this->size-1)
	{
		return true;
	}
	else
	{
		cout << "An object is outside the display" << endl;
		return false;
	}
}

void View::clear()
{
	for (int y = 0; y < view_maxsize; y++)
	{
		for (int x = 0; x < view_maxsize; x++)
		{
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}
}