#include "Sun.h"

#include <corecrt_math_defines.h>


Sun::Sun() {
	this->radius = 0;
	this->angle = 0;
}



//	radius - metre
//	angle - radian
Sun::Sun(double radius) {
	this->radius = radius;
	this->angle = 0;
}



double Sun::getAngle() {
	return this->angle;
}


double Sun::getRadius() {
	return this->radius;
}


// Sun goes 12 hours
void Sun::toModelMinute() {
	this->angle += M_PI / (12 * 60); // 180 angles (PI) per 12*60 minutes
}