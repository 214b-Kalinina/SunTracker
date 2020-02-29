#include <math.h>

#include "Cloud.h"

//	width - metre
//	y - metre
//	speed - metre / minutes
//	x - metre

Cloud::Cloud() {
	this->width = 0;
	this->y = 0;
	this->speed = 0;
	this->x = 0;
}



Cloud::Cloud(double width, double y, double speed, double x) {
	this->width = width;
	this->y = y;
	this->speed = speed;
	this->x = x;
}


double Cloud::getWidth() {
	return this->width;
}


double Cloud::getX() {
	return this->x;
}


double Cloud::getY() {
	return this->y;
}


double Cloud::getSpeed() {
	return this->speed;
}


void Cloud::toModelMinute() {
	this->x += this->speed;
}


