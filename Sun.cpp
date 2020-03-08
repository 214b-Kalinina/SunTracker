#include "Sun.h"

//	radius - metre
//	angle - radian

Sun::Sun() {
	this->angle = 0;
}


double Sun::getAngle() {
	return this->angle;
}


// Sun goes 12 hours
void Sun::toModelMinute() {
	this->angle += 3.14159 / (12 * 60); // 180 angles (PI) per 12*60 minutes
}