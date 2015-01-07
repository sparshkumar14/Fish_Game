#ifndef __CartVector__
#define __CartVector__

#include <iostream>

using namespace std;

class CartVector
{
public:
	double x;
	double y;
    
	CartVector();
	CartVector(double in_x, double in_y);
	double get_x();
	double get_y();

};
ostream& operator<<(ostream& out, const CartVector& point);
CartVector operator*(const CartVector& v1, const double d);
CartVector operator/(const CartVector& v1, const double d);
#endif 
