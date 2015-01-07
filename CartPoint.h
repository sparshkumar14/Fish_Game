//
//  CartPoint.h
//  PA3_UnderTheSea
//

#ifndef __CartPoint__
#define __CartPoint__

#include <iostream>
#include <ostream>
#include "CartVector.h"
using namespace std;

class CartPoint
{
public:
	double x;
	double y;
	CartPoint();
	CartPoint(double in_x, double in_y);
	double get_x();
	double get_y();

};

double cart_distance(CartPoint p1, CartPoint p2);
CartPoint operator+(const CartPoint& p1, const CartVector& v1);
CartVector operator-(const CartPoint& p1, const CartPoint& p2);
ostream& operator<<(ostream& out, const CartPoint& point);
bool operator==(const CartPoint& p1, const CartPoint& p2);

#endif /* defined(__CartPoint__) */

