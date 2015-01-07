//
//  CartVector.cpp
//  PA3_UnderTheSea
//

#include "CartVector.h"
#include <iostream>
#include <ostream>

using namespace std;


CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

CartVector::CartVector(double in_x, double in_y)
{
	this->x = in_x;
	this->y = in_y;
	//added this->
}


CartVector operator*(const CartVector& v1, const double d)
{
	CartVector vector;
	vector.x = v1.x * d;
	vector.y = v1.y * d;
	return vector;
}

CartVector operator/(const CartVector& v1, const double d)
{
	CartVector vector;
	vector.x = v1.x / d;
	vector.y = v1.y / d;
	return vector;
}


ostream& operator<<(ostream& out, const CartVector& vector)
{
	out << "<" << vector.x << ", " << vector.y << ">" << endl;
	return out;
}


