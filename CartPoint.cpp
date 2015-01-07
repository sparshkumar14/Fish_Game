
#include <iostream>
#include "CartPoint.h"
#include <math.h>
#include <ostream>
#include "CartVector.h"

using namespace std;



CartPoint::CartPoint()
	{
		x = 0;
		y = 0;
	}

CartPoint::CartPoint(double in_x, double in_y)
	{
		this->x = in_x;
		this->y = in_y;
	}

double CartPoint::get_x()
	{
		return x;
	}

double CartPoint::get_y()
	{
		return y;
	}

double cart_distance(CartPoint p1, CartPoint p2)
{
	double distance;
	double difference_x;
	double difference_y;
	double magnitude;

	difference_x = p2.get_x() - p1.get_x();
	difference_y = p2.get_y() - p1.get_y();
	magnitude = pow(difference_x, 2) + pow(difference_y, 2);
	distance = sqrt(magnitude);

	return distance;
}


CartPoint operator+(const CartPoint& p1, const CartVector& v1)
{
	CartPoint point;
	point.x = v1.x + p1.x;
	point.y = v1.y + p1.y;
	return point;
}


CartVector operator-(const CartPoint& p1, const CartPoint& p2)
{
	CartVector vector;
	vector.x = p1.x - p2.x;
	vector.y = p1.y - p2.y;
	return vector;

}

ostream& operator<<(ostream& out, const CartPoint& point)
{
	out << "(" << point.x << ", " << point.y << ")";
	return out;
}

bool operator==(const CartPoint &p1, const CartPoint &p2)
{
  return (p1.x == p2.x && p1.y == p2.y);
    }
